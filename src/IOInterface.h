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
        unsigned int successCount;
        unsigned int failCount;
        unsigned int existingCount;                                             // maile, które już istniały w bazie
    };

    // Methods:
    IOInterface();
    ~IOInterface();


    void importMail(MailParameters *parameters);
    ImportStats getImportStats();
    void clearImportStats();

    void exportDatabase (string filePath, DbParameters *parameters);                    // opis klas MailParameters i DbParameters jest w Parameters.h
    bool isImportedFileProtected (string filePath);
    Database* importDatabase (DbParameters *parameters);
    void exportDatabaseReport (string path, Statistics* dbStatistics);
    void exportDatabaseToTxt (string directoryPath);                                    // w podanym katalogu tworzy pliki tekstowe z rekordami bazy danych, przystosowane do importu do np. Accessa

    void setDatabasePointer (Database * db);
    string strSequenceReplace(const string& searched, const string& replaced, string subject);

private:
    // Fields:
    Database *database;                         // baza tworzona w momencie uruchomienia programu
    ImportStats stats;
    ifstream inputFile;

    // Methods:
    void xorStream(istream &inputStream, ostream &outputStream, string key);  // szyfruje/deszyfruje strumień algorytmem XOR
    void importSingleMail(boost::filesystem::path path, ImportStats &stats);
    Email* emlParser (string path);             //sprawdza poprawność maili
};
