#include "Email.h"

Email::Email() {}
Email::~Email() {}

Usember* Email::getFrom()
{
    return from;
}

void Email::setFrom(Usember *user)
{
    from = user;
}

Date Email::getDate()
{
    return date;
}

void Email::setDate(Date* newDate)
{
    date = *newDate;
}

Usember* Email::getReplyTo()
{
    return replyTo;
}

void Email::setReplyTo(Usember *newReplyTo)
{
    replyTo = newReplyTo;
}

int Email::getInReplyTo()
{
    return inReplyTo;
}

void Email::setInReplyTo(int newInReplyTo)
{
    inReplyTo = newInReplyTo;
}

string Email::getID()
{
    return messageID;
}

void Email::setID(string ID)
{
    messageID = ID;
}

Usember* Email::getTo()
{
    return to;
}

void Email::setTo(Usember *newTo)
{
    to = newTo;
}

string Email::getSubject()
{
    return subject;
}

void Email::setSubject(string newSubject)
{
    subject = newSubject;
}

string Email::getContent()
{
    return content;
}

void Email::setContent(string newContent)
{
    content = newContent;
}

int Email::getReferences()
{
    return references;
}

void Email::setReferences( int newReferences)
{
    references = newReferences;
}