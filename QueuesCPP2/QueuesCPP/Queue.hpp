#pragma once

#include <iostream>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue() { mpHead = mpTail = nullptr; }

	~Queue();

	bool enqueue(const string& newData);
	// precondition: queue must not be empty
	string dequeue();

	// predicate function
	bool isEmpty() const;
private:
	// A queue has two pointers - one to track the front/head and one to track the end/tail
	// The two pointers allow for a more efficient way of inserting and deleting items in the queue
	Node* mpHead,
		* mpTail;

	void destroyQueue();
};