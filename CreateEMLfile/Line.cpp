//
//  Line.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 15/12/13.
//  Copyright (c) 2013 Maciej Safarzyński. All rights reserved.
//

#include "Line.h"
int x,y;
From::From()
	{
        vector<string> VectorFrom;
        Input::ImportToVector("from.txt", VectorFrom);
        string s= numgen((int)VectorFrom.size(), 0);
        istringstream iss(s);
        iss >> x;
        text=VectorFrom[x];
		linijka="From: \"" + text + "\" <" + text + domena + ">";
	}


To::To()
	{
        vector<string> VectorFrom;
        Input::ImportToVector("from.txt", VectorFrom);
        do{
        string s= numgen((int)VectorFrom.size(), 0);
        istringstream iss(s);
        iss >> y;
        text=VectorFrom[y];
        }while (x==y);
		linijka="To: \"" + text + "\" <" + text + domena + ">";
	}


Subject::Subject()
	{
        vector<string> VectorSubject;
        Input::ImportToVector("subject.txt", VectorSubject);
        string s= numgen((int)VectorSubject.size(), 0);
        int x;
        istringstream iss(s);
        iss >> x;
        text=VectorSubject[x];
		linijka="Subject: " + text;
	}


MessageID::MessageID()
	{
	}




string Date::setDayofWeek()
	{
		string nr=numgen(7,1);
		if (nr=="1") DayofWeek="Mon";
		if (nr=="2") DayofWeek="Tue";
		if (nr=="3") DayofWeek="Wed";
		if (nr=="4") DayofWeek="Thu";
		if (nr=="5") DayofWeek="Fri";
		if (nr=="6") DayofWeek="Sat";
		if (nr=="7") DayofWeek="Sun";
		return DayofWeek;
	}
	
string Date::setMonth()
	{
		string nr=numgen(12,1);
		if (nr=="1") Month="Jan";
		if (nr=="2") Month="Feb";
		if (nr=="3") Month="Mar";
		if (nr=="4") Month="Apr";
		if (nr=="5") Month="May";
		if (nr=="6") Month="Jun";
		if (nr=="7") Month="Jul";
		if (nr=="8") Month="Aug";
		if (nr=="9") Month="Sep";
		if (nr=="10") Month="Oct";
		if (nr=="11") Month="Nov";
		if (nr=="12") Month="Dec";
		return Month;
	}
	
Date::Date()
	{
		linijka="Date: " + setDayofWeek() + ", " + DayofMonth + " " + setMonth() + " 2012 " + Hour + ":" + Minute + ":" + Second + " +0200";
	}


Rest::Rest()
	{
		linijka ="MIME-Version: 1.0\nContent-Type: text/html;\n\tcharset=\"iso-8859-1\"\nContent-Transfer-Encoding: quoted-printable";
	}

Contents::Contents()
	{
        vector<string> VectorContents;
        Input::ImportToVector("/Users/Maciek/Documents/Studia/AISDI/Projekt/CreateEMLfile/CreateEMLfile/contents.txt", VectorContents);
        string s= numgen((int)VectorContents.size(), 0);
        int z;
        istringstream iss(s);
        iss >> z;
        for (int i=z; i<VectorContents.size() && i-z<50; i++) {
        text=text + "\n" + VectorContents[i];
        }
		linijka="\n" + text;
	}



