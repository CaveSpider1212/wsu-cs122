/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/28/2025
* Description: This file contains the function definitions for the Data class.
*/

#include "Data.hpp"

Data::Data(int recordNumber, int idNumber, string name, string email, string units, string program, string level)
{
	this->recordNumber = recordNumber;
	this->idNumber = idNumber;
	this->numAbsences = 0;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->level = level;
}
