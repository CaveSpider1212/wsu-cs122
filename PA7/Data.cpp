/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 7
* Created: 3/28/2025
* Description: This file contains the function definitions for the Data class.
*/

#include "Data.hpp"




/*
* Function name: Data::Data
* Programmer: Aabhwan Adhikary
* Created: 4/6/2025
* Description: Constructor for the Data class
* Input parameters: All parameters are set as the object's data members
*/
Data::Data(int recordNumber, int idNumber, string name, string email, string units, string program, string level, int numAbsences, std::stack<string> absenceDates)
{
	this->recordNumber = recordNumber;
	this->idNumber = idNumber;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->level = level;
	this->numAbsences = numAbsences;
	this->absenceDates = absenceDates;
}




/*
* Function name: Data::getRecordNumber()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for recordNumber
* Input parameters: None
* Returns: int recordNumber
*/
int Data::getRecordNumber() const
{
	return recordNumber;
}




/*
* Function name: Data::getIdNumber()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for idNumber
* Input parameters: None
* Returns: int idNumber
*/
int Data::getIdNumber() const
{
	return idNumber;
}




/*
* Function name: Data::getNumAbsences()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for numAbsences
* Input parameters: None
* Returns: int numAbsences
*/
int Data::getNumAbsences() const
{
	return numAbsences;
}




/*
* Function name: Data::getName()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for name
* Input parameters: None
* Returns: string name
*/
string Data::getName() const
{
	return name;
}




/*
* Function name: Data::getEmail()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for email
* Input parameters: None
* Returns: string email
*/
string Data::getEmail() const
{
	return email;
}




/*
* Function name: Data::getUnits()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for units
* Input parameters: None
* Returns: string units
*/
string Data::getUnits() const
{
	return units;
}




/*
* Function name: Data::getProgram()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for program
* Input parameters: None
* Returns: string program
*/
string Data::getProgram() const
{
	return program;
}




/*
* Function name: Data::getLevel()
* Programmer: Aabhwan Adhikary
* Created: 4/3/2025
* Description: Getter function for level
* Input parameters: None
* Returns: string level
*/
string Data::getLevel() const
{
	return level;
}




/*
* Function name: Data::getAbsenceDates()
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Getter function for absenceDates
* Input parameters: None
* Returns: std::stack<string> &absenceDates
*/
std::stack<string>& Data::getAbsenceDates()
{
	return absenceDates;
}




/*
* Function name: Data::setNumAbsences()
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Setter function for numAbsences
* Input parameters: int num, which will be set to numAbsences
* Returns: None
*/
void Data::setNumAbsences(int num)
{
	numAbsences = num;
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 4/4/2025
* Description: Overloaded << operator which outputs the rhs (Data) attributes to an output file stream
* Input parameters: ofstream &lhs is a reference to the output file stream; Data &rhs is a reference to
*					the Data object of a Node/student
* Returns: ofstream &lhs
*/
ofstream& operator<<(ofstream& lhs, Data& rhs)
{
	lhs << rhs.getRecordNumber() << ",";
	lhs << rhs.getIdNumber() << ",";
	lhs << "\"" << rhs.getName() << "\",";
	lhs << rhs.getEmail() << ",";
	lhs << rhs.getUnits() << ",";
	lhs << rhs.getProgram() << ",";
	lhs << rhs.getLevel() << ",";
	lhs << rhs.getNumAbsences();

	if (!rhs.getAbsenceDates().empty()) {
		std::stack<string> removedDates;

		while (!rhs.getAbsenceDates().empty()) {
			// prints out the top value of the stack, then removes it and adds it to the removedDates stack, and repeats until rhs absenceDates stack is empty
			string currentDate = rhs.getAbsenceDates().top();
			lhs << "," << currentDate;
			rhs.getAbsenceDates().pop();
			removedDates.push(currentDate);
		}

		while (!removedDates.empty()) {
			// removes the top value from the removedDates stack and pushes it to the rhs absenceDates stack, and repeat until the removedDates stack is empty
			string currentDate = removedDates.top();
			removedDates.pop();
			rhs.getAbsenceDates().push(currentDate);
		}
	}

	lhs << "\n";

	return lhs;
}
