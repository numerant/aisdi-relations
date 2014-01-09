#include "Usember.h"

Usember::Usember()
{

}

Usember::Usember(string usemberName, string domain, string realName)
{
    //ctor
    this->usemberName = usemberName;
    this->domain = domain;
    this->realName = realName;
}

Usember::~Usember()
{
    //dtor
    sentMails.clear();
    receivedMails.clear();
}

void Usember::addEmailSent (Email * email)
{
    sentMails.push_back(email);
}

void Usember::addEmailReceived (Email * email)
{
    receivedMails.push_back(email);
}

void Usember::removeMail(Email *email)				// usuwa list z wektora
{

}

void Usember::setGroup(Group *group)					// przydziela grupę usemberowi / używać także jako akutalizacji
{
    this->group = group;
}

void Usember::setRealName(string rn)					// ustawia pole realName - działanie jak wyżej
{
    realName = rn;
}

string Usember::getAddress()				// zwraca ciąg pełnego maila [usemberName]@[domain]
{
    return usemberName + "@" + domain;
}

string Usember::getRealName()				// zwraca string z realName
{
    return this->realName;
}

Group* Usember::getGroup()				// zwraca wskazanie na grupę
{
    return this->group;
}

Email* Usember::getEmailReceived(int position)
{
	if ( (position < 0) || (position >= (int)receivedMails.size()) )
        return nullptr;
    else
        return receivedMails[position];
}

Email* Usember::getEmailSent(int position)
{
	if ( (position < 0) || (position >= (int)sentMails.size()) )
        return nullptr;
    else
        return sentMails[position];
}

unsigned int Usember::sendMailCount()			// zwraca liczbę maili wysłanych przez tego usembera
{
    return sentMails.size();
}

unsigned int Usember::receiveMailCount()
{
    return receivedMails.size();
}

unsigned int Usember::getEmailsReceivedInMonth (int month)
{
    unsigned int counter = 0;

    for(int i = 0; i < receivedMails.size(); i++ )
    {
        if (receivedMails[i]->getDate().monthToInt(receivedMails[i]->getDate().getMonth()) == month)
            counter++;
    }

    return counter;
}

unsigned int Usember::getEmailsSentInMonth (int month)
{
    unsigned int counter = 0;

    for(int i = 0; i < sentMails.size(); i++ )
    {
        if (sentMails[i]->getDate().monthToInt(sentMails[i]->getDate().getMonth()) == month)
            counter++;
    }

    return counter;
}

unsigned int Usember::getMaxEmailsInMonth ()
{
    unsigned int maxSum = 0, temp;

    for (int i = 0; i < 12; i++)
    {
        temp = getEmailsReceivedInMonth(i);
        if (temp > maxSum)
            maxSum = temp;
        temp = getEmailsSentInMonth(i);
        if (temp > maxSum)
            maxSum = temp;

    }
    return maxSum;
}


