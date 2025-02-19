/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 3
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/30/25
* Description: This program takes a list of records from a .csv file and stores them into a doubly linked list, allowing the
*				different fields to be modified, displayed, etc. as well as inserted, deleted, sorted, etc.
* Note: getChar() (used in the editRecords(), insertIntoRecords(), and deleteFromRecords() functions) was obtained from "https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/"
*/

#include "Header.h"
#include "testFunctions.h"

int main(void)
{
	Node* records = NULL;
	FILE* musicPlaylist = NULL;
	int menuChoice = 0;

	srand(time(NULL));

	while (menuChoice != 11) { // while user has not exited the program
		system("cls");

		mainMenu(&menuChoice);
		switch (menuChoice) {
		case 1: // load
			loadFromFile(musicPlaylist, &records);
			break;
		case 2: // store
			storeIntoFile(musicPlaylist, records);
			break;
		case 3: // display
			displayRecords(records);
			break;
		case 4: // insert
			insertIntoRecords(&records);
			break;
		case 5: // delete
			deleteFromRecords(&records);
			break;
		case 6: // edit
			editRecord(records);
			break;
		case 7: // sort
			sortRecords(records);
			break;
		case 8: // rate
			rateRecord(records);
			break;
		case 9: // play
			playRecord(records);
			break;
		case 10: // shuffle
			shuffleRecords(records);
			break;
		case 11: // exit
			storeIntoFile(musicPlaylist, records);
			break;
		default: // other number entered
			printf("Enter a number out of the options.\n");
		}
	}

	// testInsert();
	// testDelete();
	// testShuffle();

	return 0;
}