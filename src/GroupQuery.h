#pragma once
#include "Query.h"
#include "Group.h"

//enum DataType {USEMBER, USEMBERS_NUMBER};

class GroupQuery :
    public Query
{
private:
    vector<Group*> searchResultVector;
public:
    GroupQuery();
    ~GroupQuery();
};

