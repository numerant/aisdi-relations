#pragma once
#include <vector>
#include <string>
#include "Usember.h"
#include "Database.h"
#include "Date.h"
using namespace std;

/*
    Klasa Statistics, przechowujaca zestaw statystyk z bazy, udostepnianych GUI, ktory bedzie wyswietlal je w formie tabel, wykresow, itp.
    Do uaktualnienia danych sluzy metoda update(), ktora pobiera odpowiednie dane z bazy, przetwarza je i zastepuje poprzednie wartosci poszczegolnych pol.
*/

class Statistics
{
private:
    const unsigned int TOP_USEMBERS_COUNT=5;
    Database* database;
    int emails;                         
    int groups;                         //ilosc maili, grup, usemberow w bazie
    int usembers;                       
    double emailsPerMonth;
    double emailsPerDay;                //ilosc maili wyslanych na miesiac i dzien
    double emailsPerUser;               //ilosc maili przypadajacych na 1 uzytkownika
    double averageEmailLength;          //srednia dlugosc maila
    int emailsCountInMonth[12];         //ilosc maili wyslanych w poszczegolnych miesiacach
    int maxEmailsInMonth;
    int forwardCount;                   //ilosc maili bedacych forwardwami innych maili bazie
    int replyCount;                     //ilosc maili bedacych odpowiedziami na inne maile w bazie
    Date earliestDate;                  //najwczesniejsza data wyslania maila
    Date latestDate;                    //najpozniejsza data wyslania maila
    int duration;                       //roznica w nidach pomiedzy ww. datami
    vector<Usember*> topSenders;        //pieciu usemberow, ktorzy maja najwiecej wyslanych maili
    vector<Usember*> topReceivers;      //pieciu usemberow, ktorzy maja najwiecej odebrnych maili

public:
    Statistics(Database* database);
    ~Statistics();
    void update();
    int getEmails();
    int getGroups();
    int getUsembers();
    double getEmailsPerMonth();
    double getEmailsPerDay();
    double getEmailsPerUser();
    double getAverageEmailLength();
    int getEmailsCountInMonth(int month);
    int getMaxEmailsInMonth();
    int getForwards();
    int getReplies();
    Date* getEarliest();
    Date* getLatest();
    int getDuration();
    Usember* getTopSender(int position);
    Usember* getTopReceiver(int position);

private:
    void updateVectorSizes();
    void updateEmailStatistics();
    void updateTopUsembers();
    int getDateDifferenceInMonths(Date* date1, Date* date2);
    int getDateDifferenceInDays(Date* date1, Date* date2);
    static bool compareUsembersSentEmails(Usember* usember1, Usember* usember2);
    static bool compareUsembersReceivedEmails(Usember* usember1, Usember* usember2);
};
