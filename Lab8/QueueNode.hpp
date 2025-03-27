#pragma once

#include <string>
#include <iostream>

class QueueNode
{
public:
	QueueNode(const std::string &newData = "");
	~QueueNode();

	std::string getData();
	void setData(const std::string &newData);
	QueueNode* getNextPtr();
	void setNextPtr(QueueNode *nextPtr);
private:
	std::string data;
	QueueNode* pNext;
};