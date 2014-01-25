#pragma once
#include <string>

using namespace std;

// Struktury zawierające parametry wczytywania / zapisywania maili bądź bazy danych.

class Parameters
{
public:
    string path;
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
