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
    for(int i=0; i<12; ++i)
        emailsCountInMonth[i]=0;
    maxEmailsInMonth=0;
    replyCount=0;
    forwardCount=0;
    duration=0;
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

int Statistics::getEmailsCountInMonth(int month)
{
    if(month>=1 && month<=12)
        return emailsCountInMonth[month-1];
    else
        return 0;
}

int Statistics::getMaxEmailsInMonth()
{
    return maxEmailsInMonth;
}

int Statistics::getForwards()
{
    return forwardCount;
}

int Statistics::getReplies()
{
    return replyCount;
}

Date* Statistics::getEarliest()
{
    return &earliestDate;
}

Date* Statistics::getLatest()
{
    return &latestDate;
}

int Statistics::getDuration()
{
    return duration;
}

Usember* Statistics::getTopSender(int position)
{
    if(position>=0 && position< (int)topSenders.size())
        return topSenders[position];
    else
        return nullptr;
}

Usember* Statistics::getTopReceiver(int position)
{
    if(position>=0 && position< (int)topReceivers.size())
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
    if(emails>0)
    {
        earliestDate=database->getEmail(0)->getDate();
        latestDate=database->getEmail(0)->getDate();

        for(int i=1; i<database->countEmails(); ++i)
        {
            if((database->getEmail(i)->getDate()).compare(earliestDate)<0){
                earliestDate.setMinute(database->getEmail(i)->getDate().getMinute());
                earliestDate.setHour(database->getEmail(i)->getDate().getHour());
                earliestDate.setDay(database->getEmail(i)->getDate().getDay());
                earliestDate.setWeekDay(database->getEmail(i)->getDate().getWeekDate());
                earliestDate.setMonth(database->getEmail(i)->getDate().getMonth());
                earliestDate.monthToInt(database->getEmail(i)->getDate().getMonth());
                earliestDate.setYear(database->getEmail(i)->getDate().getYear());
            }
            if((database->getEmail(i)->getDate()).compare(latestDate)>0){
                latestDate.setMinute(database->getEmail(i)->getDate().getMinute());
                latestDate.setHour(database->getEmail(i)->getDate().getHour());
                latestDate.setDay(database->getEmail(i)->getDate().getDay());
                latestDate.setWeekDay(database->getEmail(i)->getDate().getWeekDate());
                latestDate.setMonth(database->getEmail(i)->getDate().getMonth());
                latestDate.monthToInt(database->getEmail(i)->getDate().getMonth());
                latestDate.setYear(database->getEmail(i)->getDate().getYear());
            }
        }

        duration=getDateDifferenceInDays(&earliestDate, &latestDate);
        double differenceInMonths=(double)getDateDifferenceInMonths(&earliestDate, &latestDate);
        if(differenceInMonths>0)
            emailsPerMonth=(double)emails/differenceInMonths;
        else
            emailsPerMonth=0;
        if(duration>0)
            emailsPerDay=(double)emails/(double)duration;
        else
            emailsPerDay=0;
        if(usembers>0)
            emailsPerUser=(double)emails/(double)usembers;
        else
            emailsPerUser=0;
        long sum=0;
        for(int i=0; i<database->countEmails(); ++i)
        {
            sum+=database->getEmail(i)->getContent().length();
        }
        averageEmailLength=(double)sum/(double)emails;

        int replies=0;
        for(int i=0; i<database->countEmails(); ++i)
            if(database->getEmail(i)->getInReplyTo()!="")
                ++replies;
        replyCount=replies;

        int forwards=0;
        for(int i=0; i<database->countEmails(); ++i)
            forwards+=database->getEmail(i)->getForwards().size();
        forwardCount=forwards;

        int month=1;
        for(int i=0; i<12; ++i)
            emailsCountInMonth[i]=0;
        for(int i=0; i<database->countEmails(); ++i)
        {
            month=database->getEmail(i)->getDate().monthToInt(database->getEmail(i)->getDate().getMonth());
            if(month>=1 && month<=12)
                ++emailsCountInMonth[month-1];
            if (emailsCountInMonth[month-1] > maxEmailsInMonth)
                maxEmailsInMonth = emailsCountInMonth[month-1];
        }
    }
}

void Statistics::updateTopUsembers()
{
    if(usembers>0){
        topSenders.clear();
        topReceivers.clear();
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
    return abs((date2->getYear()-date1->getYear())*12+date2->monthToInt(date2->getMonth())-date1->monthToInt(date1->getMonth()));
}
int Statistics::getDateDifferenceInDays(Date* date1, Date* date2)
{
    return abs((date2->getYear()-date1->getYear())*365+(date2->monthToInt(date2->getMonth())-date1->monthToInt(date1->getMonth()))*30+date2->getDay()-date1->getDay());
}

bool Statistics::compareUsembersSentEmails(Usember* usember1, Usember* usember2)
{
    if(usember1->sendMailCount()>=usember2->sendMailCount())
        return true;
    else
        return false;
}

bool Statistics::compareUsembersReceivedEmails(Usember* usember1, Usember* usember2)
{
    if(usember1->receiveMailCount()>=usember2->receiveMailCount())
        return true;
    else
        return false;
}
