//
//  Random.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 15/12/13.
//  Copyright (c) 2013 Maciej Safarzyński. All rights reserved.
//

#include "Random.h"

string numgen(int modulo, int start)
{
    int num = (rand() % modulo ) + start;
    ostringstream ss;
    ss << num;
    string snum = ss.str();
    return snum;
}
string IDgen(int size)
{
    string snumber;
    for (int i=0; i<size; ++i) {
        snumber= snumber + numgen(10, 0);
    }
    return snumber;
}