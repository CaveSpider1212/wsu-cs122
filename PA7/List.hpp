/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 4/2/2025
* Description: This file contains the class template declaration and function definitions for the List class template.
*/

#pragma once

#include "Node.hpp"
#include "Data.hpp"

template <class T>
class List {
public:
	List() : pHead(nullptr) {};

	Node<T>* getHeadPtr();

	void setHeadPtr(Node<T>* pHead);

	void insert(Data& newData);
	void deleteList();
private:
	Node<T>* pHead;

	void insertAtFront(Data& newData);
	void deleteNode(Node<T>* pDelete);
};

// created 4/2/2025
// done
template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return pHead;
}

// created 4/2/2025
// done
template<class T>
void List<T>::setHeadPtr(Node<T>* pHead)
{
	this->pHead = pHead;
}

// created 4/2/2025
// done
template<class T>
inline void List<T>::insert(Data& newData)
{
	insertAtFront(newData);
}

// created 4/3/2025
// done
template<class T>
void List<T>::deleteList()
{
	Node<T>* pCur = pHead;

	while (pCur != nullptr) {
		deleteNode(pCur);
		pCur = pCur->getNextPtr();
	}
}

// created 4/2/2025
// done
template<class T>
void List<T>::insertAtFront(Data& newData)
{
	Node<T>* pMem = new Node<T>(newData);

	if (pHead == nullptr) {
		pHead = pMem;
	}
	else {
		pMem->setNextPtr(pHead);
		pHead = pMem;
	}
}

// created 4/3/2025
template<class T>
void List<T>::deleteNode(Node<T>* pDelete)
{
	pHead = pDelete->getNextPtr();
	pDelete->setNextPtr(nullptr);
	delete pDelete;
}


