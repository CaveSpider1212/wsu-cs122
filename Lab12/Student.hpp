#pragma once

#include "Person.hpp"

typedef struct course
{
	string courseName;
	int credits, grade;
} Course;

class Student : public Person
{
public:
	int computeTotalCredits();
	int computeGPA();
private:
	Course courses[10];
	int numCourses, totalCredits;
};