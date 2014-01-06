//
//  IO.h
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 05/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#ifndef CreateEMLfile_IO_h
#define CreateEMLfile_IO_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Random.h"

using namespace std;



class Input
{
public:
    Input();
    static void ImportToVector(string filename, vector<string> & VectorOfStrings);
};



#endif
