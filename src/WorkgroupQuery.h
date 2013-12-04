#pragma once
#include "query.h"

enum DataType {USEMBER, USEMBERS_NUMBER};

class WorkgroupQuery :
	public Query
{
private:
	vector<Workgroup*> searchResultVector;
public:
	WorkgroupQuery();
	~WorkgroupQuery();
};

