#include "EmailQuery.h"
#include "WorkgroupQuery.h"
#include "UsemberQuery.h"
#include <vector>
using namespace std;

/*Klasa Database, przechowująca dane dotyczące grup, maili oraz użytkowników oraz udostępniająca
odpowiednie operacje na nich.

Wszystkie wektory są uporządkowane niemalejąco. Ich przeszukiwanie odbywa się binarnie - vector dzielony jest
na połowy i w zależności od tego czy element pomiędzy tymi połowami jest większy czy mniejszy od poszukiwanego,
bierzemy lewą bądź prawą połowę, operację powtarzamy do znalezienia (lub stwierdzenia że go nie ma) poszukiwanego
elementu.*/

class Database
{
private:
	vector<Email*> emailVector;				//wektor przechowujący obiekty klasy Email,
	vector<Workgroup*> workgroupVector;		//wektor przechowujący obiekty klasy Group
	vector<Usember*> usemberVector;			//wektor przechowujący wszystkich nadawców i odbiorców emaili, czyli Usemberów

public:
	Database();
	~Database();
	bool addEmail(Email* email);								//metoda dodająca element klasy Email do wektora emaili
	bool addWorkgroup(Workgroup* workgroup);						//metoda dodająca element klasy Workgroup do wektora grup
	bool addUsember(Usember* usember);							//metoda dodająca usembera do wektora usemberów
	void deleteEmail(Email* email);								//metoda usuwająca podany e-mail z wektora
	void deleteWorkgroup(Workgroup* workgroup);						//metoda usuwająca podany element klasy Workgroup z wektora
	void deleteUsember(Usember* usember);						//metoda usuwająca podanego usembera z wektora	
	vector<Email*>& select(EmailQuery& emailQuery);				//metody, które przeszukują bazę danych na podstawie danego obiektu klasy Query
	vector<Workgroup*>& select(WorkgroupQuery& workgroupQuery);	//przekazanego jako parametr, pobierają informacje z Query, tworzą odpowiednio posortowany wektor
	vector<Usember*>& select(UsemberQuery& usemberQuery);		//wskaźników na maile/grupy/usemberów pasujących do kryteriów zapytania i zwraca referencję na niego														//i zwracają referencję do niego
	void deleteQueryResults(Query& query);						//metoda usuwająca wektor wyników zapytania utworzonych przez metodę select, wywoływana zaraz po niej
	void sortEmails();											//metoda sortująca maile wg ID
	void sortWorkgroups();										//metoda sortująca grupy robocze
	void sortUsembers();										//metoda sortująca usemberów alfabetycznie
	int countEmails();											//metoda zwracająca liczbę maili w bazie
	int countWorkgroups();										//metoda zwracająca liczbę grup roboczych w bazie
	int countUsembers();										//metoda zwracająca liczbę usemberów w bazie
	int findEmail(int messageId);								//metoda wyszukujące email w bazie				
	int findWorkgroup(int groupId);								//metoda wyszukujące grupę w bazie
	int findUsember(string name);								//metoda wyszukujące usembera w bazie
	void clearEmails();											//metoda usuwająca wszystkie maile z bazy
	void clearWorkgroups();										//metoda usuwająca wszystkie grupy z bazy
	void clearUsembers();										//metoda usuwająca wszystkich usemberów z bazy
	int compareStrings(string string1, string string2, int position);	//metoda do sortowania alfabetycznego stringów
	void swapEmails(int position1, int position2);				//metoda zamieniająca dwa maile w wektorze
	void swapWorkgroups(int position1, int position2);			//metoda zamieniająca dwie grupy w wektorze
	void swapUsembers(int position1, int position2);			//metoda zamieniająca dwóch usemberów w wektorze
};
