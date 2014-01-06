//
//  Line.h
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 15/12/13.
//  Copyright (c) 2013 Maciej Safarzyński. All rights reserved.
//

#ifndef CreateEMLfile_Line_h
#define CreateEMLfile_Line_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Random.h"
#include "IO.h"

using namespace std;
class Line
{
public:
	string linijka, text;
	/*string numgen(int modulo, int start);
	string IDgen(int size);*/
};

class From : public Line
{
public:
	string domena = "@mail.com";
	From();
	
};

class To : public Line
{
public:
	string domena="@mail.com";
	To();
};

class Subject : public Line
{
public:
	Subject();
};

class MessageID : public Line
{
public:
    void SetID(string strID)
    {
        linijka="Message-ID: <" + strID + domena + ">";
    }
	string domena="@mail.com";
    string strID;
	MessageID();
};

class Date : public Line
{
public:
	string DayofWeek, Month;
	string setDayofWeek();
	string DayofMonth=numgen(30,1);
	string setMonth();
	string Hour=numgen(12,12);
	string Minute=numgen(50,10);
	string Second=numgen(50,10);
	Date();
	
};

class Rest : public Line
{
public:
    Rest();
};

class Contents : public Line
{
public:
	Contents();
};




#endif
