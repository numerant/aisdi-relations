#include "Group.h"

unsigned long long Group::globalId = 0;

int Group::getID()
{
    return id;
}

Group::Group()
{
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

int Group::getLeaderIndex()
{
	return leaderIndex;
}