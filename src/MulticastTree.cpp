#include "MulticastTree.h"

MulticastTree::MulticastTree()
{

}

MulticastTree::MulticastTree(Email* startEmail)
{
	Node* temp = new Node;
	//dodaj temp'a do vectore
	temp->emailTo= startEmail;
	//wywołaj w pętli findRoot(temp->email)
	//wywołuj rekurencyjnie createNode(temp)
}

MulticastTree::~MulticastTree()
{
	//rekurencyjnie dochodź do liści
	//wywołuj deleteNode (node);
	//i pop_back() wskazanie z vectora
}

Node* MulticastTree::createNode (Node* parent)
{
	//przechodź pętli po wszystkich mailach wysłanych Usembera.
	//jeśli nam pasuje, czyli FORWARD emaila wskazuje na aktualnie rozważanego Usembera
	//to dodawaj go jako nowy węzeł. W.p.p. zwracaj nullptr;
}

Node* MulticastTree::findRoot (Email* email)
{
	//idź w górę kierując się flagą forwarded_from i znajdź korzeń
}

Node* MulticastTree::findNodeByEmail (Email* email)
{
	//przechodź od korzenia rekurencyjnie w dół
	//jeśli znajdziesz maila, zwróć aktualny węzeł
	//w.p.p. zwracaj nullptr aż do korzenia
}

Node* MulticastTree::deleteNode (Node* node)
{
	//sprawdź czy węzeł jest liściem
	//jeśli tak, zapamiętaj parenta
	//usuń liść
	//usuń dowiązanie do tego liścia u parenta
}
