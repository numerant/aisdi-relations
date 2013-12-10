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

ImportStats IOInterface::importMail(MailParameters *parameters)
{
    Email *tempEmail;       //pamiętać o delete!
    ImportStats stats;


    if (parameters->isDirectory)
    {
        boost::filesystem::path currentDir(parameters->path);                           // stworzenie boostowej zmiennej określającej ścieżkę

        if (parameters->recursiveImport)
            boost::filesystem::recursive_directory_iterator iter(currentDir), end;      // boostowy iterator przechodzący katalog i podkatalogi
        else
            boost::filesystem::directory_iterator iter(currentDir), end;                // ten pomija podkatalogi

        for (; iter != end; ++iter)                                                     // przejechanie iteratorem po katalogu
            if (iter->path().extension() == ".eml")
            {
                try tempEmail = emlParser( iter->path() );
                catch ( IOException error )                                             // mail nie jest poprawny składniowo
                {                                                                       // właściwie powinno być EmlSyntaxIncorrect, ale póki co niezależnie od rzuconego przez parser wyjątku jedynie inkrementujemy failCount
                    stats->failCount++;
                    break;
                }

                try database->addEmail(*tempEmail)
                catch ( /* mail istnieje już w bazie */ )
                {
                    stats->existingCount++;
                    break;
                }
            }
            delete tempEmail;   //break przerwie chyba tylko blok if, więc może być tutaj?
    }
    else
    {
        try tempEmail = emlParser(parameters->path);
        catch ( IOException error )
        {
            stats->failCount++;
            break;                      //wyskoczenie z bloku else
        }

        try database->addEmail(*tempEmail)
        catch ( /* mail istnieje już w bazie */ )
        {
            stats->existingCount++;
            delete tempEmail;
            break;
        }
        stats->successCount++;
        delete tempEmail;
    }

    return stats;
}

Email* IOInterface::emlParser (string path)
{
	fstream plik;
	plik.open(paht, std::ios::in);
	if( plik.good() == true )
	{
		Email mail;
		Usember usemberFrom, usemberTo;
		string wiersz, fromRN, fromLOGIN, fromDOMAIN, toRN, toLOGIN, toDOMAIN, subject, MID, date, content;
		regex regFrom("From:\s+(\"(.+)\")?\s*<(.+)@(.+)>");
		regex regTo("To:\s+(\"(.+)\")?\s*<(.+)@(.+)>");
		regex regSubject("Subject:\s+(.*)");
		regex regMID("Message-ID:\s+<(.+)>");
		regex regDate("Date:\s+(\u\l{2},\s+\d{1,2}\s+\u\l+\s+\d{4}\s+\d{2}:\d{2}:\d{2}\s+\+\d{4})");
		
		
		
		
		do
		{
			getline(plik, wiersz);
		}
		while ( trim(wiersz).size() == 0 ) // pomija przypadkowe puste linie na początku pliku
		
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
		else
		{
			throw UnableToOpenFile();
		}
		
		// wczytanie TO
		wynik.clear();
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
		else
		{
			throw UnableToOpenFile();
		}
		
		// wczytanie SUBJECT
		wynik.clear();
		if ( regex_search( wiersz, wynik, regSubject) )
		{
			subject = wynik[0];
		}
		else
		{
			throw UnableToOpenFile();
		}
		
		// wczytanie MID
		wynik.clear();
		if ( regex_search( wiersz, wynik, regMID) )
		{
			MID = wynik[0];
		}
		else
		{
			throw UnableToOpenFile();
		}
		
		// wczytanie DATE
		wynik.clear();
		if ( regex_search( wiersz, wynik, regDate) )
		{
			date = wynik[0];
		}
		else
		{
			throw UnableToOpenFile();
		}
		
		// wczytanie treści
		while (wiersz.size() != 0)
			getline(plik, wiersz); // przejście do momentu pustej linii
			
		while (plik != EOT) // wczytanie tego co zostało jako treść
		{
			plik >> content;
		}
		
		plik.close();
		
		// ustawienie atrybutów maila
		mail = new Email();
		

		usemberFrom = new Usember(fromLOGIN, fromDOMAIN, fromRN);
		usemberTo = new Usember(toLOGIN, toDOMAIN, toRN);
		
		usemberFrom = database.addUsember( usemberFrom );
		usemberTo = database.addUsember( usemberTo );
		
		mail.setFrom( usemberFrom );
		mail.setTo( usemberTo );
		mail.setSubject( subject );
		mail.setContent( content );
		mail.setDate( new Date(date) );
		
		return mail;
	}
	else // nie można otworzyć pliku
	{
		throw UnableToOpenFile();
	}
}
