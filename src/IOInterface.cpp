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
