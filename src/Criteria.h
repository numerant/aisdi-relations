#pragma once
#include <string>
#include "Date.h"
#include "Email.h"
using namespace std;

enum SearchKey {E_FROM, E_DATE, E_REPLY_TO, E_TO, E_ID, E_SUBJECT, G_ID, G_USEMBER, G_USEMBERS_NUMBER, U_NAME, U_DOMAIN};

class Criteria
{
private:
    SearchKey searchKey;
public:
    SearchKey getSearchKey();
};

class IntCriteria :
	public Criteria
{
private:
	int equals;         //wartosc, ktorej musi rownac sie dane pole, jesli wypelnione, nadpisuje dwa pozostale
	int less;           //wartosc, od ktorej dane pole musi byc wieksze
	int greater;        //wartosc, od ktorej dane pole musi byc mniejsze
public:
	IntCriteria();
	~IntCriteria();
	int getEquals();
	int getLess();
	int getGreater();
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
