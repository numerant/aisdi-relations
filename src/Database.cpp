#include "Database.h"

Database::Database()
{
}

Database::~Database()
{
}

bool Database::addEmail(Email* email)
{
    if(emailVector.size()==0)
    {
        emailVector.push_back(email);
        return true;
    }
    if(findEmail(email->getID())==-1)
    {
        emailVector.push_back(email);
        sort (emailVector.begin(), emailVector.end(), Database::compareEmails);
        return true;
    }
    else
        return false;
}

bool Database::addGroup(Group* group)
{
    if(groupVector.size()==0)
    {
        groupVector.push_back(group);
        return true;
    }
    if(findGroup(group->getID()) == -1)
    {
        groupVector.push_back(group);
        sort (groupVector.begin(), groupVector.end(), Database::compareGroups);
        return true;
    }
    else
        return false;
}

bool Database::addUsember(Usember* usember)
{
    if(usemberVector.size()==0)
    {
        usemberVector.push_back(usember);
        return true;
    }
    if(findUsember(usember->getAddress())==-1)
    {
        usemberVector.push_back(usember);
        sort (usemberVector.begin(), usemberVector.end(), Database::compareUsembers);
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
    sort (emailVector.begin(), emailVector.end(), Database::compareEmails);
}

void Database::deleteGroup(Group* group)
{
    int position=findGroup(group->getID());
    if(position!=-1)
        swapGroups(position, groupVector.size()-1);
    groupVector.pop_back();
    sort (groupVector.begin(), groupVector.end(), Database::compareGroups);
}

void Database::deleteUsember(Usember* usember)
{
    int position=findUsember(usember->getAddress());
    if(position!=-1)
        swapUsembers(position, usemberVector.size()-1);
    usemberVector.pop_back();
    sort (usemberVector.begin(), usemberVector.end(), Database::compareUsembers);
}

vector<Email*>& Database::select(EmailQuery& emailQuery)
{
    for(int i=0; i<emailVector.size(); ++i){
        if(emailQuery.getIntCriteriaVectorSize()>0){
            //for(int j=0; i<emailQuery.getIntCriteriaVectorSize(); ++j){
            //   ;
            //}
        }
        if(emailQuery.getStringCriteriaVectorSize()>0){
           for(int j=0; i<emailQuery.getStringCriteriaVectorSize(); ++j){
               if(matches(*emailVector[j], *emailQuery.getStringCriteria(j)))
                  emailSearchResultVector.push_back(emailVector[j]);
           }
        }
        if(emailQuery.getDateCriteriaVectorSize()>0){
           for(int j=0; i<emailQuery.getDateCriteriaVectorSize(); ++j){
               if(matches(*emailVector[j], *emailQuery.getDateCriteria(j)))
                  emailSearchResultVector.push_back(emailVector[j]);
           }
        }
    }
    if(emailSearchResultVector.size()>1)
        sort(emailSearchResultVector.begin(), emailSearchResultVector.end());
    return emailSearchResultVector;
}

vector<Group*>& Database::select(GroupQuery& groupQuery)
{
    return groupSearchResultVector;
}

vector<Usember*>& Database::select(UsemberQuery& usemberQuery)
{
    return usemberSearchResultVector;
}

void Database::deleteQueryResults(Query* query)
{
    emailSearchResultVector.clear();
    groupSearchResultVector.clear();
    usemberSearchResultVector.clear();
    if(query!=nullptr)
    {
        query->clear();
        delete query;
    }
}

int Database::findEmail(string messageId)
{
    if(emailVector.size()==0)
        return -1;
    int position=emailVector.size()/2;
    int range=emailVector.size()/2;
    while(range>=1)
    {
        range/=2;
        if(messageId.compare(emailVector[position]->getID())==0)
            return position;
        if(messageId.compare(emailVector[position]->getID())>0)
            position+=range;
        else
            position-=range;
    }
    if(messageId.compare(emailVector[position]->getID())==0)
        return position;
    else if(position+1<emailVector.size() && messageId.compare(emailVector[position+1]->getID())==0)
        return position+1;
    else if(position>0 && messageId.compare(emailVector[position-1]->getID())==0)
        return position-1;
    else
        return -1;
}

int Database::findGroup(string groupId)
{
    if(groupVector.size()==0)
        return -1;
    int position=groupVector.size()/2;
    int range=groupVector.size()/2;
    while(range>=1)
    {
        range/=2;
        if(groupId.compare(groupVector[position]->getID())==0)
            return position;
        if(groupId.compare(groupVector[position]->getID())>0)
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
    if(usemberVector.size()==0)
        return -1;
    int position=usemberVector.size()/2;
    int range=usemberVector.size()/2;
    while(range>=1)
    {
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
/*
void insertAddedEmail()
{
    if(EmailVector.size()==0)
        return;
    Email* temp = EmailVector[EmailVector.size()-1];
    for(i=EmailVector.size()-1; i>0; --i)
    {
        if(compareEmails(temp, EmailVector[i-1]<0))
            EmailVector[i]=EmailVector[i-1];

    }
}*/

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

bool Database::matches(Email& email, IntCriteria& intCriteria)
{
    return false;
}

bool Database::matches(Email& email, StringCriteria& stringCriteria)
{
    switch(stringCriteria.getSearchKey()){
    case E_FROM:
        if(email.getFrom()->getAddress()==stringCriteria.getName())
            return true;
        return false;
    case E_REPLY_TO:
        if(email.getReplyTo()->getID()==stringCriteria.getName())
            return true;
        return false;
    case E_TO:
        if(email.getTo()->getAddress()==stringCriteria.getName())
            return true;
        return false;
    case E_ID:
         if(email.getID()==stringCriteria.getName())
            return true;
        return false;
    case E_SUBJECT:
        if(email.getSubject()==stringCriteria.getName())
            return true;
        return false;
    default:
        return false;
    }
}

bool Database::matches(Email& email, DateCriteria& dateCriteria)
{
    if(dateCriteria.getEquals()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getEquals())==0)
            return true;
        else
            return false;
    }
    if(dateCriteria.getLess()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getLess())>=0)
            return false;
    }
    if(dateCriteria.getGreater()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getGreater())<=0)
            return false;
    }
    return true;
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

bool Database::compareEmails(Email* email1, Email* email2)
{
    if(email1->getID().compare(email2->getID())<=0)
        return true;
    else
        return false;
}

bool Database::compareGroups(Group* group1, Group* group2)
{
    if(group1->getID().compare(group2->getID())<=0)
        return true;
    else
        return false;
}
bool Database::compareUsembers(Usember* usember1, Usember* usember2)
{
    if(usember1->getAddress().compare(usember2->getAddress())<=0)
        return true;
    else
        return false;
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
