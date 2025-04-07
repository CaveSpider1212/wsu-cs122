/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the function definitions for the Menu class.
*/

#include "Menu.hpp"




/*
* Function name: Menu::start()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Displays the start menu to the console and allows the user to select a menu operation
*/
void Menu::start()
{
	int menuChoice = 0;

	while (menuChoice != 7) {
		cout << "Choose a menu option from below:" << endl;
		cout << "1) Import course list\n2) Load master list\n3) Store master list\n4) Mark absences\n6) Generate report\n7) Exit" << endl;
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			importCourseList();
			break;
		case 2:
			loadMasterList();
			break;
		case 3:
			storeMasterList();
			break;
		case 4:
			markAbsences();
			break;
		case 6:
			generateReport();
			break;
		}
	}
}




/*
* Function name: Menu::importCourseList()
* Programmer: Aabhwan Adhikary
* Created: 4/2/2025
* Description: Imports the list of students and the data from the class list file
*/
void Menu::importCourseList()
{
	// destroys the master list and clears the master list file
	masterList.deleteList();
	ofstream masterFile;
	masterFile.open("master.csv", ios::out);
	masterFile.close();

	ifstream courseListFile;
	courseListFile.open("classList.csv", ios::in);

	// reads the first line in the file
	string line;
	getline(courseListFile, line);

	while (getline(courseListFile, line)) {
		// iterates until there is no line in courseListFile to read, reads each token in the line separated by ','
		int recordNum = 0, id = 0, numAbsences = 0;
		string name = "", email = "", units = "", program = "", level = "";
		std::stack<string> absenceDates;

		readDataValues(line, &recordNum, &id, &name, &email, &units, &program, &level, &numAbsences, absenceDates, false);

		Data newStudentData(recordNum, id, name, email, units, program, level, numAbsences, std::stack<string>());
		masterList.insert(newStudentData);
	}

	cout << "\nCourse list data has been imported to the master list.\n" << endl;

	courseListFile.close();
}




/*
* Function name: Menu::loadMasterList()
* Programmer: Aabhwan Adhikary
* Created: 4/5/2025
* Description: Imports the list of students and the data (including absences) from the master list file
*/
void Menu::loadMasterList()
{
	ifstream masterFile;
	masterFile.open("master.csv", ios::in);

	string line;

	while (getline(masterFile, line)) {
		// iterates until there is no line in courseListFile to read, reads each token in the line separated by ','
		int recordNum = 0, id = 0, numAbsences = 0;
		string name = "", email = "", units = "", program = "", level = "";
		std::stack<string> absenceDates;

		readDataValues(line, &recordNum, &id, &name, &email, &units, &program, &level, &numAbsences, absenceDates, true);

		Data newStudentData(recordNum, id, name, email, units, program, level, numAbsences, absenceDates);
		masterList.insert(newStudentData);
	}

	cout << "\nMaster list file data has been imported to the master list of students.\n" << endl;

	masterFile.close();
}




/*
* Function name: Menu::storeMasterList()
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Stores the list of students and their data (including absences) to the master list file
*/
void Menu::storeMasterList()
{
	ofstream masterFile;
	masterFile.open("master.csv", ios::out);

	Node<Data>* pCur = masterList.getHeadPtr();
	while (pCur != nullptr) {
		Data currentStudentData = pCur->getData();
		masterFile << currentStudentData;
		pCur = pCur->getNextPtr();
	}

	cout << "\nMaster list has been stored in the master data file.\n" << endl;
}




/*
* Function name: Menu::markAbsences()
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Iterates through linked list of students and prompts the user about if they are absent
*				or not
*/
void Menu::markAbsences()
{
	Node<Data>* pCur = masterList.getHeadPtr();
	while (pCur != nullptr) {
		char isAbsent = '\0';
		cout << "\nIs the student \"" << pCur->getData().getName() << "\" absent today? (y/n)" << endl;
		cin >> isAbsent;

		if (isAbsent == 'y') {
			markStudentAsAbsent(pCur);
		}

		pCur = pCur->getNextPtr();
	}
}



/*
* Function name: Menu::generateReport()
* Programmer: Aabhwan Adhikary
* Created: 4/5/2025
* Description: Prompts the user for which submenu to display and calls the corresponding function
*/
void Menu::generateReport()
{
	int reportNum = 0;
	cout << "\nWhich report do you want to display? (type the number):" << endl;
	cout << "1) Show all students in the class and the number of times they've been absent, as well as the date of their most recent absence" << endl;
	cout << "2) Show all students who have been absent a greater number of times than a threshold you set" << endl;
	cin >> reportNum;

	switch (reportNum) {
	case 1:
		displayAllStudents();
		break;
	case 2:
		displaySomeStudents();
		break;
	}
}




