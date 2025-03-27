// LAB 2 - 1/23/25

#include "Header.h"

int main(void)
{
	Node* pHead = NULL;
	Boolean success = FALSE;

	Contact c1 = { "Todd", "18888888888", "todd@gmail.com", "Boss" },
		c2 = { "Paul", "15555555555", "paul@gmail.com", "Worker" },
		c3 = { "Steve", "13333333333", "steve@gmail.com", "Truck Driver" },
		c4 = { "Will", "14444444444", "will@gmail.com", "Friend" };

	success = insertContactInOrder(&pHead, c1);
	success = insertContactInOrder(&pHead, c2);
	success = insertContactInOrder(&pHead, c3);
	success = insertContactInOrder(&pHead, c4);
	// printList(pHead);
	
	return 0;
}