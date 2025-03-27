#pragma once

#include <string>
#include <iostream>

using std::ostream;

class BSTNode
{
public:
	BSTNode(std::string& newData);

	std::string getData();
	BSTNode* getLeftPtr();
	BSTNode* getRightPtr();

	void setLeftPtr(BSTNode* pLeft);
	void setRightPtr(BSTNode* pRight);
private:
	std::string data;
	BSTNode* pLeft, * pRight;
};

ostream& operator <<(ostream& lhs, BSTNode& rhs);