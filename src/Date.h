#pragma once
#include <string>
#include <sstream>

using namespace std;
/*
        Klasa przechowująca informacje dotyczące daty oraz operacje na niej.
*/

class Date
{
private:
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
    Date();
    Date(const Date &date);
    Date (string newDate);
    ~Date();
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

