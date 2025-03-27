#include "BST.hpp"

BST::BST()
{
	// empty tree
	this->mpRoot = nullptr;
}

void BST::insert(string newData)
{
	insert(newData, this->mpRoot);
}

void BST::inorderTraversal() const
{
	inorderTraversal(this->mpRoot);
}

void BST::insert(string newData, Node* pTree)
{
	if (nullptr == pTree) // tree is empty
	{
		this->mpRoot = new Node(newData);
	}
	else // inserting into a non empty tree
	{
		if (newData < pTree->getData()) // left subtree
		{
			// inserting in left subtree
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new Node(newData));
			}
			else
			{
				// we have to move further down the left subtree to find
				// the slot to insert into the tree
				insert(newData, pTree->getLeftPtr());
			}
		}
		else if (newData > pTree->getData()) // right subtree
		{
			if (pTree->getRightPtr() == nullptr)
			{
				// we found the place to insert in the right subtree
				pTree->setRightPtr(new Node(newData));
			}
			else
			{
				// we need to go further down right subtree
				insert(newData, pTree->getRightPtr());
			}
		}
		else // duplicate entry
		{
			cout << "trying to insert duplicate: " << newData << endl;
		}
	}
}

void BST::inorderTraversal(Node* pTree) const
{
	if (pTree != nullptr)
	{
		// Go left, Process, Go right
		inorderTraversal(pTree->getLeftPtr()); // go left
		cout << pTree->getData() << endl; // process - print
		inorderTraversal(pTree->getRightPtr()); // go right
	}
}
