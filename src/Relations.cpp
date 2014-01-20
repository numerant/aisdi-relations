#include "Relations.h"


Relations::Relations(Database *existingDatabase)
{
	database = existingDatabase;
	userCount = database->countUsembers();
	firstUserCount  = userCount;
	Usember *tempUsember = database->getUsember(0);

	for( int i = 0; i < userCount; i++)
	{
		vertexDegree.push_back(0);
		otherGroupEmails.push_back(0);
		bossCoefficient.push_back(0);
	}

	for( int i = 0; i < userCount; i++)
	{
		tempUsember = database->getUsember(i);
		realIndex.push_back(i);
		tmpIndex.push_back(i);
		for(int j = i+1; j < userCount; j++)
		{
			unsigned int emailsCount = tempUsember->getEmailsCount(database, j);
			if(emailsCount)
			{
				adjacents[i].push_back(make_pair(j, emailsCount));
				adjacents[j].push_back(make_pair(i, emailsCount));
				vertexDegree[i]++;
				vertexDegree[j]++;
			}
		}

		//tempUsember = database->getUsember(i);
	}

	for(int i = 0; i < userCount; i++)
	{
		representant.push_back(i);
	}
}


Relations::~Relations(void)
{
}

int Relations::findRepresentantOf(int element)
{
	if (representant[element]==element) return element;
	int newRepresentant = findRepresentantOf(representant[element]);
	representant[element] = newRepresentant;
	return newRepresentant;
}

void Relations::runAlgorithm()
{
	while(true)
	{
		setClosestAssociates();
		countBossCoefficient();
		setGroups();
		findBosses();
		if(groups.size() > 1)
		{
			cout<<"GROUPS: "<<groups.size()<<endl<<endl;
			goToAnotherDimension();
		}
		else
		{
			makeGroups();
			break;
		}
	}

}

void Relations::setClosestAssociates()
{
	for(int i = 0; i < userCount; i++)
	{
		closestAssociate.push_back(make_pair(i, 0));
		for(unsigned int j = 0; j < adjacents[i].size(); j++)
		{
			if(closestAssociate[i].second < adjacents[i][j].second)
				closestAssociate[i] = adjacents[i][j];
		}

		if(findRepresentantOf(tmpIndex[closestAssociate[i].first]) != i)
		{
			representant[i] = tmpIndex[closestAssociate[i].first];
		}

	}
}

void Relations::countBossCoefficient()
{
	for(int i = 0; i < userCount; i++)
	{
		for(unsigned int j = 0; j < adjacents[i].size(); j++)
		{
			//if(findRepresentantOf(i) != findRepresentantOf(j))
			if(representant[i] != representant[tmpIndex[adjacents[i][j].first]])
				otherGroupEmails[i]++;
		}

		bossCoefficient[i] = 4*vertexDegree[i] + otherGroupEmails[i];
	}
}

void Relations::setGroups()
{
	for(int i = 0; i < userCount; i ++)
	{
		addGroup(i);
	}
}

void Relations::addGroup(int representant)
{
	int representant2 = findRepresentantOf(representant);
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		if(representant2 == groups[i])
		{
			//cout<<realIndex[representant]<<" jest u "<<realIndex[groups[i]]<<endl;
			return;
		}
	}
	groups.push_back(representant2);
	//cout<<realIndex[representant]<<" jest u "<<realIndex[representant2]<<endl;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first < b.first)
		return true;
	else
		return false;
}

void Relations::findBosses()
{
	vector<pair<int, int> > bosses;			//first: coefficient, second: index
	int highest;
	//Dla ka�dej grupy
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		//szukamy cz�onk�w danej grupy (kt�rych reprezentant jest reprezentantem danej grupy)
		for(int j = 0; j < userCount; j++)
		{
			if(findRepresentantOf(j) == groups[i])
				bosses.push_back(make_pair(bossCoefficient[j], j));
		}
		sort(bosses.begin(), bosses.end(), cmp);

		//cz�onek z najwy�szym wsp�czynnikiem szefostwa
		highest = bosses[bosses.size()-1].first;

		int k = 1;
		vector<pair<int, int> > potential;
		potential.push_back(bosses[bosses.size()-1]);

		//szukamy potencjalnych szef�w
		int sajz = bosses.size();
		while((sajz-k-1) >= 0)
		{
			if(bosses[sajz-k-1].first * 2 > highest)
			{
				potential.push_back(bosses[sajz-k-1]);
				if(sajz-k-1 == 0)
					break;
			}
			k++;
		}

		vector<double> coefficient;
		int bossIndex = bosses[bosses.size()-1].second;
		double bossCoefficient = highest;

		if(potential.size() > 1)
		{
			vector<pair<int, int> > counts = countStandardDeviation(potential);

		//obliczamy ich wsp�czynnik dodatkowy
			for(unsigned int j = 0; j < potential.size(); j ++)
			{
				double tmpCoefficient;

				tmpCoefficient = 2 * counts[j].first + potential[j].first;

				coefficient.push_back(tmpCoefficient);
			}

			//szukamy u�ytkownika z najwy�szym wsp�czynnikiem dodatkowym
			for(unsigned int j = 0; j < potential.size(); j ++)
			{
				if(coefficient[j] > bossCoefficient)
					bossIndex = potential[j].second;
			}
			//MAMY BOSSA!
		}
		representant[groups[i]] = bossIndex;
		groups[i] = bossIndex;
		representant[bossIndex] = bossIndex;
		finalBosses.push_back(make_pair(bossIndex, groups[i]));

		//clear
		bosses.clear();
	}
}


