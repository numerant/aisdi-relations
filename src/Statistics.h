#pragma once
#include <vector>
#include <string>
#include "Usember.h"
#include "Database.h"
#include "Date.h"
using namespace std;

/*Klasa Statistics, przechowujaca zestaw statystyk z bazy, udostepnianych GUI, ktory bedzie wyswietlal je w formie tabel, wykresow, itp.
Do uaktualnienia danych sluzy metoda update(), ktora pobiera odpowiednie dane z bazy, przetwarza je i zastepuje poprzednie wartosci poszczegolnych pol.
*/

class Statistics
{
private:
    const int TOP_USEMBERS_COUNT=5;
    Database* database;
    int emails;                         //
    int groups;                         //ile maili, grup, usemberow w bazie
    int usembers;                       //
    double emailsPerMonth;
    double emailsPerDay;
    double emailsPerUser;
    double averageEmailLength;
    int emailsCountInMonth[12];
    int maxEmailsInMonth;
    int forwardCount;
    int replyCount;
    Date earliestDate;
    Date latestDate;
    int duration;
    vector<Usember*> topSenders;        //powiedzmy, pieciu usemberow, ktorzy maja najwiecej wyslanych maili, mozna na wykresie pokazac dla kazdego ile maili wyslal
    vector<Usember*> topReceivers;      //jw, tyle ze odebranych

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
