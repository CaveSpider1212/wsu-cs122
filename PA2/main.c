/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 2
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/22/2025
* Description:
* Note: getChar() in the editRecords() function was obtained from "https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/"
*/

#include "Header.h"

int main(void)
{
	Node* records = NULL;
	FILE* musicPlaylist = NULL;
	int menuChoice = 0;

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
			break;
		case 5: // delete
			break;
		case 6: // edit
			editRecord(records);
			break;
		case 7: // sort
			break;
		case 8: // rate
			rateRecord(records);
			break;
		case 9: // play
			playRecord(records);
			break;
		case 10: // shuffle
			break;
		case 11: // exit
			storeIntoFile(musicPlaylist, records);
			break;
		default: // other number entered
			printf("Enter a number out of the options.\n");
		}
	}
	return 0;
}