#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Complex {
public:
	// constructor
	Complex(double real = 0, double imaginary = 0);

	// getters
	double getRealPart();
	double getImaginaryPart();

	// operations
	Complex add(Complex rhs);
	void read();
	void print();

private:
	// data members
	double realPart, imaginaryPart;
};

// other operations
Complex add(Complex lhs, Complex rhs);

// operator overloads
Complex operator +(Complex &lhs, Complex &rhs);
Complex operator -(Complex& lhs, Complex& rhs);
ostream &operator << (ostream& lhs, Complex& rhs);