/*
* Function name: Menu::readDataValues
* Programmer: Aabhwan Adhikary
* Created: 4/6/2025
* Description: Reads tokens from a line into the different Data fields for each student
* Input parameters: string line is the line the program is reading tokens out of; bool readingDates
*					indicates whether the program should read dates/absences as well (true) or not (false);
*					remaining parameters are pointers/references to the Data attributes of each student/Node
*/
void Menu::readDataValues(string line, int* recordNum, int* id, string *name, string *email, string *units, string *program, string *level, int *numAbsences, std::stack<string>& absenceDates, bool readingDates)
{
	std::stringstream ss(line);
	string token;

	getline(ss, token, ',');
	*recordNum = stoi(token);

	getline(ss, token, ',');
	*id = stoi(token);

	getline(ss, token, '"');

	getline(ss, token, '"');
	*name = token;

	getline(ss, token, ',');

	getline(ss, token, ',');
	*email = token;

	getline(ss, token, ',');
	*units = token;

	getline(ss, token, ',');
	*program = token;

	getline(ss, token, ',');
	*level = token;

	if (readingDates) {
		getline(ss, token, ',');
		*numAbsences = stoi(token);

		std::stack<string> datesReversed;

		for (int i = 0; i < *numAbsences; i++) {
			// iterates through the absence dates and pushes it into the datesReversed stack
			getline(ss, token, ',');
			datesReversed.push(token);
		}
		// datesReversed should now have the most recent date at the bottom and the earliest date at the top of the stack

		for (int i = 0; i < *numAbsences; i++) {
			absenceDates.push(datesReversed.top());
			datesReversed.pop();
		}
	}
}




/*
* Function name: Menu::displayAllStudents()
* Programmer: Aabhwan Adhikary
* Created: 4/5/2025
* Description: Report submenu #1; outputs a list of all students in the class list to another text file,
*				showing the number of absences and the date of the most recent absence
*/
void Menu::displayAllStudents()
{
	ofstream allStudents;
	allStudents.open("allStudents.txt", ios::out);

	Node<Data>* pCur = masterList.getHeadPtr();
	while (pCur != nullptr) {
		if (pCur->getData().getAbsenceDates().empty()) {
			allStudents << "\"" << pCur->getData().getName() << "\" - 0 absences - Most recent absence: N/A" << endl;
		}
		else {
			allStudents << "\"" << pCur->getData().getName() << "\" - " << pCur->getData().getNumAbsences() << " absences - Most recent absence: " << pCur->getData().getAbsenceDates().top() << endl;
		}

		pCur = pCur->getNextPtr();
	}

	allStudents.close();
	cout << "\nList of students has been displayed in \"allStudents.txt\".\n" << endl;
}




/*
* Function name: Menu::displaySomeStudents
* Programmer: Aabhwan Adhikary
* Created: 4/5/2025
* Description: Report submenu #2; outputs a list of all students to another text file who has been
*				absent more times than a threshold number set by the user (also set in this function)
*/
void Menu::displaySomeStudents()
{
	ofstream someStudents;
	someStudents.open("someStudents.txt", ios::out);

	int threshold = 0;
	cout << "\nWhat is the minimum threshold of absences to display? (Students with at least this many absences will be displayed):" << endl;
	cin >> threshold;

	Node<Data>* pCur = masterList.getHeadPtr();
	while (pCur != nullptr) {
		if (pCur->getData().getNumAbsences() > threshold) {
			someStudents << pCur->getData().getName() << endl;
		}
		
		pCur = pCur->getNextPtr();
	}

	someStudents.close();
	cout << "\nList of students has been displayed in \"someStudents.txt\".\n" << endl;
}




/*
* Function name: Menu::markStudentAsAbsent()
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Called if a student is marked absent; obtains the current date of the computer and pushes
*				that date to the list of absent dates stack of the current Node/student
* Input parameters: Node<Data>* pCur is a node representing the current student (and also the absent one);
*					the program will push the current date to the top of this Node's stack
*/
void Menu::markStudentAsAbsent(Node<Data>* pCur)
{
	time_t t = time(0);
	struct tm* now = localtime(&t);
	
	string absenceDate = std::to_string((now->tm_year + 1900)) + "-" + std::to_string((now->tm_mon + 1)) + "-" + std::to_string(now->tm_mday);
	/*
	* std::to_string() was obtained from "https://www.freecodecamp.org/news/int-to-string-in-cpp-how-to-convert-an-integer-with-tostring/"
	*/

	cout << "\"" << pCur->getData().getName() << "\" has been marked absent on " << absenceDate << "." << endl;

	pCur->getData().getAbsenceDates().push(absenceDate); // pushes the current data (absence date) to the stack
	pCur->getData().setNumAbsences(pCur->getData().getNumAbsences() + 1); // increases the number of absences by 1
}
