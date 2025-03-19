/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 5
* Assignment: PA 6
* Created: 3/10/2025
* Description: Class definition for the BST class
*/

#pragma once

#include "BSTNode.hpp"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

class BST
{
public:
	// constructor/destructor
	BST();
	~BST();

	// getter function
	BSTNode* getRootPtr();

	// public member functions -- used for main program
	void print();
	string search(char searchChar, BSTNode *pTree);
private:
	// private data member
	BSTNode* rootPtr; // BST root node

	// private member functions -- used by public functions
	void insert(char newData, string morse, BSTNode *pTree);
	void deleteNode(BSTNode *pTree, BSTNode *pParent);
	void inorderTraversal(BSTNode* pTree);
};