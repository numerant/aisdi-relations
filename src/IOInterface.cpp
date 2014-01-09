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

void IOInterface::importMail(MailParameters *parameters)
{
    if (parameters->isDirectory)
    {
        if (parameters->recursiveImport)
            for (boost::filesystem::recursive_directory_iterator iter(parameters->path), end; iter != end; ++iter)      // przejechanie iteratorem po katalogu
                importSingleMail( iter->path(), stats);                                                                // import do bazy maila, na który wskazuje iterator
        else
            for (boost::filesystem::directory_iterator iter(parameters->path), end; iter != end; ++iter)                // jak wyżej, tylko bez rekursji
                importSingleMail( iter->path(), stats );
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
                stats.successCount++;
            else
                stats.existingCount++;
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
        boost::regex regSubject("Subject:\\s+(.*)");
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

        usemberFrom = new Usember(fromLOGIN, fromDOMAIN, fromRN);
        usemberTo = new Usember(toLOGIN, toDOMAIN, toRN);

        database->addUsember( usemberFrom );
        database->addUsember( usemberTo );

        Date* newDate = new Date(date);     //wyciek pamięci!
        mail->setFrom( usemberFrom );
        mail->setTo( usemberTo );
        mail->setSubject( subject );
        mail->setContent( content );
        mail->setDate(newDate);
        mail->setID(MID);
		mail->setInReplyTo(IRT);

        return mail;
    }
    else throw UnableToOpenFile();
}

void IOInterface::setDatabasePointer (Database * db)
{
    this->database = db;
}

Database* IOInterface::importDatabase(string filePath, DbParameters *parameters)
{
    delete database;            // potrzebny prompt!
    ifstream ifs(filePath);     // dodać exception
    boost::archive::text_iarchive ia(ifs);
    ia >> database;

    return database;
}

void IOInterface::exportDatabase(string filePath, DbParameters *parameters)
{
    ofstream ofs(filePath);
    boost::archive::text_oarchive oa(ofs);
    oa << database;
}

void IOInterface::exportDatabaseToTxt (string directoryPath)
{
    string filePath;
    stringstream record;              // linia zawierająca pola pojedynczego rekordu bazy, oddzielone tabulatorami

        //wektor maili
    filePath = directoryPath + "/emails.txt";             // sprawdzić, czy / jest potrzebne
    Email* tempEmail;
    for(int i=0; ; i++)
    {
        tempEmail = database->getEmail(i);
        if (tempEmail == nullptr) break;                // null oznacza, że maile w wektorze się skończyły

        record.clear();
        record << tempEmail->getID() << "\t";
        record << tempEmail->getFrom()->getAddress() << "\t";
        record << tempEmail->getTo()->getAddress() << "\t";
        record << tempEmail->getReplyTo()->getAddress() << "\t";
        record << tempEmail->getInReplyTo() << "\t";
            // dopisać forwards
        record << tempEmail->getDate().getFullDate() << "\t";       // getDate nie zwraca wskażnika (?)
        record << tempEmail->getSubject() << "\t";

        string emailContent(tempEmail->getContent() );
        replace(emailContent.begin(), emailContent.end(), '\n', '~');
        record << emailContent << "\n";
    }

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
