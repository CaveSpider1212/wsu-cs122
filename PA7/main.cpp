/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/28/2025
* Description: This program uses class templates to simulate an attendance tracker where the program reads in records of
*				students from a text file, mark students absent, and generate reports.
*/

#include "Header.hpp"

int main(void)
{
	int menuChoice = 0;
	
	while (menuChoice != 7) {
		cout << "Choose a menu option from below:" << endl;
		cout << "1) Import course list\n2) Load master list\n3) Store master list\n4) Mark absences\n5) Edit absences\n6) Generate report\n7) Exit" << endl;
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			importCourseList();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}

	return 0;
}