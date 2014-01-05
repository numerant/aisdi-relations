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
    string inReplyTo;
    //przechowujące ID wiadomości nadane przez bazę danych
    string messageID;
    //przechowujące adres e-mail odbiorcy
    Usember *to;
    //przechowujące temat wiadomości
    string subject;
    //przechowujące treść wiadomości
    string content;
    //przechowujace ID forwardow tej wiadomosci
    vector<string> forwards;
    //opcjonalne pole przechowujące ID wiadomości, na którą dana wiadomość jest odpowiedzią oraz
    //ID wiadomości, na którą odpowiedzią jest wiadomość, na którą dana wiadomość jest odpowiedzią
    //tzn. ID1->ID2->ID3 (gdzie ID3 to ID danej wiadomośći, pole to przechowuje ID2 oraz ID1)
    int references;

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
    vector<string>& getForwards();
    int getReferences();
    void setReferences( int newReferences);
};
