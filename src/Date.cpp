#include <string>
#include <sstream>
#include "Date.h"

using namespace std;

Date::Date()
{

}

Date::Date(const Date &date)
{
    weekDay = date.weekDay;
    day = date.day;
    month = date.month;
    year = date.year;
    hour = date.hour;
    minute = date.minute;
}

Date::Date (string newDate)
{
    string tempString;
    stringstream stream;

    fullDate = newDate;
	//weekDay
    stream<<newDate;
    stream>>tempString;
    tempString.erase(tempString.end()-1, tempString.end());
    weekDay = tempString;

    //day
    stream<<newDate;
    stream>>tempString;
    day = atoi(tempString.c_str());

    //month
    stream<<newDate;
    stream>>tempString;
    month = tempString;
    monthInt = monthToInt(month);

    //year
    stream<<newDate;
    stream>>tempString;
    year = atoi(tempString.c_str());

    //hour:minute:second
    stream<<newDate;
    stream>>tempString;
    string tempHour(tempString, 0, 2);
    hour = atoi(tempHour.c_str());
    string tempMin(tempString, 3, 2);
    minute = atoi(tempMin.c_str());
    string tempSec(tempString, 5, 2);
    second = atoi(tempSec.c_str());

    //timeZone
    stream<<newDate;
    stream>>timeZone;
}

Date::~Date() {}

string Date::getFullDate()
{
	return fullDate;
}

string Date::getWeekDate(void)
{
    return weekDay;
}

void Date::setWeekDay(string newWeekDay)
{
    weekDay = newWeekDay;
}

int Date::getDay()
{
    return day;
}

void Date::setDay(int newDay)
{
    day = newDay;
}

string Date::getMonth()
{
    return month;
}

void Date::setMonth(string newMonth)
{
    month = newMonth;
}

int Date::getYear()
{
    return year;
}

void Date::setYear(int newYear)
{
    year = newYear;
}

int Date::getHour()
{
    return hour;
}

void Date::setHour(int newHour)
{
    hour = newHour;
}

int Date::getMinute()
{
    return minute;
}

void Date::setMinute(int newMinute)
{
    minute = newMinute;
}

int Date::getSecond()
{
    return second;
}

void Date::setSecond(int newSecond)
{
    second = newSecond;
}

string Date::getTimeZone()
{
    return timeZone;
}

void Date::setTimeZone(string newTimeZone)
{
    timeZone = newTimeZone;
}

/*porównuje dwie daty, format: Date.compare(Date2)
jako wynik zwraca: 1 - Date > Date2 | -1 - Date < Date2 | 0 - Date == Date2*/
int Date::compare(Date &date2)
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

int Date::monthToInt(string stringMonth)
{
    if(stringMonth == "Jan")
        monthInt = 1;
    if(stringMonth == "Feb")
        monthInt = 2;
    if(stringMonth == "Mar")
        monthInt = 3;
    if(stringMonth == "Apr")
        monthInt = 4;
    if(stringMonth == "May")
        monthInt = 5;
    if(stringMonth == "Jun")
        monthInt = 6;
    if(stringMonth == "Jul")
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

	return monthInt;
}
