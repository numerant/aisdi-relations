#pragma once
#include <string>
#include <sstream>

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
    string month;
	int monthInt;
    //rok
    int year;
    //godzina
    int hour;
    //minuta
    int minute;
    //sekunda
    int second;
    //strefa czasowa;
    string timeZone;


public:
    Date() {};
    Date(const Date &date)
    {
        weekDay = date.weekDay;
        day = date.day;
        month = date.month;
        year = date.year;
        hour = date.hour;
        minute = date.minute;
    }

    Date (string newDate)
    {
		string tempString;
		stringstream stream;
		//weekDay
		stream>>newDate;
		stream<<tempString;
		tempString.erase(tempString.end()-1, tempString.end());
		weekDay = tempString;

		//day
		stream>>newDate;
		stream<<tempString;
		day = atoi(tempString.c_str());

		//month
		stream>>newDate;
		stream<<tempString;
		month = tempString;
		monthInt = monthToInt(month);

		//year
		stream>>newDate;
		stream<<tempString;
		year = atoi(tempString.c_str());

		//hour:minute:second
		stream>>newDate;
		stream<<tempString;
		string tempTime(tempString, 0, 2);
		hour = atoi(tempTime.c_str());
		string tempTime(tempString, 3, 2);
		minute = atoi(tempTime.c_str());
		string tempTime(tempString, 5, 2);
		second = atoi(tempTime.c_str());

		//timeZone
		stream>>newDate;
		stream<<timeZone;
    }

    ~Date() {};

	string getWeekDate();
	void setWeekDay(string );
	int getDay();
	void setDay(int newDay);
	string getMonth();
	void setMonth(string );
	int getYear();
	void setYear(int );
	int getHour();
	void setHour(int );
	int getMinute();
	void setMinute(int );
	int getSecond();
	void setSecond(int );
	string getTimeZone();
	void setTimeZone(string );
	int compare(Date &);
	int monthToInt(string );

    string getWeekDate()
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

    string getMonth()
    {
        return month;
    }

    void setMonth(string newMonth)
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

    int getSecond()
    {
        return second;
    }

    void setSecond(int newSecond)
    {
        second = newSecond;
    }

    string getTimeZone()
    {
        return timeZone;
    }

    void setTimeZone(string newTimeZone)
    {
        timeZone = newTimeZone;
    }

    /*porównuje dwie daty, format: Date.compare(Date2)
    jako wynik zwraca: 1 - Date > Date2 | -1 - Date < Date2 | 0 - Date == Date2*/
    int compare(Date &date2)
    {
        if(year > date2.year)
            return 1;
        if(year < date2.year)
            return -1;
        if(monthInt > date2.monthInt)
            return 1;
        if(monthInt < date2.monthInt)
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

	int monthToInt(string stringMonth)
	{
		if(stringMonth == "Jan")
			monthInt = 1;
		if(stringMonth == "Feb")
			monthInt = 2;
		if(stringMonth == "March")
			monthInt = 3;
		if(stringMonth == "Apr")
			monthInt = 4;
		if(stringMonth == "May")
			monthInt = 5;
		if(stringMonth == "June")
			monthInt = 6;
		if(stringMonth == "July")
			monthInt = 7;
		if(stringMonth == "Aug")
			monthInt = 8;
		if(stringMonth == "Sep")
			monthInt = 9;
		if(stringMonth == "Oct")
			monthInt = 10;
		if(stringMonth == "Nov")
			monthInt = 11;
		if(stringMonth == "Dec")
			monthInt = 12;
	}
};
