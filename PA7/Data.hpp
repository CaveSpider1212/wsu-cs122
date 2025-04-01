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

using std::string;
using std::ios;

class Data {
public:
	Data(int recordNumber, int idNumber, string name, string email, string units, string program, string level);
private:
	int recordNumber, idNumber, numAbsences;
	string name, email, units, program, level;
	std::stack<string> absenceDates;
};