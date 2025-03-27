#include "BST.hpp"

BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	destroyTree(pRoot);
}

BSTNode* BST::getRoot()
{
	return pRoot;
}

void BST::insertNode(std::string newData, BSTNode* pTree)
{
	BSTNode* pMem = new BSTNode(newData);

	if (pMem != nullptr) {
		// if memory was allocated successfully for pMem

		if (pTree == nullptr) {
			// if pTree is nullptr (meaning there are no nodes in the tree), set pRoot to pMem
			pRoot = pMem;
		}
		else {
			if (pMem->getData() > pTree->getData()) {
				// if pMem's data is greater than pTree's data

				if (pTree->getRightPtr() == nullptr) {
					// if pTree's right child is nullptr, insert pMem as pTree's right child
					pTree->setRightPtr(pMem);
				}
				else {
					// iterate to pTree's right child
					insertNode(newData, pTree->getRightPtr());
				}
			}
			else if (pMem->getData() < pTree->getData()) {
				// if pMem's data is less than pTree's data

				if (pTree->getLeftPtr() == nullptr) {
					// if pTree's left child is nullptr, insert pMem as pTree's left child
					pTree->setLeftPtr(pMem);
				}
				else {
					// iterate to pTree's left child
					insertNode(newData, pTree->getLeftPtr());
				}
			}
			else {
				// pMem's data is equal to pTree's data, meaning it is a duplicate node
				std::cout << "'" << newData << "' is already in the binary search tree." << std::endl;
			}
		}
	}
}

void BST::inOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeftPtr());
		std::cout << pTree << std::endl;
		inOrderTraversal(pTree->getRightPtr());
	}
}

void BST::inOrderTraversal(BSTNode* pTree, std::string names[], int* count)
{
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeftPtr(), names, count);
		names[(*count)++] = pTree->getData();
		inOrderTraversal(pTree->getRightPtr(), names, count);
	}
}

void BST::preOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr) {
		std::cout << pTree << std::endl;
		preOrderTraversal(pTree->getLeftPtr());
		preOrderTraversal(pTree->getRightPtr());
	}
}

void BST::postOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr) {
		postOrderTraversal(pTree->getLeftPtr());
		postOrderTraversal(pTree->getRightPtr());
		std::cout << pTree << std::endl;
	}
}

bool BST::isEmpty(void)
{
	if (pRoot == nullptr) {
		return true;
	}

	return false;
}

void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr) {
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());

		pTree = nullptr;
		delete pTree;
	}
}