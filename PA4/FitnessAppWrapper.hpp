#pragma once

/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the class definition, function prototypes, and data members of the FitnessAppWrapper class.
*/

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "Header.hpp"

class FitnessAppWrapper {
public:
	// public member functions
	void runApp(void);
	int displayMenu(void);
private:
	// data members
	DietPlan weeklyDietPlans[7];
	ExercisePlan weeklyExercisePlans[7];

	// private member functions
	void loadDailyPlan(ifstream& fileStream, DietPlan& plan);
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);

	void loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(ifstream& fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(DietPlan plan);
	void displayDailyPlan(ExercisePlan plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[7]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[7]);

	void storeDailyPlan(ofstream& fileStream, DietPlan plan);
	void storeDailyPlan(ofstream& fileStream, ExercisePlan plan);

	void storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[7]);
	void storeWeeklyPlan(ofstream& fileStream, ExercisePlan weeklyPlan[7]);

	// other functions
	int isEmpty(DietPlan weeklyPlan[7]);
	int isEmpty(ExercisePlan weeklyPlan[7]);

	int findIndexOfDate(DietPlan weeklyPlan[7], string date);
	int findIndexOfDate(ExercisePlan weeklyPlan[7], string date);
};