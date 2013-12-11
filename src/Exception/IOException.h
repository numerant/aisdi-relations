// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class IOException : public exception
{
    protected:
        string message;
    public:
        IOException(string);
        string show();
};

class UnableToOpenFile : public IOException{};                 // można zaszaleć i jeszcze bardziej podzielić te wyjątki - np. zrobić jeszcze ParserException
class EmlSyntaxIncorrect : public IOException {};

