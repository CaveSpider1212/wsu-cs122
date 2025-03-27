#include "BSTNode.hpp"

BSTNode::BSTNode(std::string& newData)
{
	data = newData;
	pLeft = pRight = nullptr;
}

std::string BSTNode::getData()
{
	return data;
}

BSTNode* BSTNode::getLeftPtr()
{
	return pLeft;
}

BSTNode* BSTNode::getRightPtr()
{
	return pRight;
}

void BSTNode::setLeftPtr(BSTNode* pLeft)
{
	this->pLeft = pLeft;
}

void BSTNode::setRightPtr(BSTNode* pRight)
{
	this->pRight = pRight;
}

ostream& operator<<(ostream& lhs, BSTNode& rhs)
{
	lhs << rhs.getData();
	return lhs;
}
