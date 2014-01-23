#pragma once
#include "Criteria.h"
#include <vector>

using namespace std;

/*  Klasa Query - czyli zapytanie wysyłane do bazy danych. Zawiera informacje na temat tego, po jakich kryteriach
    chcemy wyszukiwać elementy (emaile, grupy bądź usemberów) oraz jak (według kolejno jakich pól) mają być
    posortowane wyniki. Kryteria mogą zawierać dokładną wartość danego pola badz w przypadku intow i dat przedział, a w przypadku stringow znaki *
    (dowolne znaki w nazwie). Na jej podstawie baza tworzy wektor wyników wyszukiwania.							 */

class StringCriteria;
class DateCriteria;

class Query
{
protected:
    vector<StringCriteria> stringCriteriaVector;    //1. pozycji, w przypadku elementow o takiej samej wartosci danego pola - wg klucza na 2. pozycji itd.
    vector<DateCriteria> dateCriteriaVector;        //wektory kryteriow wyszukiwania

public:
    Query();
    ~Query();
    virtual void clear();                           //metoda czyszczaca zapytanie
    StringCriteria* getStringCriteria(int position);//metody zwracajace pojedynczy element danego wektora
    DateCriteria* getDateCriteria(int position);    //
    int getStringCriteriaVectorSize();               //metody zwracajace rozmiar danego wektora
    int getDateCriteriaVectorSize();                //
    void addStringCriteria(StringCriteria stringCriteria);
    void addDateCriteria(DateCriteria dateCriteria);

};

class EmailQuery :
    public Query
{
    bool replies;
    bool forwards;

public:
    EmailQuery(bool replies, bool forwards);
    ~EmailQuery();
    void clear();
    bool searchingForReplies();
    bool searchingForForwards();
};

class UsemberQuery :
    public Query
{
public:
    UsemberQuery();
    ~UsemberQuery();
    void clear();
};



