#include "QueueNode.hpp"

QueueNode::QueueNode(const std::string &newData)
{
	data = newData;
}

QueueNode::~QueueNode()
{
	std::cout << "Deleted node with data " << data << std::endl;
}

std::string QueueNode::getData()
{
	return data;
}

void QueueNode::setData(const std::string& newData)
{
	data = newData;
}

QueueNode* QueueNode::getNextPtr()
{
	return pNext;
}

void QueueNode::setNextPtr(QueueNode *nextPtr)
{
	this->pNext = nextPtr;
}
