#pragma once
#include <boost/serialization/base_object.hpp>
#include "Usember.h"
#include <vector>

using namespace std;
class Usember;

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

public:
    Group();
	~Group();
	void addUsember(Usember* usember);
	void addIndex(int index);
	int getID();
	void setLeader(Usember* usember);
	void setLeaderIndex(int index);

	int getUsemberCount();
	int getIndexOf(int usember);
	Usember* getLeader();
	int getLeaderIndex();
	Usember* getUsember();
	Group* getHigherGroup();
	int getHigherGroupID();
};
