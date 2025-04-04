/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/28/2025
* Description: This file contains the function definitions for the Data class.
*/

#include "Data.hpp"

// created 3/31/2025
// done
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

// created 4/3/2025
// done
int Data::getRecordNumber() const
{
	return recordNumber;
}

// created 4/3/2025
// done
int Data::getIdNumber() const
{
	return idNumber;
}

// created 4/3/2025
// done
int Data::getNumAbsences() const
{
	return numAbsences;
}

// created 4/3/2025
// done
string Data::getName() const
{
	return name;
}

// created 4/3/2025
// done
string Data::getEmail() const
{
	return email;
}

// created 4/3/2025
// done
string Data::getProgram() const
{
	return program;
}

// created 4/3/2025
// done
string Data::getLevel() const
{
	return level;
}