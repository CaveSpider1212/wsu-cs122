/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the class template declaration and function definitions for the Node class template.
*/

#pragma once

template <class T>
class Node {
public:
	Node(const T& newData) : data(newData), pNext(nullptr) {};

	T& getData();
	Node* getNextPtr() const;

	void setNextPtr(Node* pNext);
private:
	T data;
	Node* pNext;
};




/*
* Function name: Node<T>::getData()
* Programmer: Aabhwan Adhikary
* Created: 3/31/2025
* Description: Getter function for data
* Input parameters: None
* Returns: T data (template, which will be replaced by the Data class)
*/
template<class T>
T& Node<T>::getData()
{
	return data;
}




/*
* Function name: Node<T>::getNextPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/31/2025
* Description: Getter function for pNext (returns the next pointer of this Node)
* Input parameters: None
* Returns: Node<T> *pNext;
*/
template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return pNext;
}




/*
* Function name: Node<T>::setNextPtr()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Setter function for pNext (sets this Node's next pointer)
* Input parameters: Node *pNext is the next pointer to this Node
* Returns: None
*/
template<class T>
void Node<T>::setNextPtr(Node* pNext)
{
	this->pNext = pNext;
}
