#include "Person.hpp"

Person::Person(string name, int age, int height, char gender)
{
	this->name = name;
	this->age = age;
	this->height = height;
	this->gender = gender;
}

Person::Person(Person& p)
{
	this->name = p.getName();
	this->age = p.getAge();
	this->height = p.getHeight();
	this->gender = p.getGender();
}

Person::~Person()
{
	std::cout << "Deleted \"" << this->getName() << "\"" << std::endl;
}

Person Person::operator=(Person& rhs)
{
	this->name = rhs.getName();
	this->age = rhs.getAge();
	this->height = rhs.getHeight();
	this->gender = rhs.getGender();

	return *this;
}

string Person::getName()
{
	return name;
}

int Person::getAge()
{
	return age;
}

int Person::getHeight()
{
	return height;
}

char Person::getGender()
{
	return gender;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::setHeight(int height)
{
	this->height = height;
}

void Person::setGender(char gender)
{
	this->gender = gender;
}

istream& operator>>(istream& lhs, Person& rhs)
{
	// TODO: insert return statement here
	string name;
	lhs >> name;
	rhs.setName(name);


	int age = 0;
	lhs >> age;
	rhs.setAge(age);

	int height = 0;
	lhs >> height;
	rhs.setHeight(height);

	char gender = 0;
	lhs >> gender;
	rhs.setGender(gender);

	return lhs;
}

ostream& operator<<(ostream& lhs, Person& rhs)
{
	lhs << "Name: " << rhs.getName() << "\nAge: " << rhs.getAge() << "\nHeight: " << rhs.getHeight() << "\nGender: " << rhs.getGender();
	return lhs;
}
