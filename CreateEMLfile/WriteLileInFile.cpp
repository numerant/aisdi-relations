//
//  WriteFileInFile.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 08/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#include "WriteLileInFile.h"


void WriteLineInFile(string linijka,string nazwapliku)
{
	ofstream plik (nazwapliku,  ios::out | ios::app);
	plik << linijka << endl;
	plik.close();
}