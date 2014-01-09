//
//  GenerateFWD.h
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 09/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#ifndef CreateEMLfile_GenerateFWD_h
#define CreateEMLfile_GenerateFWD_h

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


void GenerateFWD(From from, To to, Subject subject, Date date, Rest rest, Contents contents, int ile);

#endif
