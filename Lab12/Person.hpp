#pragma once

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Person
{
public:
	Person(string name, int age, int height, char gender);
	Person(Person& p);
	~Person();
	Person operator = (Person& rhs);

	string getName();
	int getAge();
	int getHeight();
	char getGender();

	void setName(string name);
	void setAge(int age);
	void setHeight(int height);
	void setGender(char gender);
protected:
	string name;
	int age, height;
	char gender;
};

istream& operator >> (istream& lhs, Person& rhs);
ostream& operator << (ostream& lhs, Person& rhs);