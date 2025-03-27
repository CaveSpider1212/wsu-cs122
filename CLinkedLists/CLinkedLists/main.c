// This example will illustrate how to implement and build applications with a linked
// list.

// History: 1/13/25 - Discussed lists. Defined our Movie struct (the same as the
//                    first example) and a Node struct.

#include "LinkedList.h"

int main(int argc, char* argv[])
{
	Node* pHead; // we now have a list
	int success = 0;
	Movie r1 = { .title = "Wicked", .year = 2024 }, r2 = { .title = "Interstellar", .year = 2014 }, r3 = { "G", 2012 };
	
	initList(&pHead); // sets list to empty

	/*
	success = insertFront(&pHead, r1);
	success = insertFront(&pHead, r2);
	*/

	success = insertInOrder(&pHead, r3);
	success = insertInOrder(&pHead, r2);
	success = insertInOrder(&pHead, r1);
	printList(pHead); // passes in the first node/list item


	destroyList(&pHead);
	printList(pHead);
	/*
	r1 = deleteFront(&pHead);

	printf("Deleted record: Title: %s, Year: %d\n", r1.title, r1.year);
	printList(pHead);
	*/

	// free(pHead)

	return 0;
}