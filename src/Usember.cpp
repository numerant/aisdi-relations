#include "Usember.h"

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

void Usember::addMail(Email *email, DataType type)	// dodaje list do odpowiedniego wektora
{

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

unsigned int Usember::sendMailCount()			// zwraca liczbę maili wysłanych przez tego usembera
{
    return sentMails.size();
}

unsigned int Usember::receiveMailCount()
{
    return receivedMails.size();
}
