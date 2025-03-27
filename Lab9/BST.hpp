#pragma once

#include "BSTNode.hpp"

class BST
{
public:
	BST();
	~BST();

	BSTNode* getRoot();

	void insertNode(std::string newData, BSTNode *pTree);
	void inOrderTraversal(BSTNode* pTree);
	void inOrderTraversal(BSTNode* pTree, std::string names[], int* count);
	void preOrderTraversal(BSTNode* pTree);
	void postOrderTraversal(BSTNode* pTree);
	bool isEmpty(void);
private:
	BSTNode* pRoot;

	void destroyTree(BSTNode* pTree);
};

ostream& operator<< (ostream& lhs, BST& rhs);