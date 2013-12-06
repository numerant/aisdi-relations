// Struktury zawierające parametry wczytywania / zapisywania maili bądź bazy danych.
// Można to podzielić na kilka plików, ale to chyba bez sensu (bo i metod za wielu nie będzie, bałagan się nie zrobi, a wszystko będzie w jednym miejscu).

#ifndef PARAM_H
#define PARAM_H


virtual class Param
{
    private:
        string path;
};

class MailParam : public Param          // parametry wczytywania maili, wskazują jak zachować ma się IOInterface
{
    private:
        bool isDirectory;
        bool recursiveImport;
}

class DbParam : public Param            // parametry importu / eksportu bazy danych
{
    private:
        bool isPasswordProtected;
        string password;
}


#endif // PARAM_H
