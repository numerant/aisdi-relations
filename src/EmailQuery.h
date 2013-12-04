#pragma once
#include "query.h"

enum DataType {FROM, DATE, REPLY_TO, IN_REPLY_TO, MESSAGE_ID, TO, SUBJECT};

class EmailQuery :
	public Query
{
private:
	vector<Email*> searchResultVector;
public:
	EmailQuery();
	~EmailQuery();
};
