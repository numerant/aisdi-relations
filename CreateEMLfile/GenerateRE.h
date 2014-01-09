//
//  GenerateRE.h
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 08/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#ifndef CreateEMLfile_GenerateRE_h
#define CreateEMLfile_GenerateRE_h

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

void GenerateRE(From from, To to, Subject subject, MessageID messageidINRPLY, Date date, Rest rest, Contents contents, int ile);


#endif
