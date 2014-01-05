#pragma once

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/vector.hpp>



class Database;
class Email;
class Usember;
class Group;
class Date;

/*
    Serialization.cpp - rozszerzenie przestrzeni nazw boost::serialization o funkcje
    pozwalające na serializację klas używanych w aplikacji. Takie rozwiązanie sprawia,
    że nie są konieczne znaczne modyfikacje klas (poza zaprzyjaźnieniem).
*/

namespace boost
{
    namespace serialization
    {
            //Database
        template<class Archive> void serialize(Archive &archive, Database &database, const unsigned int version);

            //Email
        template<class Archive> void serialize(Archive &archive, Email &email, const unsigned int version);

            //Usember
        template<class Archive> void serialize(Archive &archive, Usember &usember, const unsigned int version);

            //Date
        template<class Archive> void serialize(Archive &archive, Date &date, const unsigned int version);
    }
}
