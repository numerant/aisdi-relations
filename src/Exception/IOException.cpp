// Klasa IOException i po niej dziedziczące
// Służą do rzucania wyjątków mogących wystąpić podczas pracy metod klasy IOInterface

#include "IOException.h"

using namespace std;

IOException::IOException(string mess)
{
   //strcpy(message, mess);
}

string IOException::show()
{
    return message;
}
