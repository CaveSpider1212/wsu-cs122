#include "Queue.hpp"

Queue::Queue()
{
	pHead = pTail = nullptr;
}

Queue::~Queue()
{
	while (!this->isEmpty()) {
		this->dequeue();
	}

	std::cout << "Deleted queue" << std::endl;
}

bool Queue::isEmpty()
{
	if (pHead == nullptr) {
		return true;
	}

	return false;
}

bool Queue::enqueue(const std::string& newData)
{
	bool success = false;
	QueueNode* pMem = new QueueNode(newData);

	if (pMem != nullptr) {
		success = true;

		if (pHead == nullptr) {
			pHead = pTail = pMem;
		}
		else {
			pTail->setNextPtr(pMem);
			pTail = pMem;
		}
	}

	return success;
}

std::string Queue::dequeue()
{
	std::string data = "";

	if (pHead != nullptr) {
		QueueNode* curHead = pHead;
		data = curHead->getData();

		pHead = pHead->getNextPtr();
		delete curHead;
	}
	else {
		std::cout << "Unable to delete, head pointer is null" << std::endl;
	}

	return data;
}

void Queue::printQueueRecursive(QueueNode* pCur)
{
	if (pCur == nullptr) {
		return;
	}
	else {
		std::cout << pCur->getData() << std::endl;
		printQueueRecursive(pCur->getNextPtr());
	}
}

QueueNode* Queue::getHeadPtr()
{
	return pHead;
}
