#pragma once
#include "Email.h"
#include "Usember.h"
#include <vector>

using namespace std;

/*

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
    vector<Node*> Nodes;		//TODO Na razie nie jest konieczny chyba

public:
    MulticastTree();					//puste drzewo
    MulticastTree(Email* startEmail);	//tworzy obiekt drzewa od razu z węzłami
	~MulticastTree();

	Node* createNodes (Node* parent);		//szuka wszystkich możliwych potomków i tworzy je
	Node* findRoot (Email* email);			//rozpoczyna generowanie drzewa
	Node* findNodeByEmail (Email* email);	//zwraca węzeł dla podanego emaila
	Node* deleteNodes (Node* node);			//usuwa węzeł (tylko jeżeli jest liściem) i zwraca wskazanie na rodzica
											//w.p.p. zwraca nullptr

    void addEmail (Email* email);
};
