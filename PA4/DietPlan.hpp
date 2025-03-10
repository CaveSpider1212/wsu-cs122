#pragma once

/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the class definition, function prototypes, and data members of the DietPlan class.
*/

#include "Header.hpp"

class DietPlan {
public:
	// constructors/destructors
	DietPlan(int goal = 0, string name = "", string date = ""); // constructor
	DietPlan(DietPlan& p); // copy constructor
	~DietPlan();

	// getter functions
	int getGoalCalories();
	string getPlanName();
	string getPlanDate();

	// setter functions
	void setGoalCalories(int goal);
	void setPlanName(string name);
	void setPlanDate(string date);

	// member functions
	void editGoal();

private:
	// data members
	int goalCalories;
	string planName, planDate;
};

// overloaded operators
ostream& operator << (ostream& lhs, DietPlan& rhs);
ofstream& operator << (ofstream& lhs, DietPlan& rhs);
ifstream& operator >> (ifstream &lhs, DietPlan& rhs);