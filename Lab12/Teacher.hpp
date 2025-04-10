#pragma once

#include "Person.hpp"

typedef struct course
{
	string courseName;
	int credits;
	char averageGrade;
} Course;

class Teacher : public Person
{
public:
	int computeTotalCreditsTaught();
	int computeAverageGrades();
private:
	Course courses[10];
	int numCourses, numCredits;
};