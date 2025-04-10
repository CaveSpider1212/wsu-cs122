#include "Student.hpp"

int Student::computeTotalCredits()
{
	int totalCredits = 0;

	for (int i = 0; i < numCourses; i++) {
		totalCredits += courses[i].credits;
	}

	return totalCredits;
}

int Student::computeGPA()
{
	int gpaPoints = 0;

	for (int i = 0; i < numCourses; i++) {
		if (courses[i].grade >= 90) { // A
			gpaPoints += courses[i].credits * 4;
		}
		else if (courses[i].grade >= 80 && courses[i].grade < 90) { // B
			gpaPoints += courses[i].credits * 3;
		}
		else if (courses[i].grade >= 70 && courses[i].grade < 80) { // C
			gpaPoints += courses[i].credits * 2;
		}
		else if (courses[i].grade >= 60 && courses[i].grade < 70) { // D
			gpaPoints += courses[i].credits * 1;
		}
		else { // F
			gpaPoints += 0;
		}
	}

	return gpaPoints / totalCredits;
}
