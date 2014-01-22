#pragma once
#include <string>
#include "Date.h"
#include "Email.h"
using namespace std;

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
	Date equals;        //jak przy intCriteria
	Date less;
	Date greater;
public:
	DateCriteria(Date equals, Date less, Date greater);
	~DateCriteria();
	Date* getEquals();
	Date* getLess();
	Date* getGreater();
};
