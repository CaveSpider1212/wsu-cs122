#include "ListApp.h"

int main(void)
{
	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1: what function is called in the statement below?
	ListNode n1;

	// answer: constructor
	

	// Question 2: what function is called in the statement below?
	ListNode n2(42); // shallow or deep copy?

	// answer: constructor, deep copy

	
	// Question 3: what function is called in the statement below?
	ListNode n3(n2); // shallow or deep copy?

	// answer: copy constructor, shallow copy


	// Question 4: what function is called in the statement below?
	ListNode n4 = n3; // shallow or deep copy?

	// answer: copy constructor, shallow copy

	ListNode n5;
	// Question 5: what function/operator is called in the statement below?
	n5 = n4; // did we explicitly implement this function/operator? 

	// answer: doesn't call anything, did not explicitly implement overloaded = operator


	// Question 6: what function is called in the statement below?
	List l1;

	// answer: List constructor


	// make sure that you finish implementing the copy constructor for the List object before you try to 
	// execute the next statement!
	// Question 7: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	List l2 = l1; // shallow or deep copy?

	// answer: copy constructor; compiler generated one probably would not be good enough since it wouldn't do exactly what we want it to
	//			do; this is a deep copy


	// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	//             when the destructor for each list object is implicily invoked? l2 and l1 would have the same
	//             address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!


	List l3;
	// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	// execute the next statement!
	// Question 9: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	l3 = l2; // shallow or deep copy? 

	// answer: overloaded = operator; compiler generated one likely won't be good enough since it might not do exactly what we
	//			want it to do; this is a deep copy


	// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, 
	//              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	//              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!
	
	// answer: it calls the destroyList() function, which calls the destroyListHelper() function, which recursively goes through
	//			the nodes and deletes each node starting from the back to the front

	// ListApp app;
	// app.runApp();

	List testList1;
	for (int i = 0; i < 10; i++) {
		testList1.insertAtEnd(i);
	}
	testList1.deleteNode(4);
	testList1.deleteAtFront();
	testList1.deleteAtEnd();
	testList1.insertInOrder(7);
	testList1.printList();

	return 0;
}