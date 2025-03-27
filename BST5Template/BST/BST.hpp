#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

template <class T>
class BST
{
public:
	BST();

	void insert(const T &newData);
	void inorderTraversal() const;

private:
	void insert(const T& newData, Node<T>* pTree);
	void inorderTraversal(Node<T> *pTree) const;

	Node<T>* mpRoot;
};

template <class T>
BST<T>::BST()
{
	// empty tree
	this->mpRoot = nullptr;
}

template <class T>
void BST<T>::insert(const T &newData)
{
	insert(newData, this->mpRoot);
}

template <class T>
void BST<T>::inorderTraversal() const
{
	inorderTraversal(this->mpRoot);
}

template <class T>
void BST<T>::insert(const T &newData, Node<T>* pTree)
{
	if (nullptr == pTree) // tree is empty
	{
		this->mpRoot = new Node<T>(newData);
	}
	else // inserting into a non empty tree
	{
		if (newData < pTree->getData()) // left subtree
		{
			// inserting in left subtree
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new Node<T>(newData));
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
				pTree->setRightPtr(new Node<T>(newData));
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

template <class T>
void BST<T>::inorderTraversal(Node<T>* pTree) const
{
	if (pTree != nullptr)
	{
		// Go left, Process, Go right
		inorderTraversal(pTree->getLeftPtr()); // go left
		cout << pTree->getData() << endl; // process - print
		inorderTraversal(pTree->getRightPtr()); // go right
	}
}