vector<pair<int, int> > Relations::countStandardDeviation(vector<pair<int, int> > vect)
{
	vector<pair<int, int> > vertexGroups; //i-ty u�ytkownik ma (first) korespondent�w z innych grup i (second) wiadomo�ci z nimi
	for(unsigned int ii = 0; ii < vect.size(); ii++)
	{
		vertexGroups.push_back(make_pair(0,0));

		vector<int> groupsFound; // ju� znalezione grupy
		for(unsigned int i = 0 ; i < adjacents[vect[ii].second].size(); i++)
		{
			bool b = 0;
			int rep = findRepresentantOf(adjacents[vect[ii].second][i].first);
			if(rep == findRepresentantOf(vect[ii].second))
			{
				continue;
			}

			for(unsigned int j = 0; j < groupsFound.size(); j++)
			{
				if(rep == groupsFound[j])
					b=1;
			}

			if(b!=1){
				groupsFound.push_back(rep);
				vertexGroups[ii].first++;
			}
			else
				b=0;
			vertexGroups[ii].second+= adjacents[vect[ii].second][i].second;

		}
	}

	return vertexGroups;
}

void Relations::makeGroups()
{
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		Group *group = new Group();
		groups[i] = findRepresentantOf(groups[i]);

		group->setLeader(database->getUsember(realIndex[groups[i]]));
		group->setLeaderIndex(realIndex[groups[i]]);
		group->addUsember(group->getLeader());
		group->addIndex(realIndex[groups[i]]);

		for(int j = 0; j < userCount; j++)
		{
			//cout<<realIndex[j]<<" ma "<<realIndex[findRepresentantOf(j)]<<endl;
			if(realIndex[findRepresentantOf(j)] == group->getLeaderIndex() && j != findRepresentantOf(j))
			{
				group->addUsember(database->getUsember(realIndex[j]));
				group->addIndex(realIndex[j]);
			}
		}

		cout<<"Stworzono grupe!"<<endl<<"Lider: "<<group->getLeaderIndex()+1<<endl<<"Czlonkowie:"<<endl;
		cout<<endl;
		for(int i = 0; i < group->getUsemberCount(); i++)
		{
			cout<<"\tUzytkownik numer "<<group->getIndexOf(i)+1<<endl;
		}
		cout<<endl<<endl;
		finalGroups.push_back(group);
	}
}

void Relations::goToAnotherDimension()
{
	vector<pair<int, int> > tempAdj[MAX_EMAILS];
	vector<int> newRealIndex;

	makeGroups();

	//czy�cimy dla nowego poziomy
	for( int i = 0; i < userCount; i++)
		vertexDegree[i] = 0;

	tmpIndex.resize(firstUserCount,0);

	//Dla ka�dej grupy
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		Group *group = finalGroups[i];
		newRealIndex.push_back(realIndex[groups[i]]);

		//Dla ka�dego u�ytkownika z grupy
		for(int j = 0; j < group->getUsemberCount(); j++)
		{
			tmpIndex[group->getIndexOf(j)] = i;

			// Przegl�damy jego s�siad�w w celu okre�lenia wagi mi�dzy nowymi wierzcho�kami (grupami)
			for(unsigned int k = 0; k < adjacents[group->getIndexOf(j)].size(); k++)
			{
				bool isThere = 0;
				//Przeszukujemy ju� dodane nowe wierzcho�ki (aby zwi�kszy� wag� kraw�dzi mi�dzy nimi)
				for(unsigned int l = 0; l < tempAdj[i].size(); l++)
				{
					//znaleziono ju� istniej�cego s�siada, wi�c zwi�kszamy wag�
					if(tempAdj[i][l].first == findRepresentantOf(adjacents[group->getIndexOf(j)][k].first))
					{
						tempAdj[i][l].second += adjacents[group->getIndexOf(j)][k].second;
						isThere = 1;
						break;
					}
				}

				if(isThere == 1)
				{
					isThere = 0;
					continue;
				}
				else
				{
					if(findRepresentantOf(adjacents[group->getIndexOf(j)][k].first) != group->getLeaderIndex())
					{
						vertexDegree[i]++;
						//nie ma jeszcze danej grupy w s�siedztwie naszego wierzcho�ka - dodajemy
						tempAdj[i].push_back(make_pair(findRepresentantOf(adjacents[group->getIndexOf(j)][k].first),
						adjacents[group->getIndexOf(j)][k].second));
					}
				}

			}
		}
	}
	/*
	for(int i = 0; i < groups.size(); i++)
	{
		for(int j = 0; j < tempAdj[i].size(); j++)
		{
			cout<<" miedzy "<<groups[i]<<" i "<<tempAdj[i][j].first<<" jest waga"<<tempAdj[i][j].second<<endl;
		}
		cout<<"Grupa "<<groups[i]<<" jest teraz "<<i<<endl;
	}
	*/
	//podmieniamy s�siad�w ( mamy stworzony nowy graf )

	realIndex = newRealIndex;

	bool toSetUserCount = 0;
	for(int i = 0; i < userCount; i++)
	{
		if(tempAdj[i].size())
			adjacents[i] = tempAdj[i];
		else{
			adjacents[i].clear();
			if(toSetUserCount == 0)
			{
				userCount = i;
				toSetUserCount = 1;
			}
		}
	}

	for(int i = 0; i < userCount; i++)
	{
		representant[i] = i;
	}

	closestAssociate.clear();
	otherGroupEmails.clear();
	bossCoefficient.clear();
	finalBosses.clear();
	groups.clear();

	for( int i = 0; i < userCount; i++)
	{
		otherGroupEmails.push_back(0);
		bossCoefficient.push_back(0);
	}
}