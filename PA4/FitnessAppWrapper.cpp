/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the function definitions of the FitnessAppWrapper class.
*/

#include "FitnessAppWrapper.hpp"




/*
* Function name: runApp()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function runs the main fitness application.
* Input parameters: None
* Returns: None
*/
void FitnessAppWrapper::runApp(void)
{
	int menuChoice = 0;

	ifstream dietInput, exerciseInput;
	ofstream dietOutput, exerciseOutput;

	while (menuChoice != 9) { // while user hasn't exited the program yet
		menuChoice = displayMenu();

		if (menuChoice == 1) { // load diet plan from file
			dietInput.open("dietPlans.txt", ios::in);
			loadWeeklyPlan(dietInput, weeklyDietPlans);
			dietInput.close();
		}
		else if (menuChoice == 2) { // load exercise plan from file
			exerciseInput.open("exercisePlans.txt", ios::in);
			loadWeeklyPlan(exerciseInput, weeklyExercisePlans);
			exerciseInput.close();
		}
		else if (menuChoice == 3) { // store diet plan into file

			// checks that the list is not empty
			if (!isEmpty(weeklyDietPlans)) {
				dietOutput.open("dietPlans.txt", ios::out);
				storeWeeklyPlan(dietOutput, weeklyDietPlans);
				dietOutput.close();
			}
			else {
				cout << "Cannot store diet plans since the list is empty" << endl;
			}
		}
		else if (menuChoice == 4) { // store exercise plan into file

			// checks that the list is not empty
			if (!isEmpty(weeklyExercisePlans)) {
				exerciseOutput.open("exercisePlans.txt", ios::out);
				storeWeeklyPlan(exerciseOutput, weeklyExercisePlans);
				exerciseOutput.close();
			}
			else {
				cout << "Cannot store exercise plans since the list is empty" << endl;
			}
		}
		else if (menuChoice == 5) { // display diet plan
			displayWeeklyPlan(weeklyDietPlans);
		}
		else if (menuChoice == 6) { // display exercise plan
			displayWeeklyPlan(weeklyExercisePlans);
		}
		else if (menuChoice == 7) { // edit diet plan
			string editDate;
			cout << "Which date's goal do you want to edit?" << endl;
			cin >> editDate;

			int index = findIndexOfDate(weeklyDietPlans, editDate);
			
			if (index != -1) {
				weeklyDietPlans[index].editGoal();
			}
		}
		else if (menuChoice == 8) { // edit exercise plan
			string editDate;
			cout << "Which date's goal do you want to edit?" << endl;
			cin >> editDate;

			int index = findIndexOfDate(weeklyExercisePlans, editDate);

			if (index != -1) {
				weeklyExercisePlans[index].editGoal();
			}
		}
		else if (menuChoice == 9) { // exit
			if (!isEmpty(weeklyDietPlans) && !isEmpty(weeklyExercisePlans)) {
				dietOutput.open("dietPlans.txt", ios::out);
				exerciseOutput.open("exercisePlans.txt", ios::out);

				storeWeeklyPlan(dietOutput, weeklyDietPlans);
				storeWeeklyPlan(exerciseOutput, weeklyExercisePlans);

				dietOutput.close();
				exerciseOutput.close();
			}
			else {
				cout << "Cannot store lists into file since at least one of them is empty" << endl;
			}
		}
		else {
			cout << "Enter one of the numbers." << endl;
		}
	}
}




/*
* Function name: displayMenu()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function shows the menu options of the program
* Input parameters: None
* Returns: int menuOption, which takes in user input for one of the menu choices
*/
int FitnessAppWrapper::displayMenu(void)
{
	int menuOption = 0;

	cout << "Choose a menu option from below:" << endl;
	cout << "1) Load weekly diet plan from file" << endl;
	cout << "2) Load weekly exercise plan from file" << endl;
	cout << "3) Store weekly diet plan to file" << endl;
	cout << "4) Store weekly exercise plan to file" << endl;
	cout << "5) Display weekly diet plan to screen" << endl;
	cout << "6) Display weekly exercise plan to screen" << endl;
	cout << "7) Edit daily diet plan" << endl;
	cout << "8) Edit daily exercise plan" << endl;
	cout << "9) Exit" << endl;

	cin >> menuOption;
	return menuOption;
}




/*
* Function name: loadDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function loads a particular day's diet plan from the file using the overloaded >> operator.
* Input parameters: ifstream &fileStream is a reference to the input file stream the program is reading out of; DietPlan &plan is 
					the particular day's diet plan
* Returns: None
*/
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}




/*
* Function name: loadDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function loads a particular day's exercise plan from the file using the overloaded >> operator.
* Input parameters: ifstream &fileStream is a reference to the input file stream the program is reading out of; ExercisePlan &plan is
					the particular day's exercise plan
* Returns: None
*/
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}




/*
* Function name: loadWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function loads the week's diet plans from the text file by calling loadDailyPlan() in a loop.
* Input parameters: ifstream &fileStream is a reference to the input file stream the program is reading out of; DietPlan weeklyPlan[] 
					is the array of diet plans for the week
* Returns: None
*/
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}

	cout << "Loaded weekly diet plan" << endl;
}




/*
* Function name: loadWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function loads the week's exercise plans from the text file by calling loadDailyPlan() in a loop.
* Input parameters: ifstream &fileStream is a reference to the input file stream the program is reading out of; ExercisePlan weeklyPlan[]
					is the array of exercise plans for the week
* Returns: None
*/
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}

	cout << "Loaded weekly exercise plan" << endl;
}




