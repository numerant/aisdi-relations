// IOInterface class
// This class is responsible for all file operations, like database import / export, e-mail import etc.

// Klasa IOInterface
// Odpowiedzialna za operacje na plikach, takie jak wczytywanie maili do bazy danych, import / eksport bazy, zapisywanie raportów do pliku

#include "IOInterface.h"

using namespace std;
using namespace boost;

IOInterface::IOInterface()
{

}

IOInterface::~IOInterface()
{

}

IOInterface::ImportStats::ImportStats()
{
    clearStats();
}

void IOInterface::ImportStats::clearStats()
{
    successCount = 0;
    failCount = 0;
    existingCount = 0;
}

void IOInterface::importMail(MailParameters *parameters)        // dodać wyjątki
{
    if (parameters->isDirectory)
    {
        try
        {
            if (parameters->recursiveImport)
                for (boost::filesystem::recursive_directory_iterator iter(parameters->path), end; iter != end; ++iter)      // przejechanie iteratorem po katalogu
                    importSingleMail( iter->path(), stats);                                                                // import do bazy maila, na który wskazuje iterator
            else
                for (boost::filesystem::directory_iterator iter(parameters->path), end; iter != end; ++iter)                // jak wyżej, tylko bez rekursji
                    importSingleMail( iter->path(), stats );
        }
        catch(boost::filesystem::filesystem_error exception)
        {
            throw UnableToOpenDirectory();
        }
    }
    else
        importSingleMail(parameters->path, stats);
}

void IOInterface::importSingleMail(boost::filesystem::path path, ImportStats &stats)
{
    Email *tempEmail;
    if (path.extension() == ".eml")
    {
        try
        {
            tempEmail = emlParser( path.c_str() );
            if(database->addEmail(tempEmail))
            {
                stats.successCount++;
                Usember * usemberFrom = tempEmail->getFrom();
                Usember * usemberTo = tempEmail->getTo();
                usemberFrom->addEmailSent(tempEmail);
                usemberTo->addEmailReceived(tempEmail);
            }
            else
            {
                stats.existingCount++;
                delete tempEmail;
            }
        }
        catch ( IOException error )                                             // mail nie jest poprawny składniowo
        {
            stats.failCount++;
        }
    }
    //delete tempEmail;
}

IOInterface::ImportStats IOInterface::getImportStats()
{
    return stats;
}

void IOInterface::clearImportStats()
{
    stats.clearStats();
}

Email* IOInterface::emlParser (string path)
{
    fstream plik;
    plik.open(path.c_str(), ios::in);
    if( plik.good() == true )
    {
        Email* mail;
        Usember* usemberFrom;
        Usember* usemberTo;
        string wiersz, fromRN, fromLOGIN, fromDOMAIN, toRN, toLOGIN, toDOMAIN, subject, MID, IRT, date, content;
        boost::regex regFrom("From:\\s+(\"(.+)\")?\\s*<(.+)@(.+)>");
        boost::regex regTo("To:\\s+(\"(.+)\")?\\s*<(.+)@(.+)>");
        boost::regex regSubject("Subject:\\s*(.*)");
        boost::regex regMID("Message-ID:\\s+<(.+)>");
		boost::regex regIRT("In-Reply-To:\\s+<(.+)>");
        boost::regex regDate("Date:\\s+(\\u\\l{2},\\s+\\d{1,2}\\s+\\u\\l+\\s+\\d{4}\\s+\\d{2}:\\d{2}:\\d{2}\\s+\\+\\d{4})");
		boost::smatch wynik;

        // wczytanie FROM
        do
            getline(plik, wiersz);
        while (( regex_search( wiersz, wynik, regFrom) == 0 )&&( !plik.eof() ));

		if ( plik.eof() )
			throw EmlSyntaxIncorrect();
		else
		{
			fromRN = wynik[2];
			fromLOGIN = wynik[3];
			fromDOMAIN = wynik[4];
		}

        // wczytanie TO
        do
            getline(plik, wiersz);
        while (( regex_search( wiersz, wynik, regTo) == 0 )&&( !plik.eof() ));
        if ( plik.eof() )
			throw EmlSyntaxIncorrect();
		else
        {
            toRN = wynik[2];
            toLOGIN = wynik[3];
            toDOMAIN = wynik[4];
        }

        // wczytanie SUBJECT
        do
            getline(plik, wiersz);
        while (( regex_search( wiersz, wynik, regSubject) == 0 )&&( !plik.eof() ));
        if ( plik.eof() )
			throw EmlSyntaxIncorrect();
		else
			subject = wynik[1];

        // wczytanie MID
        do
            getline(plik, wiersz);
        while (( regex_search( wiersz, wynik, regMID) == 0 )&&( !plik.eof() ));
        if ( plik.eof() )
			throw EmlSyntaxIncorrect();
		else
            MID = wynik[1];

		// wczytanie InReplyTo
		do
            getline(plik, wiersz);
        while ( wiersz.size() == 0 ); // pomija przypadkowe puste linie
		if ( regex_search( wiersz, wynik, regIRT) )
            IRT = wynik[1];

        // wczytanie DATE
        while (( regex_search( wiersz, wynik, regDate) == 0 )&&( !plik.eof() ))
			getline(plik, wiersz);

		if ( plik.eof() )
			throw EmlSyntaxIncorrect();
		else
            date = wynik[1];

        // wczytanie treści
        // #### rozwiązanie tymczasowe - przejście 5 lini
        getline(plik, wiersz); // przejście do treści
        getline(plik, wiersz);
        getline(plik, wiersz);
        getline(plik, wiersz);
        getline(plik, wiersz);
        // #### rozwiązanie tymczasowe

        while ( !plik.eof() ) // wczytanie tego co zostało jako treść
        {
            getline (plik, wiersz);
            content+=wiersz;
            content+= "\n";
        }

       plik.close();

        // ustawienie atrybutów maila
        mail = new Email();

        usemberFrom = new Usember(fromLOGIN, fromDOMAIN, fromRN);   //Jeżeli baza nie przyjęłą, to trzeba zwolnić pamięć
        if (! database->addUsember( usemberFrom ))
        {
            delete usemberFrom;
            usemberFrom = database->getUsember(database->findUsember(fromLOGIN+"@"+fromDOMAIN));
        }

        usemberTo = new Usember(toLOGIN, toDOMAIN, toRN);
        if (! database->addUsember( usemberTo ))
        {
            delete usemberTo;
            usemberTo = database->getUsember(database->findUsember(toLOGIN+"@"+toDOMAIN));
        }

        Date* newDate = new Date(date);     //wyciek pamięci!
        mail->setFrom( usemberFrom );
        mail->setTo( usemberTo );
        mail->setSubject( subject );
        mail->setContent( content );
        mail->setDate(newDate);
        mail->setID(MID);
        mail->setInReplyTo(IRT);

		if ( (subject.compare(0, 4, "Fwd:") == 0 )
			|| (subject.compare(0, 4, "fwd:") == 0 )
			|| (subject.compare(0, 4, "FWD:") == 0 )
			)
			mail->setIsForwarded(true);

        return mail;
    }
    else throw UnableToOpenFile();
}

