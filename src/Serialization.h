#pragma once

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/vector.hpp>

#include "Database.h"
#include "Email.h"
#include "Usember.h"
#include "Group.h"
#include "Date.h"

//class Database;

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
        template<class Archive> void serialize(Archive &archive, Database &database, const unsigned int version)
        {
            archive & database.emailVector;
            //archive & database.groupVector;                    //zakomentowane - grupy chyba jeszcze nie działają?
            archive & database.usemberVector;                  //usember nie jest jeszcze dodawany
            archive & database.autoImportPath;
        }

            //Email
        template<class Archive> void serialize(Archive &archive, Email &email, const unsigned int version)
        {
            archive & email.from;
            archive & email.date;
            //archive & email.replyTo;
            archive & email.inReplyTo;
            archive & email.messageID;
            archive & email.to;
            archive & email.subject;
            archive & email.content;
            archive & email.isForwarded;
            archive & email.references;
        }

            //Usember
        template<class Archive> void serialize(Archive &archive, Usember &usember, const unsigned int version)
        {
            archive & usember.usemberName;
            archive & usember.domain;
            archive & usember.realName;         //czy to czasem nie jest puste?
            //archive & usember.group;			// grupy nie działają - koment
            archive & usember.sentMails;
            archive & usember.receivedMails;
        }

            //Date
        template<class Archive> void serialize(Archive &archive, Date &date, const unsigned int version)
        {
            archive & date.fullDate;
            archive & date.weekDay;
            archive & date.day;
            archive & date.month;
            archive & date.monthInt;
            archive & date.year;
            archive & date.hour;
            archive & date.minute;
            archive & date.second;
            archive & date.timeZone;
        }
    }
}
