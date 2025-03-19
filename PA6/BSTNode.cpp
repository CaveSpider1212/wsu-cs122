/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 5
* Assignment: PA 6
* Created: 3/10/2025
* Description: Function definitions for the BSTNode class
*/

#include "BSTNode.hpp"



/*
* Function name: BSTNode::BSTNode
* Programmer: Aabhwan Adhikary
* Created: 3/10/2025
* Description: Constructor for BSTNode, called when a BSTNode object is created
* Input parameters: char english, set as the englishCharacter field; string morse, set as the morseCode field
* Returns: None
*/
BSTNode::BSTNode(char english, string morse)
{
	englishCharacter = english;
	morseCode = morse;
	leftPtr = rightPtr = nullptr;
}




/*
* Function name: BSTNode::getEnglishCharacter()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Getter function for englishCharacter
* Input parameters: None
* Returns: char englishCharacter
*/
char BSTNode::getEnglishCharacter()
{
	return englishCharacter;
}




/*
* Function name: BSTNode::getMorseCode()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Getter function for morseCode
* Input parameters: None
* Returns: string morseCode
*/
string BSTNode::getMorseCode()
{
	return morseCode;
}




/*
* Function name: BSTNode::getLeftPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Getter function for leftPtr;
* Input parameters: None
* Returns: BSTNode *leftPtr
*/
BSTNode* BSTNode::getLeftPtr()
{
	return leftPtr;
}




/*
* Function name: BSTNode::getRightPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Getter function for rightPtr
* Input parameters: None
* Returns: BSTNode *rightPtr
*/
BSTNode* BSTNode::getRightPtr()
{
	return rightPtr;
}




/*
* Function name: BSTNode::setEnglishCharacter()
* Programmer: Aabhwan Adhikary
* Created: 3/16/2025
* Description: Setter function for englishCharacter
* Input parameters: char newChar
* Returns: None
*/
void BSTNode::setEnglishCharacter(char newChar)
{
	englishCharacter = newChar;
}




/*
* Function name: BSTNode::setLeftPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/11/2025
* Description: Setter function for leftPtr
* Input parameters: BSTNode *mpLeft
* Returns: None
*/
void BSTNode::setLeftPtr(BSTNode* mpLeft)
{
	leftPtr = mpLeft;
}




/*
* Function name: BSTNode::setRightPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/11/2025
* Description: Setter function for rightPtr
* Input parameters: BSTNode *mpRight
* Returns: None
*/
void BSTNode::setRightPtr(BSTNode* mpRight)
{
	rightPtr = mpRight;
}

