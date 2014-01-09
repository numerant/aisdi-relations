//
//  WriteFileInFile.h
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 08/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#ifndef __CreateEMLfile__WriteLileInFile__
#define __CreateEMLfile__WriteLileInFile__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Line.h"
#include "Random.h"
#include "IO.h"

void WriteLineInFile(string linijka,string nazwapliku);
void WriteLineInFile(string przedrostek, string linijka,string nazwapliku);

#endif
