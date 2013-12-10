// klasa Usember

#include "Usember.h"


Usember::Usember(string usemberName, string domain, string realName)
{
    //ctor
	this.usemberName = usemberName;
	this.domain = domain;
	this.realName = realName;
}

Usember::~Usember()
{
    //dtor
	sendMails.clear();
	receivedMails.clear();
}


Usember::addMail(Email *email, EmailType type)	// dodaje list do odpowiedniego wektora
{

}

Usember::removeMail(Email *email)				// usuwa list z wektora
{
	
}

Usember::setGroup(Group *group)					// przydziela grupę usemberowi / używać także jako akutalizacji
{
	this.group = group;
}

Usember::setRealName(string rn)					// ustawia pole realName - działanie jak wyżej
{
	realName = rn;
}
	
Usember::getAddress()				// zwraca ciąg pełnego maila [usemberName]@[domain]
{
	return usemberName + '@' + domain;
}

Usember::sendMailCount()			// zwraca liczbę maili wysłanych przez tego usembera
{
	return sendMails.size();
}

Usember::receiveMailCount()
{
	return receivedMails.size();
}