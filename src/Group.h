#pragma once
#include <boost/serialization/base_object.hpp>

class Group
{
    friend class boost::serialization::access;  //potrzebne do serializacji
private:
    unsigned int id;

public:
    int getID();
};
