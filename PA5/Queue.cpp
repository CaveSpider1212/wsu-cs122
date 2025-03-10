/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the function definitions for the Queue class.
*/

#include "Queue.hpp"




/*
* Function name: Queue::Queue()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This is a constructor for the Queue class, called when a Queue object is created with no parameters. It sets the
*				head and tail pointers of the queue to nullptr.
* Input parameters: none
* Returns: none
*/
Queue::Queue()
{
	pHead = pTail = nullptr;
}




/*
* Function name: Queue::Queue()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This is a constructor for the Queue class, called when a Queue object is created with a QueueNode parameter. It sets
*				the head and tail pointers to pMem, the QueueNode parameter, making it the only node in the queue.
* Input parameters: QueueNode *pMem, a node which will be the only node in the Queue
* Returns: none
*/
Queue::Queue(QueueNode* pMem)
{
	pHead = pTail = pMem;
}




/*
* Function name: Queue::printQueue()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function recursively prints out a Queue from the first node until the end of the Queue is reached.
* Input parameters: QueueNode *pCur is the head pointer of the Queue, and recursion will start here
* Returns: none
*/
void Queue::printQueue(QueueNode* pCur)
{
	if (pCur == nullptr) {
		return;
	}
	else {
		cout << "--> " << pCur->getData() << endl;
		printQueue(pCur->getNextPtr());
	}
}




/*
* Function name: Queue::isEmpty()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function determines whether a Queue is empty (by seeing if the head pointer is null).
* Input parameters: none
* Returns: bool representing if the Queue is empty (true) or not (false)
*/
bool Queue::isEmpty()
{
	if (pHead == nullptr) {
		return true;
	}

	return false;
}




/*
* Function name: Queue::enqueue()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function adds a node to the end of a queue.
* Input parameters: Data *newData is the data that will be added to the new node, which will be inserted at the end of the queue
* Returns: bool success, a boolean value representing whether the node was successfully created and inserted (true) or not (false)
*/
bool Queue::enqueue(Data *newData)
{
	bool success = false;
	QueueNode* pMem = new QueueNode(newData);

	if (pMem != nullptr) {
		// if the node was created successfully
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




/*
* Function name: Queue::dequeue()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function removes the node at the beginning of a queue.
* Input parameters: none
* Returns: Data *deletedData, the data of the node that was deleted
*/
Data* Queue::dequeue()
{
	Data* deletedData = nullptr;

	if (pHead != nullptr) {
		QueueNode* curHead = pHead;
		deletedData = curHead->getData();

		pHead = pHead->getNextPtr();
		delete curHead;
	}

	return deletedData;
}




/*
* Function name: Queue::getSumTimes()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function computes the sum of all service times of the customers currently in the queue and returns it.
* Input parameters: none
* Returns: int totalTime, the sum of the service times of all customers in the queue
*/
int Queue::getSumTimes()
{
	int totalTime = 0;
	QueueNode* pCur = pHead;
	while (pCur != nullptr) {
		// adds to totalTime until the program reaches the last pointer in the list
		totalTime += (*pCur->getData()).getServiceTime();
		pCur = pCur->getNextPtr();
	}

	return totalTime;
}




/*
* Function name: Queue::getHeadPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Getter function for pHead
* Input parameters: none
* Returns: QueueNode *pHead
*/
QueueNode* Queue::getHeadPtr()
{
	return pHead;
}
