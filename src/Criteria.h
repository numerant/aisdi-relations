#pragma once
#include <string>
#include "Date.h"
#include "Email.h"
using namespace std;

enum SearchKey {E_DATE, E_EMAIL, E_SUBJECT, E_CONTENT, U_NAME};

class Criteria
{
private:
    SearchKey searchKey;
public:
    SearchKey getSearchKey();
};

class StringCriteria :
	public Criteria
{
private:
	string name;         //poszukiwany ciag znakow
public:
	StringCriteria();
	~StringCriteria();
	string getName();
};

class DateCriteria :
	public Criteria
{
	Date equals;        //jak przy intCriteria
	Date less;
	Date greater;
public:
	DateCriteria();
	~DateCriteria();
	Date* getEquals();
	Date* getLess();
	Date* getGreater();
};
