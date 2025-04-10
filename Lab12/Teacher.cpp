#include "Teacher.hpp"

int Teacher::computeTotalCreditsTaught()
{
	int totalCredits = 0;

	for (int i = 0; i < numCourses; i++) {
		totalCredits += courses[i].credits;
	}

	return totalCredits;
}

int Teacher::computeAverageGrades()
{
	int gradePoints = 0;

	for (int i = 0; i < numCourses; i++) {
		gradePoints += courses[i].averageGrade;
	}

	return gradePoints / numCourses;
}
