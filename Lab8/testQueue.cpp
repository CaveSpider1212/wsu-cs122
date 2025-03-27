#include "testQueue.hpp"

void testEnqueue()
{
	Queue q1;
	q1.enqueue("test 1");
	q1.enqueue("test 2");

	q1.printQueueRecursive(q1.getHeadPtr());

	q1.enqueue("test 3");
	q1.enqueue("test 4");

	q1.printQueueRecursive(q1.getHeadPtr());
}

void testDequeue()
{
	Queue q1;
	q1.enqueue("test 1");
	q1.enqueue("test 2");
	q1.enqueue("test 3");
	q1.printQueueRecursive(q1.getHeadPtr());
	q1.dequeue();
	q1.printQueueRecursive(q1.getHeadPtr());

	std::cout << "-----------------------------------------------------" << std::endl;

	Queue q2;
	q2.dequeue();
	q2.printQueueRecursive(q2.getHeadPtr());
}