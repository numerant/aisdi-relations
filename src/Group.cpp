#include "Group.h"

unsigned long long Group::globalId = 0;

int Group::getID()
{
    return id;
}

Group::Group()
{
    color = 0;
	id = globalId;
	globalId++;
}

Group::~Group()
{
}

void Group::addUsember(Usember* usember)
{
	usembers.push_back(usember);

}

void Group::addIndex(int index)
{
	indexes.push_back(index);
}

void Group::setLeader(Usember* usember)
{
	leader = usember;
}

void Group::setLeaderIndex(int index)
{
	leaderIndex = index;
}

void Group::setLevel(int newLevel)
{
    level = newLevel;
}

int Group::getEmailsCount(Database *database)
{
    int sum = 0;
    for(int i = 0; i < getUsemberCount(); i++)
    {
        for(int j = i+1; j < getUsemberCount(); j++)
        {
            sum+= getUsember(i)->getEmailsCount(database, getIndexOf(j));
        }
    }

    return sum;
}

int Group::getUsemberCount()
{
	return usembers.size();
}

int Group::getIndexOf(int usember)
{
	return indexes[usember];
}

Usember* Group::getLeader()
{
	return leader;
}

Usember* Group::getUsember(int i)
{
    return usembers[i];
}

int Group::getLeaderIndex()
{
	return leaderIndex;
}

int Group::getLevel()
{
    return level;
}
