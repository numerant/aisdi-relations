//
//  IO.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 05/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#include "IO.h"
using namespace std;

void Input::ImportToVector(string filename, vector<string> & VectorOfStrings)
{
    ifstream file(filename);
    if (! file) cout<<"Brak pliku: "<<filename<<"\n";
    string l;
    while (getline(file, l)) VectorOfStrings.push_back(l);
    file.close();
}

Input::Input(){};