#include "MulticastTree.h"
#include "wx/msgdlg.h"

MulticastTree::MulticastTree()
{

}

MulticastTree::MulticastTree(Email* startEmail)
{
	//TODO dodaj wyjątek na całość
	Node* root = findRoot (startEmail);
	if (root != nullptr)
	{
		if (createNodes(HEAD) == nullptr)
			//TODO rzuć wyjątkiem, usuń box'a
			wxMessageBox(_("Nie zrobiło się..."));
	}

}

MulticastTree::~MulticastTree()
{
	deleteNodes(HEAD);
}

Node* MulticastTree::createNodes (Node* parent)
{
    int childCount = 0;
    Email* newEmail = nullptr;
	Node * temp = nullptr;
	if (parent == HEAD)
	{
		Email* emailToRecognize = parent->emailTo;
		if (emailToRecognize == nullptr)
			return nullptr;

        //TODO odkomentować
		//childCount= parent->usember->getForwardsCount(emailToRecognize);
		for (int i = 0; i < childCount-1; i++)
		{
		    //TODO odkomentować
            //newEmail= parent->usember->getForward(i);
			temp = new Node;
			temp->usember = newEmail->getTo();
			temp->parent = parent;
			parent->childs.push_back(temp);
			parent->forwards.push_back(newEmail);

			Node* returnNode = createNodes (temp);
			if (returnNode = nullptr)
			{
				temp->childs.push_back(nullptr);
				temp->forwards.push_back(nullptr);
			}
		}
		return temp;
	}
	else
	{
		Email* emailToRecognize;
		if (parent->emailTo != nullptr)
			emailToRecognize = parent->emailTo;
		else
			emailToRecognize = parent->forwards[0];

		if (emailToRecognize == nullptr)
			return nullptr;

        //TODO odkomentować
		//childCount = parent->usember->getForwardsCount(emailToRecognize);
		if (parent->emailTo != nullptr)
			childCount -= 1;

		for (int i = 0; i < childCount; i++)
		{
			//TODO odkomentować
			//newEmail = parent->usember->getForward (i);
			temp = new Node;
			temp->usember = newEmail->getTo();
			temp->parent = parent;
			parent->childs.push_back(temp);
			parent->forwards.push_back(newEmail);

			Node* returnNode = createNodes (temp);
			if (returnNode = nullptr)
			{
				temp->childs.push_back(nullptr);
				temp->forwards.push_back(nullptr);
			}
		}
		return temp;
	}
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
		Node* temp = new Node;
		temp->emailTo = email;
		temp->usember = tempUsember;
		temp->parent = returnNode;
		temp->parent->childs.push_back(temp);
		temp->parent->forwards.push_back(temp->parent->emailTo);
		return temp;
	}
	else
	{
		returnNode = new Node;
		HEAD = returnNode;
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

Node* MulticastTree::deleteNodes (Node* node)
{
	if (node->childs[0] == nullptr)		//węzeł jest liściem
	{
		return node->parent;
	}
	else
	{
		for (unsigned int i = node->childs.size()-1 ; i >=0 ; i--)
		{
			Node * returnNode = deleteNodes (node->childs[i]);
			if (returnNode != node)		//TODO może rzucenie wyjątkiem?
				break;					//zwrócenie wartości innej niż oczekiwana, bląd
			else
			{
				delete node->childs[i];
				node->childs.pop_back();
				node->forwards.pop_back();
				node->emailTo = nullptr;
			}

			return node->parent;
		}
	}
}
