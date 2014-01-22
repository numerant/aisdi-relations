#include "Criteria.h"

StringCriteria::StringCriteria(SearchKey searchKey, string name)
{
    this->searchKey=searchKey;
    this->name=name;
}

StringCriteria::~StringCriteria()
{

}

DateCriteria::DateCriteria(Date equals, Date less, Date greater)
{
    this->equals=equals;
    this->less=less;
    this->greater=greater;
}

DateCriteria::~DateCriteria()
{

}

string StringCriteria::getName()
{
    return name;
}

SearchKey StringCriteria::getSearchKey()
{
    return searchKey;
}

Date* DateCriteria::getEquals()
{
    if(equals.getDay()==0 && equals.getYear()==0)
        return nullptr;
    return &equals;
}

Date* DateCriteria::getLess()
{
    if(less.getDay()==0 && less.getYear()==0)
        return nullptr;
    return &less;
}

Date* DateCriteria::getGreater()
{
    if(greater.getDay()==0 && greater.getYear()==0)
        return nullptr;
    return &greater;
}
