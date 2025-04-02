/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the function definitions of the main program.
*/

#include "Header.hpp"

void importCourseList()
{
	ifstream courseListFile;
	courseListFile.open("classList.csv", ios::in);

	string line;
	getline(courseListFile, line);

	while (getline(courseListFile, line)) {
		// iterates until there is no line in courseListFile to read
		std::stringstream ss(line);
		string token;
		cout << line << endl;
	}

	courseListFile.close();
}