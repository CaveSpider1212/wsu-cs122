#include "Complex.hpp"

Complex::Complex(double real, double imaginary)
{
	realPart = real;
	imaginaryPart = imaginary;
}

double Complex::getRealPart()
{
	return realPart;
}

double Complex::getImaginaryPart()
{
	return imaginaryPart;
}

Complex Complex::add(Complex rhs)
{
	double sumReal = realPart + rhs.realPart;
	double sumImaginary = imaginaryPart + rhs.imaginaryPart;

	return Complex(sumReal, sumImaginary);
}

void Complex::read()
{
	cin >> realPart;
}

void Complex::print()
{
	cout << realPart;

	if (imaginaryPart >= 0) {
		cout << " + " << imaginaryPart << "i" << endl;
	}
	else {
		cout << imaginaryPart << "i" << endl;
	}
}

Complex add(Complex lhs, Complex rhs)
{
	double sumReal = lhs.getRealPart() + rhs.getRealPart();
	double sumImaginary = lhs.getImaginaryPart() + rhs.getImaginaryPart();

	return Complex(sumReal, sumImaginary);
}

Complex operator+(Complex& lhs, Complex& rhs)
{
	double sumReal = lhs.getRealPart() + rhs.getRealPart();
	double sumImaginary = lhs.getImaginaryPart() + rhs.getImaginaryPart();
	
	return Complex(sumReal, sumImaginary);
}

Complex operator-(Complex& lhs, Complex& rhs)
{
	double diffReal = lhs.getRealPart() - rhs.getRealPart();
	double diffImaginary = lhs.getImaginaryPart() - rhs.getImaginaryPart();
	
	return Complex(diffReal, diffImaginary);
}

ostream &operator<<(ostream& lhs, Complex& rhs)
{
	if (rhs.getImaginaryPart() >= 0) {
		lhs << rhs.getRealPart() << " + " << rhs.getImaginaryPart() << "i";
	}
	else {
		lhs << rhs.getRealPart() << rhs.getImaginaryPart() << "i";
	}
	
	return lhs;
}
