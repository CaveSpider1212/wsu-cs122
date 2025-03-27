#include "Rectangle.hpp"

//Rectangle::Rectangle()
//{
//	mLength = mWidth = 0;
//}

Rectangle::Rectangle(double newLength, double newWidth)
{
	if (newLength >= 0) {
		mLength = newLength;
	}
	else {
		mLength = 0.0;
	}

	if (newWidth >= 0) {
		mWidth = newWidth;
	}
	else {
		mWidth = 0.0;
	}
}


// copy constructor - define how an object of Rectangle type should be copied
// one scenario - when an object is passed-by-value
Rectangle::Rectangle(Rectangle& r) // we need to pass by reference
{
	mLength = r.mLength;
	mWidth = r.mWidth;
}

Rectangle& Rectangle::operator=(Rectangle& rhs)
{
	// self-referential assignment
	if (this != &rhs) { // address of operator
		mLength = rhs.mLength;
		mWidth = rhs.mWidth;

		// "this" is a pointer to an instance of an object
		cout << "this: " << this << endl;
	}

	return *this;
}

Rectangle::~Rectangle()
{
	// clean up resources
	cout << "Inside Rectangle destructor: " << *this << endl;
}

// getters
double Rectangle::getLength()
{
	return mLength;
}

double Rectangle::getWidth()
{
	return mWidth;
}

// setters - mutators
void Rectangle::setLength(double newLength)
{
	// validate data
	if (newLength >= 0) {
		mLength = newLength;
	}
	// else - leave the data as is
}

void Rectangle::setWidth(double newWidth)
{
	// validate the data
	if (newWidth >= 0) {
		mWidth = newWidth;
	}
	// else - leave the data as is
}

std::ostream& operator<< (std::ostream& lhs, Rectangle& rhs)
{
	lhs << "l: " << rhs.getLength() << " w: " << rhs.getWidth();

	return lhs;
}

ifstream& operator>>(ifstream& lhs, Rectangle& rhs)
{
	double length = 0, width = 0;

	lhs >> length;
	rhs.setLength(length);

	lhs >> width;
	rhs.setWidth(width);

	return lhs;
}
