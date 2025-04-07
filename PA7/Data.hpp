/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the class declaration for the Data class.
*/

#pragma once

#include <string>
#include <stack>
#include <fstream>
#include <iostream>

using std::string;
using std::ios;
using std::ofstream;

class Data {
public:
	// Data(int recordNumber = 0, int idNumber = 0, string name = "", string email = "", string units = "", string program = "", string level = "");
	Data(int recordNumber, int idNumber, string name, string email, string units, string program, string level, int numAbsences, std::stack<string> absenceDates);

	int getRecordNumber() const;
	int getIdNumber() const;
	int getNumAbsences() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	std::stack<string>& getAbsenceDates();

	void setNumAbsences(int num);
private:
	int recordNumber, idNumber, numAbsences;
	string name, email, units, program, level;
	std::stack<string> absenceDates;
};

ofstream& operator << (ofstream& lhs, Data& rhs);