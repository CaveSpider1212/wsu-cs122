/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the function definitions for the test functions.
*/

#include "Test.hpp"




/*
* Function name: testEnqueueEmpty()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This function tests the enqueue() function on an empty queue (should have one node in the queue after function is
*				finished calling).
*/
void testEnqueueEmpty()
{
	Queue q1;
	Data *newData = new Data(1, 5, 5);
	bool success = q1.enqueue(newData);

	if (success) {
		q1.printQueue(q1.getHeadPtr());
	}
	else {
		cout << "Unable to add customer to queue" << endl;
	}
}




/*
* Function name: testEnqueueOneNode()
* Programmer: Aabhwan Adhikary
* Created: 3/5/2025
* Description: This function tests the enqueue() function when there is already one node in the queue (should have two nodes in the
*				queue after function is finished calling).
*/
void testEnqueueOneNode()
{
	Data* firstData = new Data(1, 5, 5);
	QueueNode* firstNode = new QueueNode(firstData);

	Queue q1(firstNode);
	
	Data* newData = new Data(2, 4, 9);
	bool success = q1.enqueue(newData);

	if (success) {
		q1.printQueue(q1.getHeadPtr());
	}
	else {
		cout << "Unable to add customer to queue" << endl;
	}
}




/*
* Function name: testDequeueOneNode()
* Programmer: Aabhwan Adhikary
* Created: 3/5/2025
* Description: This function tests the dequeue() function on a queue with one node (should have an empty queue after function has
*				finished calling).
*/
void testDequeueOneNode()
{
	Queue q1;
	Data* newData = new Data(1, 5, 5);
	bool success = q1.enqueue(newData);

	q1.dequeue();
	q1.printQueue(q1.getHeadPtr());
}




/*
* Function name: testDequeueTwoNodes()
* Programmer: Aabhwan Adhikary
* Created: 3/5/2025
* Description: This function tests the dequeue() function on a queue with two nodes (should have a queue with one node after function
*				is finished calling).
*/
void testDequeueTwoNodes()
{
	Data* firstData = new Data(1, 5, 5);
	QueueNode* firstNode = new QueueNode(firstData);

	Queue q1(firstNode);

	Data* newData = new Data(2, 4, 9);
	bool success = q1.enqueue(newData);

	if (success) {
		q1.printQueue(q1.getHeadPtr());
	}
	else {
		cout << "Unable to add customer to queue" << endl;
	}

	q1.dequeue();
	q1.printQueue(q1.getHeadPtr());
}




/*
* Function name: runTwentyFourHours()
* Programmer: Aabhwan Adhikary
* Created: 3/6/2025
* Description: This function calls the runSimulation() function to run the simulation for 24 hours (1440 minutes).
*/
void runTwentyFourHours()
{
	runSimulation(1440);
}
