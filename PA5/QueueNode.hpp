#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the class definition for the QueueNode class.
*/

#include "Data.hpp"

using std::cout;
using std::endl;

class QueueNode
{
public: // member functions
	QueueNode(Data *newData);

	Data* getData();
	QueueNode* getNextPtr();
	void setNextPtr(QueueNode* nextPtr);
private:
	// data of the node
	Data *pData;

	// next pointer of the node
	QueueNode* pNext;
};