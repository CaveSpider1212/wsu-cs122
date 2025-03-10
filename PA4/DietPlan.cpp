/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 4
* Created: 2/13/2025
* Class: CptS 122, Spring 2025; Lab Section 9
* Description: This file contains the function definitions of the DietPlan class.
*/

#include "DietPlan.hpp"




/*
* Function name: DietPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This is the DietPlan class constructor, which is called when a DietPlan object is created. It assigns values to the
*				data members.
* Input parameters: int goal, which will be set as the goalCalories data member; string name, which will be set as the planName data 
					member; string date, which will be set as the planDate member
* Returns: None
*/
DietPlan::DietPlan(int goal, string name, string date)
{
	goalCalories = goal;
	planName = name;
	planDate = date;
}




/*
* Function name: DietPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This is the DietPlan class copy constructor, which is called when the program is copying one DietPlan object to another.
* Input parameters: DietPlan &p, a reference to another DietPlan object
* Returns: None
*/
DietPlan::DietPlan(DietPlan& p)
{
	goalCalories = p.getGoalCalories();
	planName = p.getPlanName();
	planDate = p.getPlanDate();
}




/*
* Function name: ~DietPlan()
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This is the DietPlan class destructor, which is called when a DietPlan object is destroyed.
* Input parameters: None
* Returns: None
*/
DietPlan::~DietPlan()
{
	cout << "Calling destructor for diet plan from date " << this->getPlanDate() << endl;
}




/*
* Function name: getGoalCalories()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This getter function returns the goalCalories data member of the class.
* Input parameters: None
* Returns: int goalCalories
*/
int DietPlan::getGoalCalories()
{
	return goalCalories;
}




/*
* Function name: getPlanName()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This getter function returns the planName data member of the class.
* Input parameters: None
* Returns: string planName
*/
string DietPlan::getPlanName()
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
string DietPlan::getPlanDate()
{
	return planDate;
}




/*
* Function name: setGoalCalories()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This setter function modifies the goalCalories data member of the class to a new value.
* Input parameters: int goal is the new value the program is setting goalCalories to
* Returns: None
*/
void DietPlan::setGoalCalories(int goal)
{
	goalCalories = goal;
}




/*
* Function name: setPlanName()
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This setter function modifies the planName data member of the class to a new value.
* Input parameters: string name is the new value the program is setting planName to
* Returns: None
*/
void DietPlan::setPlanName(string name)
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
void DietPlan::setPlanDate(string date)
{
	planDate = date;
}




/*
* Function name: editGoal()
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This function prompts the user for a new goal calories and takes user input, sets the goal calories using the
*				setGoalCalories() function, and prints the updated plan to the screen.
* Input parameters: None
* Returns: None
*/
void DietPlan::editGoal()
{
	int newGoal = 0;

	cout << "What is the new goal calories?: " << endl;
	cin >> newGoal;

	setGoalCalories(newGoal);

	cout << "\n" << * this << "\n";
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 2/13/2025
* Description: This function overloads the << operator to allow the program to print a DietPlan to the screen.
* Input parameters: ostream &lhs is a reference to the output stream, which the program will be writing to; DietPlan &rhs is a reference
*					to a DietPlan object which will be printed to the screen
* Returns: ostream &lhs, a reference to where the program will be printing to
*/
ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan name: " << rhs.getPlanName() << "\nGoal calories: " << rhs.getGoalCalories() << "\nPlan date: " << rhs.getPlanDate() << "\n";

	return lhs;
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This function overloads the << operator to allow the program to write a DietPlan to an output file.
* Input parameters: ofstream &lhs is a reference to the output file stream, which the program will be writing to; DietPlan &rhs is a
*					reference to a DietPlan object which will be written to the file
* Returns: ofstream &lhs, a reference to the file the program will be writing to
*/
ofstream& operator<<(ofstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getPlanName() << "\n" << rhs.getGoalCalories() << "\n" << rhs.getPlanDate() << "\n\n";

	return lhs;
}




/*
* Function name: operator >>
* Programmer: Aabhwan Adhikary
* Created: 2/18/2025
* Description: This function overloads the >> operator to allow the program to read into a DietPlan object from a text file.
* Input parameters: ifstream &lhs is a reference to the input file stream, which the program will be reading from; DietPlan &rhs is a
*					reference to a DietPlan object which the program will store the file's data into
* Returns: ifstream &lhs, a reference to the file the program will be reading from
* Note: getline() in this function was obtained from "https://www.geeksforgeeks.org/read-a-file-line-by-line-in-cpp/"
*		stoi() in this function was obtained from "https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/"
*/
ifstream& operator>>(ifstream& lhs, DietPlan& rhs)
{
	string fileName, fileGoal, fileDate, blankLine;

	getline(lhs, fileName);
	rhs.setPlanName(fileName);

	getline(lhs, fileGoal);
	rhs.setGoalCalories(stoi(fileGoal));

	getline(lhs, fileDate);
	rhs.setPlanDate(fileDate);

	getline(lhs, blankLine);
	return lhs;
}

