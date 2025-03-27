// LAB 5 - 2/13/2025

#include "Complex.hpp"
#include "CreditReport.hpp"

int main(void)
{
	Complex c1(3.5, 2), c2(4, -3), c3, c4;

	// c3 = c1.add(c2);
	// c3 = add(c1, c2);
	c3 = c1 + c2;
	c4 = c1 - c2;

	c3.print();
	cout << c4 << endl;

	return 0;
}