void IOInterface::setDatabasePointer (Database * db)
{
    this->database = db;
}

void IOInterface::xorStream(istream &inputStream, ostream &outputStream, string key)
{
	unsigned int keyPosition = 0;
	int xorByte;

	while( (xorByte = inputStream.get()) != EOF)
	{
		outputStream.put(xorByte ^ key[keyPosition]);       // XOR aktualnie wczytanego bajtu z bajtem pod aktualną pozycją klucza

		keyPosition++;
		if(keyPosition == key.length())
			keyPosition = 0;                                //zerowanie pozycji klucza po osiągnięciu jego końca
	}
}

bool IOInterface::isImportedFileProtected (string filePath)
{
    char isPasswordProtected;

    inputFile.open(filePath, ios_base::binary);
    if (inputFile.fail())
    {
        inputFile.close();
        throw UnableToOpenFile();
    }

    if (inputFile.get() != 48)
    {
        inputFile.close();
        throw InvalidFile();
    }

    isPasswordProtected = inputFile.get();
    if (isPasswordProtected == 0)
        return false;
    else if (isPasswordProtected == 1)
        return true;
    else
    {
        inputFile.close();
        throw InvalidFile();
    }
    return 0;
}

Database* IOInterface::importDatabase(DbParameters *parameters)
{
    using namespace boost::iostreams;

    if (inputFile.fail())
        throw UnableToOpenFile();

    stringstream compressedData;
    stringstream decompressedData;
    filtering_streambuf<input> decompressedStream;
    decompressedStream.push(zlib_decompressor());

    if (parameters->isPasswordProtected)
    {
        xorStream(inputFile, compressedData, parameters->password);
        decompressedStream.push(compressedData);
    }
    else
        decompressedStream.push(inputFile);
    try
    {
        copy(decompressedStream, decompressedData);

        delete database;
        boost::archive::text_iarchive inputArchive(decompressedData);
        inputArchive >> database;
    }
    catch(boost::iostreams::zlib_error exception)
    {
        throw InvalidPassword();
    }

    inputFile.close();
    return database;
}

void IOInterface::exportDatabase(string filePath, DbParameters *parameters)
{
    using namespace boost::iostreams;

    stringstream dataToCompress;
    ofstream outputFile(filePath);

    if (outputFile.fail())
        throw UnableToOpenFile();
    outputFile.put((char)48);       // oznaczenie pliku ARB

    boost::archive::text_oarchive outputArchive(dataToCompress);
    outputArchive << database;

    filtering_streambuf<input> compressedStream;
    compressedStream.push(zlib_compressor(zlib::best_compression));
    compressedStream.push(dataToCompress);

    if (parameters->isPasswordProtected)
    {
        outputFile.put((char)1);
        stringstream dataToEncrypt;
        copy(compressedStream, dataToEncrypt);

        xorStream(dataToEncrypt, outputFile, parameters->password);
    }
    else
    {
        outputFile.put((char)0);
        copy(compressedStream, outputFile);
    }
}

