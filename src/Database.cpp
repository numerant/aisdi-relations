#include "Database.h"


Database::Database()
{
}


Database::~Database()
{
}

bool Database::addEmail(Email* email)
{
	if(findEmail(email->getID())==-1)
		emailVector.push_back(email);
}

bool Database::addWorkgroup(Workgroup* workgroup)
{
	if(findWorkgroup(workgroup->getID())==-1)
		workgroupVector.push_back(workgroup);
}

bool Database::addUsember(Usember* usember)
{
	if(findUsember(usember->getAddress())==-1)
		usemberVector.push_back(usember);
}

void Database::deleteEmail(Email* email)
{
	int position=findEmail(email->getID());
	if(position!=-1)
		swapEmails(position, emailVector.size()-1);
	emailVector.pop_back();
}

void Database::deleteWorkgroup(Workgroup* workgroup)
{
	int position=findWorkgroup(workgroup->getID());
	if(position!=-1)
		swapWorkgroups(position, workgroupVector.size()-1);
	workgroupVector.pop_back();
}

void Database::deleteUsember(Usember* usember)
{
	int position=findUsember(usember->getAddress());
	if(position!=-1)
		swapUsembers(position, usemberVector.size()-1);
	usemberVector.pop_back();
}

vector<Email*>& Database::select(EmailQuery& emailQuery)
{
}

vector<Workgroup*>& Database::select(WorkgroupQuery& workgroupQuery)
{
}

vector<Usember*>& Database::select(UsemberQuery& usemberQuery)
{
}

void Database::deleteQueryResults(Query& query)
{
}

void Database::sortEmails()
{
	int exchangeCounter;
	do{
		exchangeCounter=0;
		for(int i=0; i<emailVector.size()-1; ++i){
			if(emailVector[i]->getID()>emailVector[i+1]->getID()){
				swapEmails(i, i+1);
				++exchangeCounter;
			}
		}
	}while(exchangeCounter>0);
}

void Database::sortWorkgroups()
{
	int exchangeCounter;
	do{
		exchangeCounter=0;
		for(int i=0; i<workgroupVector.size()-1; ++i){
			if(workgroupVector[i]->getID()>workgroupVector[i+1]->getID()){
				swapWorkgroups(i, i+1);
				++exchangeCounter;
			}
		}
	}while(exchangeCounter>0);
}

void Database::sortUsembers()
{
	int exchangeCounter;
	do{
		exchangeCounter=0;
		for(int i=0; i<usemberVector.size()-1; ++i)
			if(compareStrings(usemberVector[i]->getAddress(), usemberVector[i+1]->getAddress(), 0)==1){
				swapUsembers(i, i+1);
				++exchangeCounter;
			}
	}while(exchangeCounter>0);
}

int Database::countEmails()
{
	return emailVector.size();
}

int Database::countWorkgroups()
{
	return workgroupVector.size();
}

int Database::countUsembers()
{
	return usemberVector.size();
}

int Database::findEmail(int messageId)
{
	int position=emailVector.size();
	int range=emailVector.size()/2;
	while(range>=1){
		position/=2;
		range/=2;
		if(messageId==emailVector[position]->getID())
			return position;
		if(messageId>emailVector[position]->getID())
			position+=range;
		else
			position-=range;
	}
	if(emailVector[position]->getID()==messageId)
		return position;
	else
		return -1;
}

int Database::findWorkgroup(int groupId)
{
	int position=workgroupVector.size();
	int range=workgroupVector.size()/2;
	while(range>=1){
		position/=2;
		range/=2;
		if(groupId==workgroupVector[position]->getID())
			return position;
		if(groupId>workgroupVector[position]->getID())
			position+=range;
		else
			position-=range;
	}
	if(workgroupVector[position]->getID()==groupId)
		return position;
	else
		return -1;
}

int Database::findUsember(string name)
{
	int position=usemberVector.size();
	int range=usemberVector.size()/2;
	while(range>=1){
		position/=2;
		range/=2;
		if(compareStrings(name, usemberVector[position]->getAddress(), 0)==0)
			return position;
		if(compareStrings(name, usemberVector[position]->getAddress(), 0)==1)
			position+=range;
		else
			position-=range;
	}
	if(compareStrings(name, usemberVector[position]->getAddress(), 0)==0)
		return position;
	else
		return -1;
}

void Database::clearEmails()
{
	emailVector.clear();

}

void Database::clearWorkgroups()
{
	workgroupVector.clear();

}

void Database::clearUsembers()
{
	usemberVector.clear();

}

int Database::compareStrings(string string1, string string2, int position)
{
	if(string1[position]<string2[position])
		return -1;
	else if(string1[position]>string2[position])
		return 1;
	else
		return compareStrings(string1, string2, position+1);
}

void Database::swapEmails(int position1, int position2)
{
	if(position1>=emailVector.size() || position2>=emailVector.size() || position1<0 || position2<0)
		return;
	Email* temp = emailVector[position1];
	emailVector[position1]=emailVector[position2];
	emailVector[position2]=temp;
}

void Database::swapWorkgroups(int position1, int position2)
{
	if(position1>=workgroupVector.size() || position2>=workgroupVector.size() || position1<0 || position2<0)
		return;
	Workgroup* temp = workgroupVector[position1];
	workgroupVector[position1]=workgroupVector[position2];
	workgroupVector[position2]=temp;
}

void Database::swapUsembers(int position1, int position2)
{
	if(position1>=usemberVector.size() || position2>=usemberVector.size() || position1<0 || position2<0)
		return;
	Usember* temp = usemberVector[position1];
	usemberVector[position1]=usemberVector[position2];
	usemberVector[position2]=temp;
}
