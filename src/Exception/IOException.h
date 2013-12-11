// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

class IOException : public exception
{
private:
    static int nrexceptions;
public:
    IOException();
    showException();
    
};

class UnableToOpenFile : public IOException
{
public:
    string showException();
};

class EmlSyntaxIncorrect : public IOException
{
public:
    string showException();
};

class EmlExists() : public IOException
{
    public
    string showException();
}


#endif