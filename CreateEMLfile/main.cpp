//
//  main.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 12/12/13.
//  Copyright (c) 2013 Maciej Safarzyński. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Line.h"
#include "Random.h"
#include "IO.h"

using namespace std;

void WriteLineInFile(string linijka,string nazwapliku)
{
	ofstream plik (nazwapliku,  ios::out | ios::app);
	plik << linijka << endl;
	plik.close();
}

int main()
{
	srand((unsigned int) time( NULL ));
	for (int i=0; i<100 ; i++) {		//Petla stanowiaca o liczbie plikow .eml
	MessageID messageid;
	messageid.SetID(messageid.strID=IDgen(20));
	string nazwapliku="Mails temp/IDnr" + messageid.strID + ".eml";
	From from;
	To to;
	Subject subject;
	Date date;
	Rest rest;
	Contents contents;
    WriteLineInFile(from.linijka, nazwapliku);
	WriteLineInFile(to.linijka, nazwapliku);
	WriteLineInFile(subject.linijka, nazwapliku);
	WriteLineInFile(messageid.linijka, nazwapliku);
	WriteLineInFile(date.linijka, nazwapliku);
	WriteLineInFile(rest.linijka, nazwapliku);
	WriteLineInFile(contents.linijka, nazwapliku);
	}
    return 0;
}

