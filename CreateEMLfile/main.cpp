//
//  main.cpp
//  CreateEMLfileRE
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
#include "WriteLileInFile.h"
#include "GenerateRE.h"
#include "GenerateFWD.h"

using namespace std;

int main()
{
	srand((unsigned int) time( NULL ));
	for (int i=0; i<1 ; i++)	//Petla stanowiaca o liczbie zwyklych maili

	{
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
		GenerateRE(from, to, subject, messageid, date, rest, contents, 0); //Funkcja kreujaca maile RE, ostatni parametr funkcji to liczba maili Re przypadajaca na kazdy zwykly mail
		GenerateFWD(from, to, subject, date, rest, contents, 0); //Funkcja kreujaca maile FWD, ostatni parametr funkcji to liczba maili FWD przypadajaca na kazdy zwykly mail
	}
    return 0;
}
