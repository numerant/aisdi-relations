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

bool Query::searchingForReplies()
{
    return replies;
}

bool Query::searchingForForwards()
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

EmailQuery::EmailQuery()
{

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
