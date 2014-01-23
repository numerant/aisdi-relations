#include "Database.h"

Database::Database()
{
}

Database::~Database()
{
    for(int i=0; i<(int)emailVector.size(); ++i)
        delete emailVector[i];
    for(int i=0; i<(int)groupVector.size(); ++i)
        delete groupVector[i];
    for(int i=0; i<(int)usemberVector.size(); ++i)
        delete usemberVector[i];
    emailVector.clear();
    groupVector.clear();
    usemberVector.clear();
    emailSearchResultVector.clear();
    usemberSearchResultVector.clear();
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
    delete emailVector[position];
    if(position!=-1)
        swapEmails(position, emailVector.size()-1);
    emailVector.pop_back();
    sort (emailVector.begin(), emailVector.end(), Database::compareEmails);
}

void Database::deleteGroup(Group* group)
{
    int position=findGroup(group->getID());
    delete groupVector[position];
    if(position!=-1)
        swapGroups(position, groupVector.size()-1);
    groupVector.pop_back();
    sort (groupVector.begin(), groupVector.end(), Database::compareGroups);
}

void Database::deleteUsember(Usember* usember)
{
    int position=findUsember(usember->getAddress());
    delete usemberVector[position];
    if(position!=-1)
        swapUsembers(position, usemberVector.size()-1);
    usemberVector.pop_back();
    sort (usemberVector.begin(), usemberVector.end(), Database::compareUsembers);
}

void Database::simpleSelect(string phrase)
{
    emailSearchResultVector.clear();
    for(int i=0; i<(int)emailVector.size(); ++i)
        if(emailVector[i]->getSubject().find(phrase)!=string::npos || emailVector[i]->getContent().find(phrase)!=string::npos)
            emailSearchResultVector.push_back(emailVector[i]);
}

void Database::select(EmailQuery& emailQuery)
{
    bool match;
    emailSearchResultVector.clear();
    for(int i=0; i<(int)emailVector.size(); ++i)
    {
        match=true;
        if(emailQuery.searchingForReplies() && findEmail(emailVector[i]->getInReplyTo())==-1)
            match=false;
        if(emailQuery.searchingForForwards() && emailVector[i]->getIsForwarded())
            match=false;
        if(emailQuery.getStringCriteriaVectorSize()>0)
        {
            match=true;
            for(unsigned int j=0; j<emailQuery.getStringCriteriaVectorSize(); ++j)
            {
                if(!matches(*emailVector[i], *emailQuery.getStringCriteria(j)))
                {
                    match=false;
                    break;
                }
            }
        }

        if(match && emailQuery.getDateCriteriaVectorSize()>0)
        {
            for(unsigned int j=0; j<emailQuery.getDateCriteriaVectorSize(); ++j)
            {
               if(!matches(*emailVector[i], *emailQuery.getDateCriteria(j)))
               {
                   match=false;
                   break;
               }
            }
        }
        if(match)
            emailSearchResultVector.push_back(emailVector[i]);
    }
}

void Database::select(UsemberQuery& usemberQuery)
{
    bool match=true;;
    usemberSearchResultVector.clear();
    for(int i=0; i<(int)usemberVector.size(); ++i)
    {
        if(usemberQuery.getStringCriteriaVectorSize()>0)
        {
            match=true;
            for(unsigned int j=0; j<usemberQuery.getStringCriteriaVectorSize(); ++j)
            {
                if(!matches(*usemberVector[i], *usemberQuery.getStringCriteria(j)))
                {
                    match=false;
                    break;
                }
            }
        }
        if(match)
            usemberSearchResultVector.push_back(usemberVector[i]);
    }
}

void Database::deleteQueryResults(Query* query)
{
    if(query!=nullptr)
    {
        query->clear();
        delete query;
    }
}

int Database::findEmail(string messageId)
{
	int low = 0, high = emailVector.size()-1, midpoint = 0;
	while (low <= high)
	{
		midpoint = (high + low)/2;
		if(messageId.compare(emailVector[midpoint]->getID())==0)
            return midpoint;
		else if (messageId.compare(emailVector[midpoint]->getID())<0)
			high = midpoint - 1;
		else
			low = midpoint + 1;
	}
	return -1;
}

