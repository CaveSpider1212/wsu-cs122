#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the class definition for the Data class.
*/

#include <iostream>

using std::ostream;

class Data
{
public: // member functions
	Data(int customerNum = 0, int servTime = 0, int totTime = 0);
	
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	void setServiceTime(int newTime);
private:
	// data values (number of the customer, service time, total time in line)
	int customerNumber, serviceTime, totalTime;
};

ostream& operator << (ostream& lhs, Data* rhs);