#pragma once
#include "Email.h"
#include "Usember.h"
#include <vector>

using namespace std;

/*
    Klasa przechowująca strukturę maili 'forwardowanych' przez wielu użytkowników. Dal wybranego maila typu FWD, obiekt wyszukuje korzeń (findRoot),
    następnie rekurencyjnie tworzy wierzchołki potomne, a potem wracając do góry, przelicza współczynniki takie jak wysokość czy liczba liści
    (potrzebne szczególnie do późniejszego rysowania). Wierzchołki (czyli usemberzy) są reprezentowani strukturą Node.
*/

typedef struct Node
{
    Email* emailTo = nullptr;             //email zapamiętany, żeby znaleźć ścieżkę do pierwotnego
    Usember* usember = nullptr;           //użytkownik jako właściwy węzeł drzewa
    Node* parent = nullptr;               //węzeł poprzedzający
    unsigned long id = 0;
    vector<Node*> childs;       //potomkowie
    vector<Email*> forwards;   //vector forwardów (bo może być do wielu)
} Node;

class MulticastTree
{
private:
    Node* HEAD = nullptr;		//wskazanie na korzeń
    unsigned long globalId = 0;
    vector<Node*> Nodes;

public:
    MulticastTree();					//puste drzewo
    MulticastTree(Email* startEmail);	//tworzy obiekt drzewa od razu z węzłami
	~MulticastTree();

	Node* createNodes (Node* parent);		//szuka wszystkich możliwych potomków i tworzy je
	Node* findRoot (Email* email);			//rozpoczyna generowanie drzewa
	Node* findNodeByEmail (Email* email);	//zwraca węzeł dla podanego emaila
	Node* deleteNodes (Node* node);			//usuwa węzeł (tylko jeżeli jest liściem) i zwraca wskazanie na rodzica
											//w.p.p. zwraca nullptr
};
