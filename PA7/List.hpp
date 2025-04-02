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

	void insertAtFront(Data& newData);
private:
	Node* pHead;
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


