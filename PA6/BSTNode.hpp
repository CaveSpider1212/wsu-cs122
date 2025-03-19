/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 5
* Assignment: PA 6
* Created: 3/10/2025
* Description: Class definition for the BSTNode class
*/

#pragma once

#include <string>

using std::string;

class BSTNode
{
public:
	// constructor
	BSTNode(char english, string morse);

	// getter functions
	char getEnglishCharacter();
	string getMorseCode();
	BSTNode *getLeftPtr();
	BSTNode* getRightPtr();

	// setter functions
	void setEnglishCharacter(char newChar);
	void setLeftPtr(BSTNode* mpLeft);
	void setRightPtr(BSTNode* mpRight);
private:
	// private data members
	char englishCharacter;
	string morseCode;
	BSTNode* leftPtr, * rightPtr; // left and right child nodes
};