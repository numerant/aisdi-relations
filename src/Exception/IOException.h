// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>


class IOException : public std::exception {};

class UnableToOpenFile : public IOException {};
class InvalidFile : public IOException {};
class EmlSyntaxIncorrect : public IOException {};


#endif
