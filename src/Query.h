#pragma once
#include "Criteria.h"
#include <vector>

using namespace std;

/*                      ---TODO---                      *
 *  Wyrzucic ze wszystkich plikow includy               *
 *  EmailQuery, GroupQuery i UsemberQuery (.h i .cpp)   */


/*  Klasa Query - czyli zapytanie wysyłane do bazy danych. Zawiera informacje na temat tego, po jakich kryteriach
    chcemy wyszukiwać elementy (emaile, grupy bądź usemberów) oraz jak (według kolejno jakich pól) mają być
    posortowane wyniki. Kryteria mogą zawierać dokładną wartość danego pola badz w przypadku intow i dat przedział, a w przypadku stringow znaki *
    (dowolne znaki w nazwie). Na jej podstawie baza tworzy wektor wyników wyszukiwania.							 */

class Query
{
protected:
    vector<SearchKey> sortingOrder;                 //wektor przechowujacy klucz do posortowania wynikow wyszukiwania - sortowanie odbywa sie wg klucza na
                                                    //1. pozycji, w przypadku elementow o takiej samej wartosci danego pola - wg klucza na 2. pozycji itd.
    vector<IntCriteria> intCriteriaVector;          //
    vector<StringCriteria> stringCriteriaVector;    //wektory kryteriow wyszukiwania
    vector<DateCriteria> dateCriteriaVector;        //

public:
    Query();
    ~Query();
    virtual void clear();                           //metoda czyszczaca zapytanie
    IntCriteria* getIntCriteria(int position);      //
    StringCriteria* getStringCriteria(int position);//metody zwracajace pojedynczy element danego wektora
    DateCriteria* getDateCriteria(int position);    //
    int getIntCriteriaVectorSize();                 //
    int getStringCriteriaVectorSize();              //metody zwracajace rozmiar danego wektora
    int getDateCriteriaVectorSize();                //
};

class EmailQuery :
    public Query
{
public:
    EmailQuery();
    ~EmailQuery();
    void clear();
};

class GroupQuery :
    public Query
{
public:
    GroupQuery();
    ~GroupQuery();
    void clear();
};

class UsemberQuery :
    public Query
{
public:
    UsemberQuery();
    ~UsemberQuery();
    void clear();
};



