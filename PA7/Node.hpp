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

	T getData() const;
	Node* getNextPtr() const;
private:
	T data;
	Node* pNext;
};

// created 3/31/2025
// done
template<class T>
T Node<T>::getData() const
{
	return data;
}

// created 3/31/2025
// done
template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return pNext;
}