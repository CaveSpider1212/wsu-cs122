#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the class definition for the Queue class.
*/

#include "QueueNode.hpp"

class Queue
{
public: // member functions
	Queue();
	Queue(QueueNode* pMem);

	void printQueue(QueueNode *pCur);
	bool isEmpty();
	bool enqueue(Data *newData);
	Data* dequeue();

	int getSumTimes();
	QueueNode* getHeadPtr();
private:
	// head and tail pointers of the queue
	QueueNode* pHead, * pTail;
};