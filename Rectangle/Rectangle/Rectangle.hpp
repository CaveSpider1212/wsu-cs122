#pragma once

#include <iostream> // input output operations; cout, cin
#include <fstream>

using std::cin; // cin >>
using std::cout; // cout <<
using::std::endl; // endl
using std::ifstream;

struct rect
{
	double mLen, mWid;
};

class Rectangle
{
public:
	// member functions
	// constructor - default constructor - special member
	// Rectangle();
	// constructor w/ parameters
	// Rectangle(double newLength, double newWidth);
	// constructor w/ default arguments
	Rectangle(double newLength = 0, double newWidth = 0);



	// Rule of Three
	// copy constructor - define how an object of Rectangle type should be copied
	// one scenario - when an object is passed-by-value
	Rectangle(Rectangle &r); // we need to pass by reference

	// copy assignment operator
	Rectangle& operator=(Rectangle& rhs);

	// destructor - special member function that gets invoked implicitly when an object goes out of scope
	// gets invoked when an object on the heap is explicitly deleted
	~Rectangle();

	


	// getters
	double getLength();
	double getWidth();

	// setters - mutators
	void setLength(double newLength);
	void setWidth(double newWidth);

private:
	// data members
	double mLength, mWidth;
};

// overloaded operator - non-member
std::ostream& operator << (std::ostream& lhs, Rectangle& rhs);
ifstream& operator >> (ifstream& lhs, Rectangle& rhs);