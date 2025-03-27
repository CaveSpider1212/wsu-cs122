#include "Rectangle.hpp"

int main(void)
{
	Rectangle r1, r2(6.7, -1), r3(7),
		r4(r3);

	r1 = r2; // copy assignment
	cout << "address of r1: " << &r1 << endl;

	ifstream inputStream;
	double length = 0, width = 0;

	inputStream.open("RectangleData.txt", std::ios::in);

	if (!inputStream.is_open()) {
		// we have a problem
	}
	else {
		inputStream >> r3;

		cout << "r3: " << r3 << endl;

		inputStream.close();
	}

	/*inputStream >> length;
	r3.setLength(length);

	inputStream >> width;
	r3.setWidth(width);
	*/
	
	r1.setLength(4.0);
	r1.setWidth(2.5);

	cout << r1 << endl;

	return 0;
}