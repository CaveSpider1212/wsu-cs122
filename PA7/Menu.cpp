/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the function definitions for the Menu class.
*/

#include "Menu.hpp"

// created 4/2/2025
void Menu::start()
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
}

// created 4/2/2025
// done, could maybe split into another function
void Menu::importCourseList()
{
	masterList.deleteList();

	ifstream courseListFile;
	courseListFile.open("classList.csv", ios::in);

	string line;
	getline(courseListFile, line);

	while (getline(courseListFile, line)) {
		// iterates until there is no line in courseListFile to read, reads each token in the line separated by ','
		std::stringstream ss(line);
		string token;

		getline(ss, token, ',');
		int recordNum = stoi(token);

		getline(ss, token, '"');
		int id = stoi(token);

		getline(ss, token, '"');
		string name = token;

		getline(ss, token, ',');
		string email = token;

		getline(ss, token, ',');
		string units = token;

		getline(ss, token, ',');
		string program = token;

		getline(ss, token, ',');
		string level = token;

		Data newStudentData(recordNum, id, name, email, units, program, level);
		masterList.insert(newStudentData);
	}

	courseListFile.close();
}