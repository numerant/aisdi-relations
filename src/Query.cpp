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

IntCriteria* Query::getIntCriteria(int position)
{
    if(position>=0 && position< (int)intCriteriaVector.size())
        return &intCriteriaVector[position];
    return nullptr;
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

int Query::getIntCriteriaVectorSize()
{
    return intCriteriaVector.size();
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

GroupQuery::GroupQuery()
{

}

GroupQuery::~GroupQuery()
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
    sortingOrder.clear();
    intCriteriaVector.clear();
    stringCriteriaVector.clear();
    dateCriteriaVector.clear();
}

void GroupQuery::clear()
{
    sortingOrder.clear();
    intCriteriaVector.clear();
    stringCriteriaVector.clear();
    dateCriteriaVector.clear();
}

void UsemberQuery::clear()
{
    sortingOrder.clear();
    intCriteriaVector.clear();
    stringCriteriaVector.clear();
    dateCriteriaVector.clear();
}
