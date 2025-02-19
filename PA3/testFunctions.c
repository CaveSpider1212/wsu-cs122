/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 3
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 2/8/2025
* Description: This file contains all of the definitions for the test functions.
*/



#include "testFunctions.h"



/*
* Function name: testInsert()
* Programmer: Aabhwan Adhikary
* Created: 2/8/2025
* Description: Inserts a test record into the function using insertAtFront()
* Input parameters: None
* Returns: None
*/
void testInsert(void)
{
	Node* records = NULL;

	Duration newRecordDuration = { 4, 36 };
	Record newRecord = { "Perry, Katy", "Witness", "Chained to the Rhythm", "Pop", newRecordDuration, -1, 6 };

	insertAtFront(&records, newRecord);

	printList(records, NULL);
}




/*
* Function name: testDelete()
* Programmer: Aabhwan Adhikary
* Created: 2/8/2025
* Description: Inserts a test record into the linked list, and then deletes that same record from the list using deleteNodeByTitle()
* Input parameters: None
* Returns: None
*/
void testDelete(void)
{
	Node* records = NULL;

	Duration recordDuration = { 4, 36 };
	Record newRecord = { "Perry, Katy", "Witness", "Chained to the Rhythm", "Pop", recordDuration, 3, 5 };

	insertAtFront(&records, newRecord);

	int deleteSuccess = deleteNodeByTitle(&records, "Chained to the Rhythm");
	
	if (deleteSuccess) {
		printf("Deleted \"Chained to the Rhythm\"");
	}
}




/*
* Function name: testInsert()
* Programmer: Aabhwan Adhikary
* Created: 2/8/2025
* Description: Inserts records into the linked list, and provides an array representing the order in which the songs will be played
*				using the playInOrder() function
* Input parameters: None
* Returns: None
*/
void testShuffle(void)
{
	Node* records = NULL;
	
	Record r1 = { "Adele", "25", "Remedy", "Pop", {4, 11}, 24, 4 };
	Record r2 = { "Swift, Taylor", "1989", "Shake it Off", "Pop", {3, 35}, 12, 3 };
	Record r3 = { "Brooks, Garth", "FRESH HORSES", "The Old Stuff", "Country", {2, 57}, 11, 2 };

	insertAtFront(&records, r1);
	insertAtFront(&records, r2);
	insertAtFront(&records, r3);

	int playOrder[3] = { 3, 1, 2 };
	playInOrder(records, playOrder, countRecords(records));

	system("cls");
	printf("Finished playing.\n");
	system("pause");
}
