#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

class BST
{
public:
	BST();

	void insert(string newData);
	void inorderTraversal() const;

private:
	void insert(string newData, Node* pTree);
	void inorderTraversal(Node *pTree) const;

	Node* mpRoot;
};