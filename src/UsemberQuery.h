#pragma once
#include "Query.h"

//enum DataType {NAME, EMAIL_ADDRESS, GROUP_DOMAIN, GROUP};

class UsemberQuery :
    public Query
{
private:
    vector<Usember*> searchResultVector;
public:
    UsemberQuery();
    ~UsemberQuery();
};

