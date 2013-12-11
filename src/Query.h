#pragma once
#include "Criteria.h"
#include <vector>
using namespace std;

/* Klasa Query - czyli zapytanie wysyłane do bazy danych. Zawiera informacje na temat tego, po jakich kryteriach
    chcemy wyszukiwać elementy (emaile, grupy bądź usemberów) oraz jak (według kolejno jakich pól) mają być
    posortowane wyniki. Kryteria mogą zawierać dokładną wartość danego pola, przedział, a także znaki *
    (dowolne znaki w nazwie). Na jej podstawie baza tworzy wektor wyników wyszukiwania.							 */

class Query
{
private:
    //vector<DataType> sortingOrder;
    vector<Criteria> criteriaVector;
public:
    Query();
    ~Query();
};
