// First C++ Program

#include <iostream>
#include <string>

// function overloading
int add(int n1, int n2);
std::string add(std::string s1, std::string s2);

int main(void)
{
	std::cout << "result of int add(): " << add(5, 6) << std::endl;
	std::cout << "result of string add(): " << add("cat", "dog") << std::endl;

	int num = 50, num2 = 17;
	int &refNum = num; // & is the reference operator
	// refNum = num2;
	// we are creating an alias or another name for an existing variable or object
	
	num = 75;
	std::cout << "refNum contents: " << refNum << std::endl;
	std::cout << "Address of num " << &num << " " << "Address of refNum " << &refNum << std::endl;

	// below is the way we insert or output messages to the screen
	std::cout << "Hello, CptS 122!" << std::endl;

	std::string str = "";
	std::cout << "Enter a C++ standard string: ";
	std::cin >> str;
	std::cout << "string entered: " << str << std::endl;

	return 0;
}

int add(int n1, int n2)
{
	return n1 + n2;
}

std::string add(std::string s1, std::string s2)
{
	return s1 + s2;
}
