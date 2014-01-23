#pragma once
#include <boost/serialization/base_object.hpp>
#include "Usember.h"
#include "Database.h"
#include <string>
#include <vector>

using namespace std;
class Usember;
class Database;

class Group
{
    friend class boost::serialization::access;  //potrzebne do serializacji
private:
    static unsigned long long globalId;
	unsigned int id;
	vector <Usember*> usembers;
	vector <int> indexes;
	Usember* leader;
	int leaderIndex;
	int level;
	string name;

public:
    Group();
	~Group();
	void addUsember(Usember* usember);
	void addIndex(int index);
	int getID();
	void setLeader(Usember* usember);
	void setLeaderIndex(int index);
	void setLevel(int newLevel);
	int color;

	int getUsemberCount();
	string getName();
	int getEmailsCount(Database *database);
	int getIndexOf(int usember);
	Usember* getLeader();
	int getLeaderIndex();
	int getLevel();
	Usember* getUsember(int i);
	Group* getHigherGroup();
	int getHigherGroupID();
};
