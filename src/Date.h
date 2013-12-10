#pragma once
#include <string>

using namespace std;
/*
	Klasa przechowująca informacje dotyczące daty oraz operacje na niej.
*/

class Date
{
	//dzień tygodnia
	string weekDay;
	//dzień
	int day;
	//miesiąc
	int month;
	//rok
	int year;
	//godzina
	int hour;
	//minuta
	int minute;


public:
	Date();
	Date(const Date &date)
	{
		weekDay = date.weekDay;
		day = date.day;
		month = date.month;
		year = date.year;
		hour = date.hour;
		minute = date.minute;
	}
	~Date();

	string getweekDat()
	{
		return weekDay;
	}

	void setWeekDay(string newWeekDay)
	{
		weekDay = newWeekDay;
	}

	int getDay()
	{
		return day;
	}

	void setDay(int newDay)
	{
		day = newDay;
	}

	int getMonth()
	{
		return month;
	}

	void setMonth(int newMonth)
	{
		month = newMonth;
	}

	int getYear()
	{
		return year;
	}

	void setYear(int newYear)
	{
		year = newYear;
	}

	int getHour()
	{
		return hour;
	}

	void setHour(int newHour)
	{
		hour = newHour;
	}

	int getMinute()
	{
		return minute;
	}

	void setMinute(int newMinute)
	{
		minute = newMinute;
	}
	
	/*porównuje dwie daty, format: Date.compare(Date2)
	jako wynik zwraca: 1 - Date > Date2 | -1 - Date < Date2 | 0 - Date == Date2*/
	int compare(Date &date2)
	{
		if(year > date2.year)
			return 1;
		if(year < date2.year)
			return -1;
		if(month > date2.month)
			return 1;
		if(month < date2.month)
			return -1;
		if(day > date2.day)
			return 1;
		if(day < date2.day)
			return -1;
		if(hour > date2.hour)
			return 1;
		if(minute < date2.minute)
			return -1;
		return 0;
	}
	
};
