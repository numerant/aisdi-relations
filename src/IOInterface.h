#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include <boost/regex.hpp>
#include "boost/filesystem.hpp"         // do wczytywania plików z katalogu - także rekursywnie
#include "boost/algorithm/string.hpp"   // do zaawansowanych operacji na stringach
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "Database.h"
#include "Serialization.h"
#include "Email.h"
#include "Parameters.h"
#include "Report.h"
#include "Exception/IOException.h"

using namespace std;
using namespace boost;

// IOInterface class
// This class is responsible for all file operations, like database import / export, e-mail import etc.

// Klasa IOInterface
// Odpowiedzialna za operacje na plikach, takie jak wczytywanie maili do bazy danych, import / eksport bazy, zapisywanie raportów do pliku

class IOInterface
{
public:
    // Classes:
    struct ImportStats                                                          // struktura zawierająca statystyki importu - ile udało się wczytać, ile nie itp.
    {
        ImportStats();
        void clearStats();
        unsigned int successCount;                                              // niech ktoś mądry się wypowie czy tak jest OK, czy lepiej bawić się w set/get
        unsigned int failCount;
        unsigned int existingCount;                                             // maile, które już istniały w bazie
    };

    // Methods:
    IOInterface();                                                              // trzeba zadbać o wskaźnik na bazę danych
    ~IOInterface();

    void importMail(MailParameters *parameters);
    ImportStats getImportStats();
    void clearImportStats();

    void exportDatabase (string filePath, DbParameters *parameters);            // opis klas MailParameters i DbParameters jest w Param.h
    Database* importDatabase (string filePath, DbParameters *parameters);
    void exportReport (string path, Report report);

    void setDatabasePointer (Database * db);
    string strSequenceReplace(const string& searched, const string& replaced, string subject);

private:
    // Fields:
    Database *database;                         // baza tworzona w momencie uruchomienia programu
    ImportStats stats;
    //vector<char> *binary_file;                // trzyma zserializowaną bazę danych w formie binarnej - chyba lepiej tworzyć lokalnie, wewnątrz metody

    // Methods:
    void importSingleMail(boost::filesystem::path path, ImportStats &stats);
    Email* emlParser (string path);             //sprawdza poprawność maili
    void encryptFile (string password);
    void decryptFile (string password);
};
