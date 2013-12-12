// Struktury zawierające parametry wczytywania / zapisywania maili bądź bazy danych.
// Można to podzielić na kilka plików, ale to chyba bez sensu (bo i metod za wielu nie będzie, bałagan się nie zrobi, a wszystko będzie w jednym miejscu).

#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>

using namespace std;

class Parameters
{
public:
    string path;

    Parameters();
};

class MailParameters : public Parameters          // parametry wczytywania maili, wskazują jak zachować ma się IOInterface
{
public:
    bool isDirectory;
    bool recursiveImport;
};

class DbParameters : public Parameters            // parametry importu / eksportu bazy danych
{
private:
    bool isPasswordProtected;
    string password;
};


#endif // PARAMETERS_H
