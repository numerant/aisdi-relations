// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#include "IOException.h"

using namespace std;

IOException::IOException()
{
    ++nrexceptions;
}

string IOException::show(){}


string UnableToOpenFile::showExceptions()
{
    return "Nie można odczytać pliku";
}

string EmlSynataxIncorrect::showExceptions()
{
    return "Mail nie jest poprawny składniowo";
}

string EmlExists::showExceptions()
{
    return "Mail już istnieje";
}
