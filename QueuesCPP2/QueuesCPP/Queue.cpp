#include "Queue.hpp"

Queue::~Queue()
{
	destroyQueue();
}

bool Queue::enqueue(const string& newData)
{
	Node* pMem = new Node(newData); // constructor for Node gets called here w/ new
	bool success = false;

	if (pMem != nullptr) {
		// allocated node in heap successfully
		if (this->mpHead == nullptr) {
			// empty queue
			this->mpHead = this->mpTail = pMem;
		}
		else {
			// the queue is not empty
			this->mpTail->setNextPtr(pMem);
			this->mpTail = pMem;
		}

		success = true;
	}

	return success;
}

// precondition: queue must not be empty
string Queue::dequeue()
{
	string data = this->mpHead->getData();
	Node* pTemp = this->mpHead; // pTemp refers to the node to delete

	if (this->mpHead == this->mpTail) {
		// one node in queue
		this->mpTail = nullptr;
	}

	this->mpHead = this->mpHead->getNextPtr();

	delete pTemp; // invoke the destructor for the object that's removed - Node's destructor
	cout << "finished removing node" << endl;

	return data;
}

bool Queue::isEmpty() const
{
	return this->mpHead == nullptr && this->mpTail == nullptr;
}

void Queue::destroyQueue()
{
	while (!isEmpty()) {
		dequeue();
	}
}
