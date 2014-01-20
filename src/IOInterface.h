#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <algorithm>                            // do zamiany znaków nowej linii w treści maila
#include <boost/regex.hpp>
#include "boost/filesystem.hpp"                 // do wczytywania plików z katalogu - także rekursywnie
#include "boost/algorithm/string.hpp"           // do zaawansowanych operacji na stringach
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/iostreams/filtering_streambuf.hpp"
#include "boost/iostreams/copy.hpp"
#include "boost/iostreams/filter/zlib.hpp"
#include "Database.h"
#include "Serialization.h"
#include "Email.h"
#include "Parameters.h"
#include "Statistics.h"
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

    void exportDatabase (string filePath, DbParameters *parameters);                    // opis klas MailParameters i DbParameters jest w Param.h
    Database* importDatabase (string filePath, DbParameters *parameters);
    void exportDatabaseReport (string path, Statistics* dbStatistics);
    void exportDatabaseToTxt (string directoryPath);                                    // w podanym katalogu tworzy pliki tekstowe z rekordami bazy danych, przystosowane do importu do np. Accessa

    void setDatabasePointer (Database * db);
    string strSequenceReplace(const string& searched, const string& replaced, string subject);

private:
    // Fields:
    Database *database;                         // baza tworzona w momencie uruchomienia programu
    ImportStats stats;
    ifstream inputFile;
    //vector<char> *binary_file;                // trzyma zserializowaną bazę danych w formie binarnej - chyba lepiej tworzyć lokalnie, wewnątrz metody

    // Methods:
    void xorStream(stringstream &inputStream, stringstream &outputStream, string key);  // szyfruje/deszyfruje strumień algorytmem XOR
    void importSingleMail(boost::filesystem::path path, ImportStats &stats);
    Email* emlParser (string path);             //sprawdza poprawność maili
    void encryptFile (string password);
    void decryptFile (string password);
};
