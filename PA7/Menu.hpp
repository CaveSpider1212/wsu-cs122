/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the declarations for the Menu class.
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Data.hpp"
#include "Node.hpp"
#include "List.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::getline;
using std::string;
using std::stoi;

class Menu {
public:
	void start();
private:
	List<Data> masterList;

	// menu operations
	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void generateReport();

	// helper functions
	void readDataValues(string line, int* recordNum, int* id, string *name, string *email, string *units, string *program, string *level, int *numAbsences, std::stack<string>& absenceDates, bool readingDates);
	void displayAllStudents();
	void displaySomeStudents();
	void markStudentAsAbsent(Node<Data>* pCur);
};