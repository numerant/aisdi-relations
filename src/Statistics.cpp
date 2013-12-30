#include "Statistics.h"

Statistics::Statistics(Database* database)
{
    this->database=database;
    emails=0;
    groups=0;
    usembers=0;
    emailsPerMonth=0;
    emailsPerDay=0;
    emailsPerUser=0;
    averageEmailLength=0;
}

Statistics::~Statistics()
{
    topSenders.clear();
    topReceivers.clear();
}

void Statistics::update()
{
    updateVectorSizes();
    updateEmailStatistics();
    updateTopUsembers();
}

int Statistics::getEmails()
{
    return emails;
}

int Statistics::getGroups()
{
    return groups;
}

int Statistics::getUsembers()
{
    return usembers;
}

double Statistics::getEmailsPerMonth()
{
    return emailsPerMonth;
}

double Statistics::getEmailsPerDay()
{
    return emailsPerDay;
}

double Statistics::getAverageEmailLength()
{
    return averageEmailLength;
}

double Statistics::getEmailsPerUser()
{
    return emailsPerUser;
}

Usember* Statistics::getTopSender(int position)
{
    if(position>=0 && position<topSenders.size())
        return topSenders[position];
    else
        return nullptr;
}

Usember* Statistics::getTopReceiver(int position)
{
    if(position>=0 && position<topReceivers.size())
        return topReceivers[position];
    else
        return nullptr;
}


void Statistics::updateVectorSizes()
{
    emails=database->countEmails();
    groups=database->countGroups();
    usembers=database->countUsembers();
}

void Statistics::updateEmailStatistics()
{
    if(emails>0){
        Date earliestDate=database->getEmail(0)->getDate();
        Date latestDate=database->getEmail(0)->getDate();
        for(int i=0; i<database->countEmails(); ++i)
        {
            if(database->getEmail(i)->getDate().compare(earliestDate)<0)
                earliestDate=database->getEmail(i)->getDate();
            if(database->getEmail(i)->getDate().compare(latestDate)>0)
                latestDate=database->getEmail(i)->getDate();
        }
        emailsPerMonth=(double)emails/(double)getDateDifferenceInMonths(&earliestDate, &latestDate);
        emailsPerDay=(double)emails/(double)getDateDifferenceInDays(&earliestDate, &latestDate);
        if(usembers>0)
            emailsPerUser=(double)emails/(double)usembers;
        long sum=0;
        for(int i=0; i<database->countEmails(); ++i)
        {
            sum+=database->getEmail(i)->getContent().length();
        }
        averageEmailLength=(double)sum/(double)emails;
    }
}

void Statistics::updateTopUsembers()
{
    if(usembers>0){
        for(int i=0; i<database->countUsembers(); ++i)
        {
            topSenders.push_back(database->getUsember(i));
            topReceivers.push_back(database->getUsember(i));
        }
        sort(topSenders.begin(), topSenders.end(), Statistics::compareUsembersSentEmails);
        sort(topReceivers.begin(), topReceivers.end(), Statistics::compareUsembersReceivedEmails);
        while(topSenders.size()>TOP_USEMBERS_COUNT){
            topSenders.pop_back();
            topReceivers.pop_back();
        }
    }
}

int Statistics::getDateDifferenceInMonths(Date* date1, Date* date2)
{
    return (date2->getYear()-date1->getYear())*12+date2->getMonthInt()-date1->getMonthInt();
}

int Statistics::getDateDifferenceInDays(Date* date1, Date* date2)
{
    return (date2->getYear()-date1->getYear())*365+(date2->getMonthInt()-date1->getMonthInt())*30+date2->getDay()-date1->getDay();
}

bool Statistics::compareUsembersSentEmails(Usember* usember1, Usember* usember2)
{
    if(usember1->sentMailCount()>=usember2->sentMailCount())
        return true;
    else
        return false;
}

bool Statistics::compareUsembersReceivedEmails(Usember* usember1, Usember* usember2)
{
    if(usember1->receivedMailCount()>=usember2->receivedMailCount())
        return true;
    else
        return false;
}
