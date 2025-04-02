/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/31/2025
* Description: This file contains the declarations for the Menu class.
*/

#pragma once

#include "Data.hpp"
#include "Node.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ios;
using std::getline;
using std::string;
using std::stoi;

class Menu {
public:
	void start();
private:
	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void editAbsences();
	void generateReport();
};