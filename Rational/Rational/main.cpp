// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 

#include "Rational.hpp"

int main(void)
{
	Rational r1(0, 1), r2(5, 2), r3, r4(7);

	int n1 = 7, n2 = 10;
	cout << "addition: " << add(n1, n2) << endl;

	// r1 = r2.add(r4);
	cout << "addition: " << add(r2, r4) << endl;

	return 0;
}