#pragma once
#include "Email.h"
#include "Usember.h"
#include <vector>

using namespace std;

/*

*/

typedef struct Node
{
    Email* emailTo;         //treści emaila podanego dalej
    Usember* usember;       //użytkownik jako właściwy węzeł drzewa
    Node* parent;           //węzeł poprzedzający
    vector<Node*> childs;   //potomkowie
} Node;

class MulticastTree
{
private:
    Node* HEAD = nullptr;		//wskazanie na korzeń
    vector<Node*> Nodes;		//Na razie nie jest konieczny chyba

public:
    MulticastTree();					//puste drzewo
    MulticastTree(Email* startEmail);	//tworzy obiekt drzewa od razu z węzłami
	~MulticastTree();

	Node* createNode (Node* parent);		//szuka wszystkich możliwych potomków i tworzy je
	Node* findRoot (Email* email);			//rozpoczyna generowanie drzewa
	Node* findNodeByEmail (Email* email);	//zwraca węzeł dla podanego emaila
	Node* deleteNode (Node* node);			//usuwa węzeł (tylko jeżeli jest liściem) i zwraca wskazanie na rodzica
											//w.p.p. zwraca nullptr
};
