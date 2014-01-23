#pragma once
#include "Usember.h"
#include "Date.h"
#include "SerializationInit.h"
#include <string>
#include <boost/serialization/base_object.hpp>

//typedef enum DataType {FROM, DATE, REPLY_TO, IN_REPLY_TO, MESSAGE_ID, TO, SUBJECT} DataType;

class Usember;
class Date;

using namespace std;

class Email
{
    template<class Archive> friend void  boost::serialization::serialize(Archive &, Email &, const unsigned int);  //potrzebne do serializacji

private:
    Usember *from;		//przechowujące adres e-mail nadawcy
    Date date;			//przechowujące datę nadania
    Usember *replyTo;	//przechowujące adres e-mail, na który ma zostać wysłana odpowiedź do danego maila
    string inReplyTo = "";	//przechowujące ID wiadomości, na którą dana wiadomość jest odpowiedzią
    string messageID = "";	//przechowujące ID wiadomości nadane przez bazę danych
    Usember *to;	    	//przechowujące adres e-mail odbiorcy
    string subject = "";	//przechowujące temat wiadomości
    string content = "";		//przechowujące treść wiadomości

    int references;

	bool isForwarded = false;	// czy ta wiadomość jest Forwardem

public:
    Email();
    ~Email();

    Usember* getFrom();
    void setFrom(Usember *user);
    Date getDate();
    void setDate(Date* newDate);
    Usember* getReplyTo();
    void setReplyTo(Usember *newReplyTo);
    string getInReplyTo();
    void setInReplyTo(string newInReplyTo);
    string getID(void);
    void setID(string ID);
    Usember* getTo();
    void setTo(Usember *newTo);
    string getSubject();
    void setSubject(string newSubject);
    string getContent();
    void setContent(string newContent);
    int getReferences();
    void setReferences( int newReferences);
	void setIsForwarded( bool newIsForwarded);
	bool getIsForwarded();
};
