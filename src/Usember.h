#pragma once

#include <string>
#include <vector>
#include <boost/serialization/base_object.hpp>
#include "Group.h"
#include "Email.h"
#include "SerializationInit.h"

/*
	Klasa tożsamości wyodrębnionych z maili w polach od/do/dowielu/przekazanodalej.
	W momencie wczytywania nowego maila do bazy, sprawdzane są wszelkie adresy z tych pól,
	przeszukiwana jest baza usemberów i jeśli występuje już nasz kontakt to tylko jest akutalizowany
	w przeciwnym razie tworzymy nowy kontakt.

*/

class Email;
typedef enum DataType {FROM, DATE, REPLY_TO, IN_REPLY_TO, MESSAGE_ID, TO, SUBJECT} DataType;


using namespace std;

class Usember
{
    template<class Archive> friend void  boost::serialization::serialize(Archive &, Usember &, const unsigned int);  //potrzebne do serializacji
public:
    Usember();                                      //potrzebne do serializacji
    Usember(string usemberName, string domain, string realName);
    ~Usember();

    void addEmailSent (Email * email);             // dodaje list do odpowiedniego wektora
    void addEmailReceived (Email * email);

    bool removeEmailSent(Email *email);					// usuwa list z wektora
    bool removeEmailReceived (Email* email);
    void setGroup(Group	*group);						// przydziela grupę usemberowi / używać także jako akutalizacji
    void setRealName(string rn);						// ustawia pole realName - działanie jak wyżej

	string getRealName();								// zwraca string z realName
    string getAddress();					// zwraca ciąg pełnego maila [usemberName]@[domain]
	Group* getGroup();						// zwraca wskazanie na grupę
	Email* getEmailReceived(int position);	// zwraca wskazanie na danego maila (z otrzymanych)
	Email* getEmailSent(int position);		// zwraca wskazanie na danego maila (z wysłanych)

    unsigned int sendMailCount();				// zwraca liczbę maili wysłanych przez tego usembera
    unsigned int receiveMailCount();				// zwraca liczbę maili odebranych przez tego usembera
    unsigned int getEmailsReceivedInMonth (int month); // zwraca liczbę maili odebranych w danym miesiącu
    unsigned int getEmailsSentInMonth (int month);    // zwraca liczbę maili wysłanych w danym miesiącu
    unsigned int getMaxEmailsInMonth ();               // zwraca największą liczbę maili napisanych w ciągu danego miesiąca

private:
    // adres - email:
    string usemberName;				// to co przed @
    string domain;					// to co po @

    string realName;				// nazwa (na ogół imię i nazwisko) wychwycone z pola Od - jeśli zdef.
    Group *group;					// referencja na grupę do której należy ten usember

    vector<Email*> sentMails;		// maile wysłane przez tego usembera
    vector<Email*> receivedMails;	// maile odebrane przez tego usembera
};
