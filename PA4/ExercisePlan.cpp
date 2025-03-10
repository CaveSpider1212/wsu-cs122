/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the function definitions of the ExercisePlan class.
*/

#include "ExercisePlan.hpp"




/*
* Function name: ExercisePlan()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This is the ExercisePlan class constructor, which is called when a ExercisePlan object is created. It assigns values to the
*				data members.
* Input parameters: int goal, which will be set as the goalSteps data member; string name, which will be set as the planName data
					member; string date, which will be set as the planDate member
* Returns: None
*/
ExercisePlan::ExercisePlan(int goal, string name, string date)
{
	goalSteps = goal;
	planName = name;
	planDate = date;
}




/*
* Function name: ExercisePlan()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This is the ExercisePlan class copy constructor, which is called when the program is copying one ExercisePlan object to another.
* Input parameters: ExercisePlan &p, a reference to another ExercisePlan object
* Returns: None
*/
ExercisePlan::ExercisePlan(ExercisePlan& p)
{
	goalSteps = p.getGoalSteps();
	planName = p.getPlanName();
	planDate = p.getPlanDate();
}




/*
* Function name: ~ExercisePlan()
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This is the ExercisePlan class destructor, which is called when a ExercisePlan object is destroyed.
* Input parameters: None
* Returns: None
*/
ExercisePlan::~ExercisePlan()
{
	cout << "Calling destructor for exercise plan from date " << this->getPlanDate() << endl;
}




/*
* Function name: getGoalSteps()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This getter function returns the goalSteps data member of the class.
* Input parameters: None
* Returns: int goalSteps
*/
int ExercisePlan::getGoalSteps()
{
	return goalSteps;
}




/*
* Function name: getPlanName()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This getter function returns the planName data member of the class.
* Input parameters: None
* Returns: string planName
*/
string ExercisePlan::getPlanName()
{
	return planName;
}




/*
* Function name: getPlanDate()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This getter function returns the planDate data member of the class.
* Input parameters: None
* Returns: string planDate
*/
string ExercisePlan::getPlanDate()
{
	return planDate;
}




/*
* Function name: setGoalSteps()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This setter function modifies the goalSteps data member of the class to a new value.
* Input parameters: int goal is the new value the program is setting goalSteps to
* Returns: None
*/
void ExercisePlan::setGoalSteps(int goal)
{
	goalSteps = goal;
}




/*
* Function name: setPlanName()
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This setter function modifies the planName data member of the class to a new value.
* Input parameters: string name is the new value the program is setting planName to
* Returns: None
*/
void ExercisePlan::setPlanName(string name)
{
	planName = name;
}




/*
* Function name: setPlanDate()
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This setter function modifies the planDate data member of the class to a new value.
* Input parameters: string date is the new value the program is setting planDate to
* Returns: None
*/
void ExercisePlan::setPlanDate(string date)
{
	planDate = date;
}




/*
* Function name: editGoal()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This function prompts the user for a new goal steps and takes user input, sets the goal steps using the
*				setGoalSteps() function, and prints the updated plan to the screen.
* Input parameters: None
* Returns: None
*/
void ExercisePlan::editGoal()
{
	int newGoal = 0;

	cout << "What is the new goal steps?: " << endl;
	cin >> newGoal;

	setGoalSteps(newGoal);

	cout << "\n" << * this << "\n";
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This function overloads the << operator to allow the program to print a ExercisePlan to the screen.
* Input parameters: ostream &lhs is a reference to the output stream, which the program will be writing to; ExercisePlan &rhs is a reference
*					to a ExercisePlan object which will be printed to the screen
* Returns: ostream &lhs, a reference to where the program will be printing to
*/
ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan name: " << rhs.getPlanName() << "\nGoal steps: " << rhs.getGoalSteps() << "\nPlan date: " << rhs.getPlanDate() << "\n";

	return lhs;
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This function overloads the << operator to allow the program to write a ExercisePlan to an output file.
* Input parameters: ofstream &lhs is a reference to the output file stream, which the program will be writing to; ExercisePlan &rhs is a
*					reference to a ExercisePlan object which will be written to the file
* Returns: ofstream &lhs, a reference to the file the program will be writing to
*/
ofstream& operator<<(ofstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getPlanName() << "\n" << rhs.getGoalSteps() << "\n" << rhs.getPlanDate() << "\n\n";

	return lhs;
}




/*
* Function name: operator >>
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This function overloads the >> operator to allow the program to read into a ExercisePlan object from a text file.
* Input parameters: ifstream &lhs is a reference to the input file stream, which the program will be reading from; ExercisePlan &rhs is a
*					reference to a ExercisePlan object which the program will store the file's data into
* Returns: ifstream &lhs, a reference to the file the program will be reading from
* Note: getline() in this function was obtained from "https://www.geeksforgeeks.org/read-a-file-line-by-line-in-cpp/"
*		stoi() in this function was obtained from "https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/"
*/
ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs)
{
	string fileName, fileGoal, fileDate, blankLine;

	getline(lhs, fileName);
	rhs.setPlanName(fileName);

	getline(lhs, fileGoal);
	rhs.setGoalSteps(stoi(fileGoal));

	getline(lhs, fileDate);
	rhs.setPlanDate(fileDate);

	getline(lhs, blankLine);
	return lhs;
}
