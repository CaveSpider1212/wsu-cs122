#pragma once

#include "QueueNode.hpp"

class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty();
	bool enqueue(const std::string& newData);
	std::string dequeue();
	void printQueueRecursive(QueueNode* pCur);

	QueueNode* getHeadPtr();
private:
	QueueNode* pHead, * pTail;
};