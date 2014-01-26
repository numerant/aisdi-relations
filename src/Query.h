#pragma once
#include "Criteria.h"
#include <vector>

using namespace std;

/*  
    Klasa Query - czyli zapytanie wysyłane do bazy danych. Zawiera informacje na temat tego, po jakich kryteriach
    chcemy wyszukiwać elementy (emaile  bądź usemberów). Na jej podstawie baza tworzy wektor wyników wyszukiwania.							 
*/

class StringCriteria;
class DateCriteria;

class Query
{
protected:
    vector<StringCriteria> stringCriteriaVector;    //wektory kryteriow wyszukiwania
    vector<DateCriteria> dateCriteriaVector;        

public:
    Query();
    ~Query();
    virtual void clear();                                   //metoda czyszczaca zapytanie
    StringCriteria* getStringCriteria(int position);        //metody zwracajace pojedynczy element danego wektora
    DateCriteria* getDateCriteria(int position);    
    int getStringCriteriaVectorSize();                      //metody zwracajace rozmiar danego wektora
    int getDateCriteriaVectorSize();                
    void addStringCriteria(StringCriteria stringCriteria);  //metody dodajace nowe kryterium do zapytania
    void addDateCriteria(DateCriteria dateCriteria);

};

class EmailQuery :
    public Query
{
    bool replies;       //zmienne boolowskie, ktore mowia, czy szukamy tylko posrododpowiedzi, tylko forwardow,
    bool forwards;      //czy tez posrod wszystkich maili w bazie

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



