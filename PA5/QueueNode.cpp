/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This function contains the function definitions for the QueueNode class.
*/

#include "QueueNode.hpp"




/*
* Function name: QueueNode::QueueNode()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This is a constructor of the QueueNode class, called when a QueueNode object is created with a Data* parameter. It
*				sets the node's data to newData and the next pointer to nullptr.
* Input parameters: Data *newData is the data that the newly created node will have
* Returns: none
*/
QueueNode::QueueNode(Data *newData)
{
	pData = newData;
	pNext = nullptr;
}




/*
* Function name: QueueNode::getData()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Getter function for pData
* Input parameters: none
* Returns: Data *pData
*/
Data* QueueNode::getData()
{
	return pData;
}




/*
* Function name: QueueNode::getNextPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Getter function for pNext
* Input parameters: none
* Returns: QueueNode *pNext
*/
QueueNode* QueueNode::getNextPtr()
{
	return pNext;
}




/*
* Function name: QueueNode::setNextPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Setter function for pNext
* Input parameters: QueueNode *nextPtr, the new next pointer of the node
* Returns: none
*/
void QueueNode::setNextPtr(QueueNode* nextPtr)
{
	pNext = nextPtr;
}
