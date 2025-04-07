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




/*
* Function name: List<T>::getHeadPtr()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Getter function for pHead;
* Input parameters: None
* Returns: Node<T>* pHead
*/
template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return pHead;
}




/*
* Function name: List<T>::setHeadPtr()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Setter function for pHead (changes the head pointer/node of the list)
* Input parameters: Node<T>* pHead is the new head pointer
* Returns: None
*/
template<class T>
void List<T>::setHeadPtr(Node<T>* pHead)
{
	this->pHead = pHead;
}




/*
* Function name: List<T>::insert()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Calls the insertAtFront() function
* Input parameters: Data &newData is a reference to a Data object and will be passed into the insert()
*					function
* Returns: None
*/
template<class T>
void List<T>::insert(Data& newData)
{
	insertAtFront(newData);
}




/*
* Function name: List<T>::deleteList()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Iterates through the list and calls deleteNode() with each node in the list (deletes the
*				entire list)
* Input parameters: None
* Returns: None
*/
template<class T>
void List<T>::deleteList()
{
	Node<T>* pCur = pHead;

	while (pCur != nullptr) {
		deleteNode(pCur);
		pCur = pCur->getNextPtr();
	}
}




/*
* Function name: List<T>::insertAtFront()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Creates a new node and inserts it to the front of the list by setting it as the head
*				pointer
* Input parameters:
* Returns:
*/
template<class T>
void List<T>::insertAtFront(Data& newData)
{
	Node<T>* pMem = new Node<T>(newData);

	if (pHead == nullptr) {
		// if there is no head pointer, set the head pointer to pMem
		pHead = pMem;
	}
	else {
		// if there already is a head pointer, have pMem point to the current head pointer and set the head pointer as pMem
		pMem->setNextPtr(pHead);
		pHead = pMem;
	}
}




/*
* Function name: List<T>::deleteNode()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Deletes the head pointer of the list
* Input parameters: Node<T> *pDelete is the Node the program is deleting from the list
* Returns: None
* Precondition: pDelete is the current head pointer of the list
*/
template<class T>
void List<T>::deleteNode(Node<T>* pDelete)
{
	pHead = pDelete->getNextPtr(); // pHead is the new head pointer of the node
	pDelete->setNextPtr(nullptr);
	delete pDelete;
}