// IOInterface class
// This class is responsible for all file operations, like database import / export, e-mail import etc.

// Klasa IOInterface
// Odpowiedzialna za operacje na plikach, takie jak wczytywanie maili do bazy danych, import / eksport bazy, zapisywanie raportów do pliku

#include "IOInterface.h"

using namespace std;

IOInterface::ImportStats::ImportStats()
{
    successCount = 0;
    failCount = 0;
    existingCount = 0;
}

IOInterface::ImportStats IOInterface::importMail(MailParameters *parameters)
{
    ImportStats stats;

    if (parameters->isDirectory)
    {
        if (parameters->recursiveImport)
            for (boost::filesystem::recursive_directory_iterator iter(parameters->path), end; iter != end; ++iter)      // przejechanie iteratorem po katalogu
                importSingleMail( iter->path(), stats );                                                                // import do bazy maila, na który wskazuje iterator
        else
            for (boost::filesystem::directory_iterator iter(parameters->path), end; iter != end; ++iter)                // jak wyżej, tylko bez rekursji
                importSingleMail( iter->path(), stats );
    }
    else
        importSingleMail(parameters->path, stats);

    return stats;
}

void IOInterface::importSingleMail(boost::filesystem::path path, ImportStats &stats)
{
    Email *tempEmail;
    if (path.extension() == ".eml")
    {
        try
        {
            tempEmail = emlParser( path.c_str() );
            database->addEmail(tempEmail);
            stats.successCount++;
        }
        catch ( IOException error )                                             // mail nie jest poprawny składniowo
        {
            stats.failCount++;
        }
        catch ( ... /* tu ma być błąd bazy danych! */ )
        {
            stats.existingCount++;
        }
    }
    delete tempEmail;
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
        string wiersz, fromRN, fromLOGIN, fromDOMAIN, toRN, toLOGIN, toDOMAIN, subject, MID, date, content;
        regex regFrom("From:\s+(\"(.+)\")?\s*<(.+)@(.+)>");
        regex regTo("To:\s+(\"(.+)\")?\s*<(.+)@(.+)>");
        regex regSubject("Subject:\s+(.*)");
        regex regMID("Message-ID:\s+<(.+)>");
        regex regDate("Date:\s+(\\u\l{2},\s+\d{1,2}\s+\\u\l+\s+\d{4}\s+\d{2}:\d{2}:\d{2}\s+\+\d{4})");

        do
            getline(plik, wiersz);
        while ( (wiersz).size() == 0 ); // pomija przypadkowe puste linie na początku pliku

        // wczytanie FROM
        smatch wynik;
        if ( regex_search( wiersz, wynik, regFrom) )
        {
            if (wynik.size() == 2) // odczytano tylko goły adres
            {
                fromLOGIN = wynik[0];
                fromDOMAIN = wynik[1];
            }
            else
            {
                fromRN = wynik[1];
                fromLOGIN = wynik[2];
                fromDOMAIN = wynik[3];
            }
        }
        else throw EmlSyntaxIncorrect();


        // wczytanie TO
        getline(plik, wiersz);
        if ( regex_search( wiersz, wynik, regTo) )
        {
            if (wynik.size() == 2) // odczytano tylko goły adres
            {
                toLOGIN = wynik[0];
                toDOMAIN = wynik[1];
            }
            else
            {
                toRN = wynik[1];
                toLOGIN = wynik[2];
                toDOMAIN = wynik[3];
            }
        }
        else throw EmlSyntaxIncorrect();

        // wczytanie SUBJECT
        getline(plik, wiersz);
        if ( regex_search( wiersz, wynik, regSubject) )
        {
            subject = wynik[0];
        }
        else throw EmlSyntaxIncorrect();

        // wczytanie MID
        getline(plik, wiersz);
        if ( regex_search( wiersz, wynik, regMID) )
        {
            MID = wynik[0];
        }
        else throw EmlSyntaxIncorrect();

        // wczytanie DATE
        getline(plik, wiersz);
        if ( regex_search( wiersz, wynik, regDate) )
        {
            date = wynik[0];
        }
        else throw EmlSyntaxIncorrect();

        // wczytanie treści
        while (wiersz.size() != 0)
            getline(plik, wiersz); // przejście do momentu pustej linii

        while (plik.eof() != EOF) // wczytanie tego co zostało jako treść
            plik >> content;

        plik.close();

        // ustawienie atrybutów maila
        mail = new Email();

        usemberFrom = new Usember(fromLOGIN, fromDOMAIN, fromRN);
        usemberTo = new Usember(toLOGIN, toDOMAIN, toRN);

//        usemberFrom = database.addUsember( usemberFrom );
//        usemberTo = database.addUsember( usemberTo );

        Date* newDate = new Date(date);
        mail->setFrom( usemberFrom );
        mail->setTo( usemberTo );
        mail->setSubject( subject );
        mail->setContent( content );
        mail->setDate(newDate);

        return mail;
    }
    else throw UnableToOpenFile();
}