/*
* Function name: displayDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function displays the day's diet plan to the screen using the overloaded << operator.
* Input parameters: DietPlan plan is the current day's diet plan
* Returns: None
*/
void FitnessAppWrapper::displayDailyPlan(DietPlan plan)
{
	cout << plan << endl;
}




/*
* Function name: displayDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function displays the day's exercise plan to the screen using the overloaded << operator.
* Input parameters: ExercisePlan plan is the current day's exercise plan
* Returns: None
*/
void FitnessAppWrapper::displayDailyPlan(ExercisePlan plan)
{
	cout << plan << endl;
}




/*
* Function name: displayWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function displays the week's diet plans to the screen by calling displayDailyPlan() in a loop.
* Input parameters: DietPlan weeklyPlan[7] is the array of diet plans for the week
* Returns: None
*/
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}




/*
* Function name: displayWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This functions displays the week's exercise plans to the screen by calling displayDailyPlan() in a loop.
* Input parameters: ExercisePlan weeklyPlan[7] is the array of exercise plans for the week
* Returns: None
*/
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}




/*
* Function name: storeDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/20/2025
* Description: This function stores a particular day's diet plan into the text file using the overloaded << operator.
* Input parameters: ofstream &fileStream is a reference to the output file stream, which the program will be writing to; DietPlan plan is
*					the current day's diet plan to be written to the file
* Returns: None
*/
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan plan)
{
	fileStream << plan;
}




/*
* Function name: storeDailyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function stores a particular day's exercise plan into the text file using the overlodaed << operator.
* Input parameters: ofstream &fileStream is a reference to the output file stream, which the program will be writing to; ExercisePlan 
					plan is the current day's exercise plan to be written to the file
* Returns: None
*/
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan plan)
{
	fileStream << plan;
}




/*
* Function name: storeWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function stores the week's diet plans into the text file by calling storeDailyPlan() in a loop.
* Input parameters: ofstream &fileStream is a reference to the output file stream, which the program will be writing; DietPlan
*					weeklyPlan[7] is the array of diet plans for the week
* Returns: None
*/
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}

	cout << "Stored weekly diet plan" << endl;
}




/*
* Function name: storeWeeklyPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function stores the week's exercise plans into the text file by calling storeDailyPlan() in a loop.
* Input parameters: ofstream &fileStream is a reference to the output file stream, which the program will be reading out of; ExercisePlan
*					weeklyPlan[7] is the array of exercise plans for the week
* Returns: None
*/
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, ExercisePlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}




/*
* Function name: isEmpty()
* Programmer: Aabhwan Adhikary
* Created: 2/20/2025
* Description: This function loops through the diet plans array to check if it is empty.
* Input parameters: DietPlan weeklyPlan[7] is the array the program is checking to see if it is empty or not
* Returns: int empty, integer representing whether the DietPlan array is empty (1) or not (0)
*/
int FitnessAppWrapper::isEmpty(DietPlan weeklyPlan[7])
{
	int empty = 1;

	for (int i = 0; i < 7; i++) {
		// checks if any of the fields are different than the default values, if so then the list is not empty
		if (weeklyPlan[i].getPlanName() != "" || weeklyPlan[i].getGoalCalories() != 0 || weeklyPlan[i].getPlanDate() != "") {
			empty = 0;
			break;
		}
	}

	return empty;
}




/*
* Function name: isEmpty()
* Programmer: Aabhwan Adhikary
* Created: 2/20/2025
* Description: This function loops through the exercise plans array to check if it is empty.
* Input parameters: ExercisePlan weeklyPlan[7] is the array the program is checking to see if it is empty or not
* Returns: int empty, integer representing whether the ExercisePlan array is empty (1) or not (0)
*/
int FitnessAppWrapper::isEmpty(ExercisePlan weeklyPlan[7])
{
	int empty = 1;

	for (int i = 0; i < 7; i++) {
		// checks if any of the fields are different than the default values, if so then the list is not empty
		if (weeklyPlan[i].getPlanName() != "" || weeklyPlan[i].getGoalSteps() != 0 || weeklyPlan[i].getPlanDate() != "") {
			empty = 0;
			break;
		}
	}

	return empty;
}




/*
* Function name: findIndexOfDate()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function loops through the DietPlan array to find the index of a particular date in the array.
* Input parameters: DietPlan weeklyPlan[7] is the array the program is looping through to find the index of the date; string date is
*					the date the program is looking for
* Returns: int i, index of the date (-1 if it is not there)
*/
int FitnessAppWrapper::findIndexOfDate(DietPlan weeklyPlan[7], string date)
{
	int i = 0;

	// loops until we either reach end of array or find the date
	while (i < 7 && weeklyPlan[i].getPlanDate() != date) {
		i++;
	}

	if (i == 7) { // program made it through entire array without finding the date, meaning it's not there
		i = -1;
	}

	return i;
}




/*
* Function name: findIndexOfDate()
* Programmer: Aabhwan Adhikary
* Created: 2/19/2025
* Description: This function through the ExercisePlan array to find the index of a particular date in the array.
* Input parameters: ExercisePlan weeklyPlan[7] is the array the program is looping through to find the index of the date; string date
*					is the date the program is looking for
* Returns: int i, index of the date (-1 if it isn't there)
*/
int FitnessAppWrapper::findIndexOfDate(ExercisePlan weeklyPlan[7], string date)
{
	int i = 0;

	// loops until we either reach end of array or find the date
	while (i < 7 && weeklyPlan[i].getPlanDate() != date) {
		i++;
	}

	if (i == 7) { // program made it through entire array without finding the date, meaning it's not there
		i = -1;
	}

	return i;
}
