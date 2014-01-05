#pragma once
#include <string>
#include <sstream>
#include <boost/serialization/base_object.hpp>
#include "SerializationInit.h"

using namespace std;

/*
    Klasa przechowująca informacje dotyczące daty oraz operacje na niej.
*/

class Date
{
    template<class Archive> friend void  boost::serialization::serialize(Archive &, Date &, const unsigned int);  //potrzebne do serializacji

private:
    //pola przechowujące wszystkie elementy daty emaila
	string fullDate;
    string weekDay;
    int day;
    string month;
    int monthInt;
    int year;
    int hour;
    int minute;
    int second;
    string timeZone;

public:
    Date();
    Date(const Date &date);
    Date (string newDate);
    ~Date();

	string getFullDate();
    void setWeekDay(string );
    string getWeekDate(void);
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
};
