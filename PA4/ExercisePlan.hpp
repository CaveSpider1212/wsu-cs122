#pragma once

/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the class definition, function prototypes, and data members of the ExercisePlan class.
*/

#include "Header.hpp"

class ExercisePlan {
public:
	// constructors/destructors
	ExercisePlan(int goal = 0, string name = "", string date = ""); // constructor
	ExercisePlan(ExercisePlan& p); // copy constructor
	~ExercisePlan();

	// getter functions
	int getGoalSteps();
	string getPlanName();
	string getPlanDate();

	// setter functions
	void setGoalSteps(int goal);
	void setPlanName(string name);
	void setPlanDate(string date);

	// member functions
	void editGoal();

private:
	// data members
	int goalSteps;
	string planName, planDate;
};

// overloaded operators
ostream& operator << (ostream& lhs, ExercisePlan& rhs);
ofstream& operator << (ofstream& lhs, ExercisePlan& rhs);
ifstream& operator >> (ifstream& lhs, ExercisePlan& rhs);