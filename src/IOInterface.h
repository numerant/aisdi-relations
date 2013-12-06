// IOInterface class
// This class is responsible for all file operations, like database import / export, e-mail import etc.

// Klasa IOInterface
// Odpowiedzialna za operacje na plikach, takie jak wczytywanie maili do bazy danych, import / eksport bazy, zapisywanie raportów do pliku

#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <vector>
#include <fstream>
#include "boost/filesystem.hpp"         // do wczytywania plików z katalogu - także rekursywnie
#include "Database.h"
#include "Email.h"
#include "Param.h"

using namespace std;

class IOInterface
{
    public:
    // Classes:
        struct ImportStats                                                          // struktura zawierająca statystyki importu - ile udało się wczytać, ile nie itp.
        {
            ImportStats();
            unsigned int successCount;                                              // niech ktoś mądry się wypowie czy tak jest OK, czy lepiej bawić się w set/get
            unsigned int failCount;
            unsigned int existingCount;                                             // maile, które już istniały w bazie
        };

    // Methods:
        IOInterface();                                                              // trzeba zadbać o wskaźnik na bazę danych
        ~IOInterface();

        ImportStats importMail(MailParam *parameters);

        void exportDatabase (string filePath, DbParam *parameters);                 // opis klas MailParam i DbParam jest w Param.h
        void importDatabase (string filePath, DbParam *parameters);
        void exportReport (string path, Report report);

    private:
    // Fields:
        Database *database;                         // baza tworzona w momencie uruchomienia programu, czy przy imporcie maili?
        //vector<char> *binary_file;                // trzyma zserializowaną bazę danych w formie binarnej - chyba lepiej tworzyć lokalnie, wewnątrz metody

    // Methods:
        Email* emlParser (string path);             //sprawdza poprawność maili
        void encryptFile (string password);
        void decryptFile (string password);
};

#endif // IOINTERFACE_H
