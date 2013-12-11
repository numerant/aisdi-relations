#pragma once
#include "Query.h"
#include "Email.h"

class EmailQuery :
    public Query
{
private:
    vector<Email*> searchResultVector;
public:
    EmailQuery();
    ~EmailQuery();
};
