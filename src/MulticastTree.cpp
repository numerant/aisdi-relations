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

		childCount= parent->usember->getForwardsCount(emailToRecognize, false);
		for (int i = 0; i < childCount; i++)
		{
            newEmail= parent->usember->getForward(i, emailToRecognize, false);
            if (newEmail == emailToRecognize)
            	continue;
            if (newEmail == nullptr)
            	break;
			temp = new Node;
			temp->usember = newEmail->getTo();
			temp->parent = parent;
			parent->childs.push_back(temp);
			parent->forwards.push_back(newEmail);
			temp->id = globalId;
			globalId++;

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
		bool nullParent = true;
		if (parent->emailTo != nullptr)
			nullParent = false;

		if (! nullParent)
			emailToRecognize = parent->emailTo;
		else
			emailToRecognize = parent->parent->forwards[0];

		if (emailToRecognize == nullptr)
			return nullptr;

     	if (! nullParent)
			childCount = parent->usember->getForwardsCount(emailToRecognize, false);
		else
			childCount = parent->usember->getForwardsCount(emailToRecognize, true);

		for (int i = 0; i < childCount; i++)
		{
			if (! nullParent)
			{
				newEmail = parent->usember->getForward (i, emailToRecognize, false);
				if (newEmail == emailToRecognize)
            		continue;
				if (newEmail == nullptr)
            		break;
			}
			else
			{
				newEmail = parent->usember->getForward (i, emailToRecognize, false);
				string subject = newEmail->getSubject();
				if (subject.substr(5, subject.size()-5) == emailToRecognize->getSubject())
            		continue;
				if (newEmail == nullptr)
            		break;
			}

			temp = new Node;
			temp->usember = newEmail->getTo();
			temp->parent = parent;
			parent->childs.push_back(temp);
			parent->forwards.push_back(newEmail);
			temp->id = globalId;
			globalId++;

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
		temp->id = globalId;
		globalId++;
		return temp;
	}
	else
	{
		returnNode = new Node;
		HEAD = returnNode;
		returnNode->emailTo = email;
		returnNode->usember = tempUsember;
		returnNode->parent = nullptr;
		returnNode->id = globalId;
		globalId++;
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
		for (unsigned int i = node->childs.size(); i >0 ; i--)
		{
			Node * returnNode = deleteNodes (node->childs[i-1]);
			if (returnNode != node)		//TODO może rzucenie wyjątkiem?
				break;					//zwrócenie wartości innej niż oczekiwana, bląd
			else
			{
				delete node->childs[i-1];
				node->childs.pop_back();
				node->forwards.pop_back();
				node->emailTo = nullptr;
			}

			return node->parent;
		}
	}
	globalId = 0;
}
