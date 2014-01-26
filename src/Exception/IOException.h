#pragma once
#include <iostream>
#include <string>
#include <exception>

/*
	Klasa IOException i po niej dziedziczące
	Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface
*/

class IOException : public std::exception {};

class UnableToOpenFile : public IOException {};
class UnableToOpenDirectory : public IOException {};
class InvalidFile : public IOException {};
class InvalidPassword : public IOException {};
class EmlSyntaxIncorrect : public IOException {};
