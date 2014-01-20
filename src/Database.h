#pragma once
#include "Email.h"
#include "Query.h"
#include "SerializationInit.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace std;

/*Klasa Database, przechowująca dane dotyczące grup, maili oraz użytkowników oraz udostępniająca
odpowiednie operacje na nich.

Wszystkie wektory są uporządkowane niemalejąco. Ich przeszukiwanie odbywa się binarnie - vector dzielony jest
na połowy i w zależności od tego czy element pomiędzy tymi połowami jest większy czy mniejszy od poszukiwanego,
bierzemy lewą bądź prawą połowę, operację powtarzamy do znalezienia (lub stwierdzenia że go nie ma) poszukiwanego
elementu.*/

class EmailQuery;
class UsemberQuery;
class Query;
class DateCriteria;
class StringCriteria;
class Criteria;

class Database
{
public:
    template<class Archive> friend void  boost::serialization::serialize(Archive &, Database &, const unsigned int);  //potrzebne do serializacji
private:
    vector<Email*> emailVector;                 //wektor przechowujący obiekty klasy Email,
    vector<Group*> groupVector;                 //wektor przechowujący obiekty klasy Group
    vector<Usember*> usemberVector;             //wektor przechowujący wszystkich nadawców i odbiorców emaili, czyli Usemberów
    vector<Email*> emailSearchResultVector;     //
    vector<Usember*> usemberSearchResultVector; //wektory wynikow wyszukiwania w bazie danych
public:
    Database();
    ~Database();
    bool addEmail(Email* email);                                //metoda dodająca element klasy Email do wektora emaili
    bool addGroup(Group* group);                                //metoda dodająca element klasy Group do wektora grup
    bool addUsember(Usember* usember);                          //metoda dodająca usembera do wektora usemberów
    void deleteEmail(Email* email);                             //metoda usuwająca podany e-mail z wektora
    void deleteGroup(Group* group);                             //metoda usuwająca podany element klasy Group z wektora
    void deleteUsember(Usember* usember);                       //metoda usuwająca podanego usembera z wektora
    void select(EmailQuery& emailQuery);                        //metody, które przeszukują bazę danych na podstawie danego obiektu klasy Query
    void select(UsemberQuery& usemberQuery);                    //i na tej podstawie tworza wektor wskaźników na maile/grupy/usemberów pasujących do kryteriów zapytania                                                       //i zwracają referencję do niego
    void deleteQueryResults(Query* query);                      //metoda usuwająca zapytanie utworzone przez metodę select, wywoływana zaraz po niej
    int findEmail(string messageId);                            //metoda wyszukujące email w bazie
    int findGroup(int groupId);                                 //metoda wyszukujące grupę w bazie
    int findUsember(string name);                               //metoda wyszukujące usembera w bazie
    void clearEmails();                                         //metoda usuwająca wszystkie maile z bazy
    void clearGroups();                                         //metoda usuwająca wszystkie grupy z bazy
    void clearUsembers();                                       //metoda usuwająca wszystkich usemberów z bazy
    Email* getEmail(int position);                              //metoda zwracajaca mail na okreslonej pozycji w wektorze
    Group* getGroup(int position);                              //metoda zwracajaca grupe na okreslonej pozycji w wektorze
    Usember* getUsember(int position);                          //metoda zwracajaca usembera na okreslonej pozycji w wektorze
    Email* getResultEmail(int position);                        //metoda zwracajaca mail na okreslonej pozycji w wektorze wynikow wyszukiwania
    Usember* getResultUsember(int position);                    //metoda zwracajaca usembera na okreslonej pozycji w wektorze wynikow wyszukiwania
    int countEmails();                                          //metoda zwracajaca ilosc maili w wektorze
    int countGroups();                                          //metoda zwracajaca ilosc grup w wektorze
    int countUsembers();                                        //metoda zwracajaca ilosc usemberow w wektorze
    int countResultEmails();                                          //metoda zwracajaca ilosc maili w wektorze wynikow wyszukiwania
    int countResultUsembers();                                        //metoda zwracajaca ilosc usemberow w wektorze wynikow wyszukiwania
private:
    bool matches(Email& email, StringCriteria& stringCriteria); //metody sprawdzajace, czy podany mail spelnia podane kryterium
    bool matches(Email& email, DateCriteria& dateCriteria);     //
    bool matches(Usember& usember, StringCriteria& stringCriteria);
    void swapEmails(int position1, int position2);              //metoda zamieniająca dwa maile w wektorze
    void swapGroups(int position1, int position2);              //metoda zamieniająca dwie grupy w wektorze
    void swapUsembers(int position1, int position2);            //metoda zamieniająca dwóch usemberów w wektorze
    static bool compareEmails(Email* email1, Email* email2);    //metoda porownujaca 2 maile wg id, uzywana do sortowania
    static bool compareGroups(Group* group1, Group* group2);    //metoda porownujaca 2 grupy wg id, uzywana do sortowania
    static bool compareUsembers(Usember* usember1, Usember* usember2);  //metoda porownujaca 2 usemberow wg nazwy/imienia, uzywana do sortowania
};
