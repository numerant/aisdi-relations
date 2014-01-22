#include "MulticastTree.h"

MulticastTree::MulticastTree()
{

}

MulticastTree::MulticastTree(Email* startEmail)
{
	HEAD = findRoot (startEmail);
	if (HEAD != nullptr)
	{
		
		createNode(HEAD);
		Node* tempNode = new Node;
		tempNode->usember = startEmail->getTo();
	}
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
	Node* returnNode = nullptr;
	Usember * tempUsember = email->getFrom();
	Email* nextEmail = tempUsember->searchBackward(email);
	if (nextEmail != nullptr)
	{
		if (nextEmail->getIsForwarded())
			returnNode = findRoot (nextEmail);
		return returnNode;
	}
	else
	{
		returnNode = new Node;
		returnNode->emailTo = email;
		returnNode->usember = tempUsember;
		returnNode->parent = nullptr;
		return returnNode;
	}
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
