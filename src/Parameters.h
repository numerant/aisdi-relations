#pragma once
#include <string>

using namespace std;

// Struktury zawierające parametry wczytywania / zapisywania maili bądź bazy danych.
// Można to podzielić na kilka plików, ale to chyba bez sensu (bo i metod za wielu nie będzie, bałagan się nie zrobi, a wszystko będzie w jednym miejscu).

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
public:
    bool isPasswordProtected;
    string password;
};
