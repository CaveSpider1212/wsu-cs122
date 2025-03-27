// We will place the definitions for only
// Rational's operations in this file

#include "Rational.hpp"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational::Rational(const int newNumerator, const int newDenominator)
{
	mNumerator = newNumerator;

	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
	else
	{
		mDenominator = 1;
	}
}

int Rational::getNumerator() const
{
	return mNumerator;
}

int Rational::getDenominator() const
{
	return mDenominator;
}


void Rational::setNumerator(const int newNumerator)
{
	mNumerator = newNumerator;
}

void Rational::setDenominator(const int newDenominator)
{
	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
}

// implicitly called when passing-by-value
Rational::Rational(const Rational& copy)
{
	//mNumerator = copy.mNumerator; // could also work
	setNumerator(copy.getNumerator());
	setDenominator(copy.getDenominator());

	// let's rewrite using the copy assignment operator!
}

Rational Rational::add(const Rational& rhs)
{
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator() * rhs.getDenominator());

	return result;
}

Rational::~Rational()
{
	cout << "Inside destructor for Rational" << std::endl;
}

Rational& Rational::operator= (const Rational& rhs)
{
	// fill in during class

	return *this;
}

Rational operator+(Rational& lhs, Rational& rhs)
{
	Rational result;

	result.setDenominator(lhs.getDenominator() * rhs.getDenominator());

	result.setNumerator(lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator());

	return result;
}

ostream& operator<<(ostream& lhs, Rational& rhs)
{
	lhs << rhs.getNumerator() << "/" << rhs.getDenominator();

	return lhs;
}
