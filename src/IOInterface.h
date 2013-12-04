# IOInterface class
# This class is responsible for all file operations, like database import / export, e-mail import etc.

#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <vector>

class IOInterface
{
    public:
    // Classes
        struct ImportStats { }                                                      // IOInterface::ImportStats

    // Methods:
        IOInterface();                                                              // trzeba zadbać o wskaźnik na bazę danych
        ~IOInterface();

        ImportStats importMail(string path, MailImportParam *parameters);

        void exportDatabase (string file_path, ExportParam *parameters);            // można zrobić klasę Param, a ImportParam i ExportParam bedą po niej dziedziczyć
        void importDatabase (string file_path, DbImportParam * parameters);
        void exportReport (string path, Report report);

    private:
    // Fields:
        Database *database;                         // baza tworzona w momencie uruchomienia programu, czy przy imporcie maili?
        Email *temp_email;
        vector<char> *binary_file;                  // trzyma zserializowaną bazę danych w formie binarnej

    // Methods:
        void emlParser (string eml_content);        //sprawdza poprawność maili
        void encryptFile (string password);
        void decryptFile (string password);
};

#endif // IOINTERFACE_H
