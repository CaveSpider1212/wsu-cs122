#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
public:
	Node(const string newData = "");
	
	~Node();

	string getData() const;

	Node* getNextPtr() const;

	void setNextPtr(Node* const newNextPtr);
private:
	string mJob;
	Node* mpNext;
};