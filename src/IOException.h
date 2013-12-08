// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H


class IOException : public exception {};

class UnableToOpenFile : public IOException {};                 // można zaszaleć i jeszcze bardziej podzielić te wyjątki - np. zrobić jeszcze ParserException
class EmlSyntaxIncorrect : public IOException {};

#endif // IOEXCEPTION_H
