#pragma once
#include "Usember.h"
#include "Date.h"
#include <string>

//typedef enum DataType {FROM, DATE, REPLY_TO, IN_REPLY_TO, MESSAGE_ID, TO, SUBJECT} DataType;

class Usember;
class Date;

using namespace std;

class Email
{
private:
    //przechowujące adres e-mail nadawcy
    Usember *from;
    //przechowujące datę nadania
    Date date;
    //przechowujące adres e-mail, na który ma zostać wysłana odpowiedź do danego maila
    Usember *replyTo;
    //przechowujące ID wiadomości, na którą dana wiadomość jest odpowiedzią
    int inReplyTo;
    //przechowujące ID wiadomości nadane przez bazę danych
    int messageID;
    //przechowujące adres e-mail odbiorcy
    Usember *to;
    //przechowujące temat wiadomości
    string subject;
    //przechowujące treść wiadomości
    string content;
    //opcjonalne pole przechowujące ID wiadomości, na którą dana wiadomość jest odpowiedzią oraz
    //ID wiadomości, na którą odpowiedzią jest wiadomość, na którą dana wiadomość jest odpowiedzią
    //tzn. ID1->ID2->ID3 (gdzie ID3 to ID danej wiadomośći, pole to przechowuje ID2 oraz ID1)
    int references;

public:
    Email() {}
    ~Email() {}

    Usember* getFrom()
    {
        return from;
    }
    void setFrom(Usember *user)
    {
        from = user;
    }

    Date getDate()
    {
        return date;
    }
    void setDate(Date* newDate)
    {
        date = *newDate;
    }

    Usember* getReplyTo()
    {
        return replyTo;
    }
    void setReplyTo(Usember *newReplyTo)
    {
        replyTo = newReplyTo;
    }

    int getInReplyTo()
    {
        return inReplyTo;
    }
    void setInReplyTo(int newInReplyTo)
    {
        inReplyTo = newInReplyTo;
    }

    int getID()
    {
        return messageID;
    }

    void setID(int ID)
    {
        messageID = ID;
    }

    Usember* getTo()
    {
        return to;
    }
    void setTo(Usember *newTo)
    {
        to = newTo;
    }

    string getSubject()
    {
        return subject;
    }
    void setSubject(string newSubject)
    {
        subject = newSubject;
    }

    string getContent()
    {
        return content;
    }
    void setContent(string newContent)
    {
        content = newContent;
    }

    int getReferences()
    {
        return references;
    }
    void setReferences( int newReferences)
    {
        references = newReferences;
    }
};
