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

bool Usember::removeEmailSent(Email *email)
{
    bool found = false;
    for (unsigned i = 0; i < sentMails.size(); i++)
    {
        if (email == sentMails[i])
        {
            Email* temp = sentMails[sentMails.size()-1];
            sentMails[sentMails.size()-1] = email;
            sentMails[i] = temp;
            sentMails.pop_back();
            found = true;
            break;
        }
    }

    return found;
}

bool Usember::removeEmailReceived(Email *email)
{
    bool found = false;
    for (unsigned i = 0; i < receivedMails.size(); i++)
    {
        if (email == receivedMails[i])
        {
            Email* temp = receivedMails[receivedMails.size()-1];
            receivedMails[receivedMails.size()-1] = email;
            receivedMails[i] = temp;
            receivedMails.pop_back();
            found = true;
            break;
        }
    }

    return found;
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

    for(unsigned int i = 0; i < receivedMails.size(); i++ )
    {
        if (receivedMails[i]->getDate().monthToInt(receivedMails[i]->getDate().getMonth()) == month)
            counter++;
    }

    return counter;
}

unsigned int Usember::getEmailsSentInMonth (int month)
{
    unsigned int counter = 0;

    for(unsigned int i = 0; i < sentMails.size(); i++ )
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

unsigned int Usember::getEmailsCount (Database* database, int usemberIndex)
{
    Usember* tempU = database->getUsember(usemberIndex);
    if (tempU != nullptr)
    {
        unsigned int emailsSum = 0;
        for (unsigned int i = 0; i < this->sendMailCount(); i++)
        {
            Email* tempE = this->sentMails[i];
            if (tempE->getTo() == tempU)
                emailsSum++;
        }

        for (unsigned int i = 0; i < this->receiveMailCount(); i++)
        {
            Email* tempE = this->receivedMails[i];
            if (tempE->getFrom() == tempU)
                emailsSum++;
        }

        return emailsSum;
    }
}

Email* Usember::searchBackward(Email* email)
{
	if (email->getIsForwarded() == false)
		return nullptr;
		
	string subject = email->getSubject();
	subject.substr(5, subject.size()-5);
	
	Email* tempE;
	for (unsigned int i = 0; i < this->sendMailCount(); i++)
    {
		tempE = this->sentMails[i];
        if (tempE->getSubject() == subject)
			return tempE;
    }
	return nullptr;
}