int Database::findGroup(int groupId)
{
 	int low = 0, high = groupVector.size()-1, midpoint = 0;
	while (low <= high)
	{
		midpoint = (high + low)/2;
		if(groupId==groupVector[midpoint]->getID())
            return midpoint;
		else if (groupId<groupVector[midpoint]->getID())
			high = midpoint - 1;
		else
			low = midpoint + 1;
	}
	return -1;
}

int Database::findUsember(string name)
{
 	int low = 0, high = usemberVector.size()-1, midpoint = 0;
	while (low <= high)
	{
		midpoint = (high + low)/2;
		if(name.compare(usemberVector[midpoint]->getAddress())==0)
            return midpoint;
		else if (name.compare(usemberVector[midpoint]->getAddress())<0)
			high = midpoint - 1;
		else
			low = midpoint + 1;
	}
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

bool Database::matches(Email& email, StringCriteria& stringCriteria)
{
    switch(stringCriteria.getSearchKey()){
    case E_EMAIL:
        if(email.getFrom()->getAddress().find(stringCriteria.getName())!=string::npos || email.getTo()->getAddress().find(stringCriteria.getName())!=string::npos)
            return true;
        return false;
    case E_SUBJECT:
        if(email.getSubject().find(stringCriteria.getName())!=string::npos)
            return true;
        return false;
    case E_CONTENT:
        if(email.getContent().find(stringCriteria.getName())!=string::npos)
            return true;
        return false;
    default:
        return false;
    }
}

bool Database::matches(Email& email, DateCriteria& dateCriteria)
{
    if(dateCriteria.getEquals()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getEquals())==0)      //mozna zrobic w Date wersje compare porownujaca tylko lata, miesiace i dni i dac ja tutaj
            return true;
        else
            return false;
    }
    if(dateCriteria.getLess()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getLess())<0)
            return false;
    }
    if(dateCriteria.getGreater()!=nullptr){
        if(email.getDate().compare(*dateCriteria.getGreater())>0)
            return false;
    }
    return true;
}

bool Database::matches(Usember& usember, StringCriteria& stringCriteria)
{
    if(usember.getAddress().find(stringCriteria.getName())!=string::npos)
        return true;
    return false;
}

void Database::swapEmails(int position1, int position2)
{
    if(position1>= (int)emailVector.size() || position2>= (int)emailVector.size() || position1<0 || position2<0)
        return;
    Email* temp = emailVector[position1];
    emailVector[position1]=emailVector[position2];
    emailVector[position2]=temp;
}

void Database::swapGroups(int position1, int position2)
{
    if(position1>= (int)groupVector.size() || position2>= (int)groupVector.size() || position1<0 || position2<0)
        return;
    Group* temp = groupVector[position1];
    groupVector[position1]=groupVector[position2];
    groupVector[position2]=temp;
}

void Database::swapUsembers(int position1, int position2)
{
    if(position1>= (int)usemberVector.size() || position2>= (int)usemberVector.size() || position1<0 || position2<0)
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
    if(group1->getID()<=group2->getID())
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

int Database::countResultEmails()
{
    return emailSearchResultVector.size();
}

int Database::countResultUsembers()
{
    return usemberSearchResultVector.size();
}

Email* Database::getEmail(int position)
{
    if(position<0 || position>=(int)emailVector.size())
        return nullptr;
    else
        return emailVector[position];
}

Group* Database::getGroup(int position)
{
    if(position<0 || position>=(int)groupVector.size())
        return nullptr;
    else
        return groupVector[position];
}

Usember* Database::getUsember(int position)
{
    if(position<0 || position>=(int)usemberVector.size())
        return nullptr;
    else
        return usemberVector[position];
}

Email* Database::getResultEmail(int position)
{
    if(position<0 || position>=(int)emailSearchResultVector.size())
        return nullptr;
    else
        return emailSearchResultVector[position];
}

Usember* Database::getResultUsember(int position)
{
     if(position<0 || position>=(int)usemberSearchResultVector.size())
        return nullptr;
    else
        return usemberSearchResultVector[position];
}

string Database::getAutoImportPath()
{
    return autoImportPath;
}

void Database::setAutoImportPath(string path)
{
    autoImportPath = path;
}
