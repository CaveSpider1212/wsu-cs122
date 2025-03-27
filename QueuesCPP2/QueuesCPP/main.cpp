// We'll work on implementing a Queue data structure in C++.

// History: 2/19/25 - Added the necessary data members to the class Node and class Queue. We
//                    declared the enqueue () function. We'll define in lecture on Fri, 2/21.

#include "Queue.hpp"

int main(void)
{
	Queue q;

	q.enqueue("PJ1");

	if (!q.isEmpty()) {
		q.dequeue();
	}

	return 0;
}