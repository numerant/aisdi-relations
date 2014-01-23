#include "Query.h"

Query::Query()
{

}

Query::~Query()
{

}

void Query::clear()
{

}

bool EmailQuery::searchingForReplies()
{
    return replies;
}

bool EmailQuery::searchingForForwards()
{
    return forwards;
}

StringCriteria* Query::getStringCriteria(int position)
{
    if(position>=0 && position< (int)stringCriteriaVector.size())
        return &stringCriteriaVector[position];
    return nullptr;
}

DateCriteria* Query::getDateCriteria(int position)
{
     if(position>=0 && position< (int)dateCriteriaVector.size())
        return &dateCriteriaVector[position];
    return nullptr;
}

int Query::getStringCriteriaVectorSize()
{
    return stringCriteriaVector.size();
}

int Query::getDateCriteriaVectorSize()
{
    return dateCriteriaVector.size();
}

void Query::addStringCriteria(StringCriteria stringCriteria)
{
    stringCriteriaVector.push_back(stringCriteria);
}

void Query::addDateCriteria(DateCriteria dateCriteria)
{
    dateCriteriaVector.push_back(dateCriteria);
}


EmailQuery::EmailQuery(bool replies, bool forwards)
{
    this->replies=replies;
    this->forwards=forwards;
}

EmailQuery::~EmailQuery()
{

}

UsemberQuery::UsemberQuery()
{

}

UsemberQuery::~UsemberQuery()
{

}

void EmailQuery::clear()
{
    stringCriteriaVector.clear();
    dateCriteriaVector.clear();
}

void UsemberQuery::clear()
{
    stringCriteriaVector.clear();
    dateCriteriaVector.clear();
}
