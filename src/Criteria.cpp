#include "Criteria.h"

SearchKey Criteria::getSearchKey()
{
    return searchKey;
}

IntCriteria::IntCriteria()
{

}

IntCriteria::~IntCriteria()
{

}

StringCriteria::StringCriteria()
{

}

StringCriteria::~StringCriteria()
{

}

DateCriteria::DateCriteria()
{

}

DateCriteria::~DateCriteria()
{

}

int IntCriteria::getEquals()
{
    return equals;
}

int IntCriteria::getLess()
{
    return less;
}

int IntCriteria::getGreater()
{
    return greater;
}

string StringCriteria::getName()
{
    return name;
}

Date* DateCriteria::getEquals()
{
    if(equals.getDay()==0 && equals.monthToInt(equals.getMonth())==0 && equals.getYear()==0)
        return nullptr;
    return &equals;
}

Date* DateCriteria::getLess()
{
    if(less.getDay()==0 && less.monthToInt(equals.getMonth())==0 && less.getYear()==0)
        return nullptr;
    return &less;
}

Date* DateCriteria::getGreater()
{
    if(greater.getDay()==0 && greater.monthToInt(equals.getMonth())==0 && greater.getYear()==0)
        return nullptr;
    return &greater;
}
