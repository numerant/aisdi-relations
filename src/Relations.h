#pragma once
#include <vector>
#include <algorithm>
#include "Database.h"
#include "Group.h"

using namespace std;

class Relations {
public:
	Relations(Database *existingDatabase);
	virtual ~Relations();

	int findRepresentantOf(int element);
	void runAlgorithm();
	void setClosestAssociates();
	void countBossCoefficient();
	void setGroups();
	void addGroup(int representant);		//not FINAL!
	void findBosses();
	void goToAnotherDimension();
	void makeGroups();
	void saveGroupsInDatabase();
	int getFinalGroupsSize();
	Group* getGroup(int i);
	vector<pair<int, int> > countStandardDeviation(vector<pair<int, int> > vect);

private:
	static const int MAX_EMAILS = 10000;
	Database *database;
	int firstUserCount;
	int userCount;
	static int level;
	vector< pair<int, int> > adjacents[MAX_EMAILS];
	vector< pair<int, int> > closestAssociate;
	vector<int> realIndex;	//prawdziwy index użytkownika w bazie
	vector<int> tmpIndex;	//tymczasowy index
	vector<int> vertexDegree;
	vector<int> otherGroupEmails;
	vector<int> bossCoefficient;
	vector<pair<int, int> > finalBosses;	//first: index ; second: group
	vector<int> representant;
	vector<int> groups;
	vector<Group*> finalGroups;
};
