#include "Database.h"


Database::Database()
{
}

Database::~Database()
{
}

bool Database::addEmail(Email* email)
{
    if(findEmail(email->getID())==-1)
    {
        emailVector.push_back(email);
        return true;
    }
    else
        return false;
}

bool Database::addGroup(Group* group)
{
    if(findGroup(group->getID())==-1)
    {
        groupVector.push_back(group);
        return true;
    }
    else
        return false;
}

bool Database::addUsember(Usember* usember)
{
    if(findUsember(usember->getAddress())==-1)
    {
        usemberVector.push_back(usember);
        return true;
    }
    else
        return false;
}

void Database::deleteEmail(Email* email)
{
    int position=findEmail(email->getID());
    if(position!=-1)
        swapEmails(position, emailVector.size()-1);
    emailVector.pop_back();
}

void Database::deleteGroup(Group* group)
{
    int position=findGroup(group->getID());
    if(position!=-1)
        swapGroups(position, groupVector.size()-1);
    groupVector.pop_back();
}

void Database::deleteUsember(Usember* usember)
{
    int position=findUsember(usember->getAddress());
    if(position!=-1)
        swapUsembers(position, usemberVector.size()-1);
    usemberVector.pop_back();
}

vector<Email*>& Database::select(EmailQuery& emailQuery)
{
}

vector<Group*>& Database::select(GroupQuery& groupQuery)
{
}

vector<Usember*>& Database::select(UsemberQuery& usemberQuery)
{
}

void Database::deleteQueryResults(Query* query)
{
    if(query!=nullptr)
    {
        query->clear();
        delete query;
    }
}

void Database::sortEmails()
{
    int exchangeCounter;
    do
    {
        exchangeCounter=0;
        for(int i=0; i<emailVector.size()-1; ++i)
        {
            if(emailVector[i]->getID()>emailVector[i+1]->getID())
            {
                swapEmails(i, i+1);
                ++exchangeCounter;
            }
        }
    }
    while(exchangeCounter>0);
}

void Database::sortGroups()
{
    int exchangeCounter;
    do
    {
        exchangeCounter=0;
        for(int i=0; i<groupVector.size()-1; ++i)
        {
            if(groupVector[i]->getID()>groupVector[i+1]->getID())
            {
                swapGroups(i, i+1);
                ++exchangeCounter;
            }
        }
    }
    while(exchangeCounter>0);
}

void Database::sortUsembers()
{
    int exchangeCounter;
    do
    {
        exchangeCounter=0;
        for(int i=0; i<usemberVector.size()-1; ++i)
            if(usemberVector[i]->getAddress().compare(usemberVector[i+1]->getAddress())>0)
            {
                swapUsembers(i, i+1);
                ++exchangeCounter;
            }
    }
    while(exchangeCounter>0);
}

int Database::countEmails()
{
    return emailVector.size();
}

int Database::countGroups()
{
    return groupVector.size();
}

int Database::countUsembers()
{
    return usemberVector.size();
}

int Database::findEmail(int messageId)
{
    int position=emailVector.size();
    int range=emailVector.size()/2;
    while(range>=1)
    {
        position/=2;
        range/=2;
        if(messageId==emailVector[position]->getID())
            return position;
        if(messageId>emailVector[position]->getID())
            position+=range;
        else
            position-=range;
    }
    if(emailVector[position]->getID()==messageId)
        return position;
    else
        return -1;
}

int Database::findGroup(int groupId)
{
    int position=groupVector.size();
    int range=groupVector.size()/2;
    while(range>=1)
    {
        position/=2;
        range/=2;
        if(groupId==groupVector[position]->getID())
            return position;
        if(groupId>groupVector[position]->getID())
            position+=range;
        else
            position-=range;
    }
    if(groupVector[position]->getID()==groupId)
        return position;
    else
        return -1;
}

int Database::findUsember(string name)
{
    int position=usemberVector.size();
    int range=usemberVector.size()/2;
    while(range>=1)
    {
        position/=2;
        range/=2;
        if(name.compare(usemberVector[position]->getAddress())==0)
            return position;
        if(name.compare(usemberVector[position]->getAddress())>0)
            position+=range;
        else
            position-=range;
    }
    if(name.compare(usemberVector[position]->getAddress())==0)
        return position;
    else
        return -1;
}

void Database::clearEmails()
{
    emailVector.clear();

}

void Database::clearGroups()
{
    groupVector.clear();

}

void Database::clearUsembers()
{
    usemberVector.clear();

}

void Database::swapEmails(int position1, int position2)
{
    if(position1>=emailVector.size() || position2>=emailVector.size() || position1<0 || position2<0)
        return;
    Email* temp = emailVector[position1];
    emailVector[position1]=emailVector[position2];
    emailVector[position2]=temp;
}

void Database::swapGroups(int position1, int position2)
{
    if(position1>=groupVector.size() || position2>=groupVector.size() || position1<0 || position2<0)
        return;
    Group* temp = groupVector[position1];
    groupVector[position1]=groupVector[position2];
    groupVector[position2]=temp;
}

void Database::swapUsembers(int position1, int position2)
{
    if(position1>=usemberVector.size() || position2>=usemberVector.size() || position1<0 || position2<0)
        return;
    Usember* temp = usemberVector[position1];
    usemberVector[position1]=usemberVector[position2];
    usemberVector[position2]=temp;
}

Email* Database::getEmail(int position)
{
    if(position<0 || position>=emailVector.size())
        return nullptr;
    else
        return emailVector[position];
}

Group* Database::getGroup(int position)
{
    if(position<0 || position>=groupVector.size())
        return nullptr;
    else
        return groupVector[position];
}

Usember* Database::getUsember(int position)
{
    if(position<0 || position>=usemberVector.size())
        return nullptr;
    else
        return usemberVector[position];
}
