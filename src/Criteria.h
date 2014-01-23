#pragma once
#include <string>
#include "Date.h"
#include "Email.h"
using namespace std;

/*  Klasa Criteria - czyli pojedyncze kryterium zapytania do bazy danych. Kryteria moga byc typu StringCriteria badz DateCriteria   */

enum SearchKey {E_EMAIL, E_SUBJECT, E_CONTENT, E_NAME};

class Criteria
{

};

class StringCriteria :
	public Criteria
{
private:
    SearchKey searchKey;
	string name;         //poszukiwany ciag znakow
public:
	StringCriteria(SearchKey searchKey, string name);
	~StringCriteria();
	SearchKey getSearchKey();
	string getName();

};

class DateCriteria :
	public Criteria
{
	Date equals;        //data, ktorej data w szukanym mailu mailu musi byc odpowiednio rowna, mniejsza od niej lub wieksza
	Date less;
	Date greater;
public:
	DateCriteria(Date equals, Date less, Date greater);
	~DateCriteria();
	Date* getEquals();
	Date* getLess();
	Date* getGreater();
};