void IOInterface::exportDatabaseToTxt (string directoryPath)
{
    string filePath;
    stringstream record;              // linia zawierająca pola pojedynczego rekordu bazy, oddzielone tabulatorami
    ofstream file;

        //wektor maili
    filePath = directoryPath + "/emails.txt";             // sprawdzić, czy / jest potrzebne
    file.open(filePath);

    Email* tempEmail;
    for(int i=0; ; i++)
    {
        tempEmail = database->getEmail(i);
        if (tempEmail == nullptr) break;                // null oznacza, że maile w wektorze się skończyły

        record.clear();
        record << tempEmail->getID() << "\t";
        record << tempEmail->getFrom()->getAddress() << "\t";
        record << tempEmail->getTo()->getAddress() << "\t";         // TODO JM: dodać obsługę replyTo
        //record << tempEmail->getReplyTo()->getAddress() << "\t";  //replyTo chyba nie działa (?)
        record << tempEmail->getInReplyTo() << "\t";              //na razie puste

        record << tempEmail->getDate().getFullDate() << "\t";       // getDate nie zwraca wskażnika (?)
        record << tempEmail->getSubject() << "\t";

        string emailContent(tempEmail->getContent() );
        replace(emailContent.begin(), emailContent.end(), '\n', '~');
        record << emailContent << "\n";

        file << record.rdbuf();
    }
    file.close();

        //wektor usemberów
    filePath = directoryPath + "/usembers.txt";
    file.open(filePath);

    Usember* tempUsember;
    for(int i=0; ; i++)
    {
        tempUsember = database->getUsember(i);
        if (tempUsember == nullptr) break;

        record.clear();
        record << tempUsember->getAddress() << "\t";
        record << tempUsember->getRealName() << "\t";
        //record << tempUsember->getGroup()->getID();       // TODO JM: odkomentować gdy Patryk poprawi setID
        record << "\n";
        file << record.rdbuf();
    }
    file.close();

            //wektor grup
    filePath = directoryPath + "/groups.txt";             // sprawdzić, czy / jest potrzebne
    file.open(filePath);

    Group* tempGroup;
    for(int i=0; ; i++)
    {
        tempGroup = database->getGroup(i);
        if (tempGroup == nullptr) break;

        record.clear();

        record << tempGroup->getID() << "\t";
        record << tempGroup->getLeader()->getRealName() << "\t";
        record << "\n";
        file << record.rdbuf();
    }
    file.close();
}

void IOInterface::exportDatabaseReport (string path, Statistics* dbStatistics)
{
    ofstream outputFile(path);
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    outputFile << "\tStatystyki bazy danych:\n\n";
    outputFile << "Liczba e-maili:\t" << dbStatistics->getEmails() << "\n";
    outputFile << "Liczba usemberów:\t" << dbStatistics->getUsembers() << "\n";
    outputFile << "Liczba grup:\t" << dbStatistics->getGroups() << "\n\n";
    outputFile << "Średnio e-maili na miesiąc:\t" << dbStatistics->getEmailsPerMonth() << "\n";
    outputFile << "Średnio e-maili na dzień:\t" << dbStatistics->getEmailsPerDay() << "\n";
    outputFile << "Średnio e-maili na usembera:\t" << dbStatistics->getEmailsPerUser() << "\n\n";
    outputFile << "Średnia długość maila:\t" << dbStatistics->getAverageEmailLength() << "\n";
    outputFile << "Najwięcej maili w miesiącu:\t" << dbStatistics->getMaxEmailsInMonth() << "\n";
    outputFile << "Liczba forwardów:\t" << dbStatistics->getForwards() << "\n";
    outputFile << "Liczba odpowiedzi:\t" << dbStatistics->getReplies() << "\n\n";
    outputFile << "Najwcześniejszy mail:\t" << dbStatistics->getEarliest()->getFullDate() << "\n";        // tu i w następnym przydałaby się funkcja wypisująca datę w uproszczonej formie
    outputFile << "Najpóźniejszy mail:\t" << dbStatistics->getLatest()->getFullDate() << "\n";
    outputFile << "Okres trwania korespondencji:\t" << dbStatistics->getDuration() << "\n\n";

    outputFile << "Liczba maili na każdy miesiąc:\n";

    for (int i=0; i<12; i++)
        outputFile << months[i] << ":\t" << dbStatistics->getEmailsCountInMonth(i+1) << "\n";

    outputFile.close();
}

string IOInterface::strSequenceReplace(const string& searched, const string& replaced, string subject)
{
    string buffer;

    int sealeng = searched.length();
    int strleng = subject.length();

    if (sealeng==0)
        return subject;//no change

    for(int i=0, j=0; i<strleng; j=0 )
    {
        while (i+j<strleng && j<sealeng && subject[i+j]==searched[j])
            j++;
        if (j==sealeng)//found 'search'
        {
            buffer.append(replaced);
            i+=sealeng;
        }
        else
        {
            buffer.append( &subject[i++], 1);
        }
    }
    subject = buffer;
    return subject;
}
