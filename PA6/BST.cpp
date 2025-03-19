/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 5
* Assignment: PA 6
* Created: 3/10/2025
* Description: Function definitions for the BST class
*/

#include "BST.hpp"



/*
* Function name: BST::BST()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Constructor for the BST class, called when a BST object is created; reads from the morse table file and inserts each
*				character read from the file into a binary search tree
* Input parameters: None
* Returns: None
*/
BST::BST()
{
	ifstream morseTableFile;
	morseTableFile.open("MorseTable.txt", ios::in);

	for (int i = 0; i < 39; i++) {
		char englishCharacter = '\0';
		string morseCode = "";

		morseTableFile >> englishCharacter;
		morseTableFile >> morseCode;

		insert(englishCharacter, morseCode, rootPtr);
	}

	morseTableFile.close();
}




/*
* Function name: BST::~BST()
* Programmer: Aabhwan Adhikary
* Created: 3/15/2025
* Description: Destructor for the BST class, called when a BST object is destroyed; deletes all nodes in the binary search tree
* Input parameters: None
* Returns: None
*/
BST::~BST()
{
	while (rootPtr != nullptr) {
		// loops while the root pointer is not nullptr (meaning it loops until the root pointer is deleted and set to nullptr)
		deleteNode(rootPtr, nullptr);
	}
}




/*
* Function name: BST::getRootPtr()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Getter function for rootPtr
* Input parameters: None
* Returns: BSTNode *rootPtr;
*/
BSTNode* BST::getRootPtr()
{
	return rootPtr;
}




/*
* Function name: BST::print()
* Programmer: Aabhwan Adhikary
* Created: 3/15/2025
* Description: Prints out the binary search tree by calling inorderTraversal()
* Input parameters: None
* Returns: None
*/
void BST::print()
{
	inorderTraversal(rootPtr);
	cout << "\n\n";
}




/*
* Function name: BST::search()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Recursively loops through the binary search tree to look for an English character, and returns its corresponding morse
*				code
* Input parameters: char searchChar is the English character the function should look for; BSTNode *pTree is the root pointer of the
*					tree or subtree the function should search
* Returns: string morse is the morse code of the English character
*/
string BST::search(char searchChar, BSTNode *pTree)
{
	string morse = "";

	if (searchChar < pTree->getEnglishCharacter()) {
		// if the character we're searching for is less than the current node's character, go to the left subtree
		morse = search(searchChar, pTree->getLeftPtr());
	}
	else if (searchChar > pTree->getEnglishCharacter()) {
		// if the character we're searching for is greater than the current node's character, go to the right subtree
		morse = search(searchChar, pTree->getRightPtr());
	}
	else {
		// character is equal to the current node's character, so we have found the node
		morse = pTree->getMorseCode();
	}

	return morse;
}




/*
* Function name: BST::insert()
* Programmer: Aabhwan Adhikary
* Created: 3/13/2025
* Description: Creates a new node and inserts that node into the binary search tree based on its English character
* Input parameters: char newData is the English character of the new node; string morse is the morse code of the new node; BSTNode 
					*pTree is the root pointer of the binary search tree that the new node will be inserted in
* Returns: None
*/
void BST::insert(char newData, string morse, BSTNode *pTree)
{
	BSTNode* pMem = new BSTNode(newData, morse);

	if (pTree == nullptr) {
		// if the root pointer is null, meaning the tree is empty
		rootPtr = pMem;
	}
	else {
		// if there is a root pointer

		if (newData < pTree->getEnglishCharacter()) {
			// if the current character is less than the current node's character
			if (pTree->getLeftPtr() == nullptr) {
				// the current node's left pointer is empty, set that pointer to pMem
				pTree->setLeftPtr(pMem);
			}
			else {
				// there is already a pointer in pTree's left pointer spot, keep going down
				insert(newData, morse, pTree->getLeftPtr());
			}
		}
		else {
			// if the current character is greater than the current node's character
			if (pTree->getRightPtr() == nullptr) {
				// the current node's right pointer is empty, set that pointer to pMem
				pTree->setRightPtr(pMem);
			}
			else {
				// there is already a pointer in pTree's right pointer spot, keep going down
				insert(newData, morse, pTree->getRightPtr());
			}
		}
	}
}




/*
* Function name: BST::deleteNode()
* Programmer: Aabhwan Adhikary
* Created: 3/15/2025
* Description: Recursively traverses the binary search tree until it reaches a leaf node, then deletes that node
* Input parameters: BSTNode *pTree is the root node of the tree or subtree the function should be traversing, and also the current
					node; BSTNode *pParent is the parent of the current node, whose left or right child will be set to nullptr once
					the node is deleted
* Returns: None
*/
void BST::deleteNode(BSTNode* pTree, BSTNode *pParent)
{
	if (pTree != nullptr) {
		if (pTree->getLeftPtr() == nullptr && pTree->getRightPtr() == nullptr) {
			// pTree is a leaf node, so just delete it
			cout << "Deleting '" << pTree->getEnglishCharacter() << "'" << endl;

			if (pTree == rootPtr) {
				// if pTree is the root pointer, set root pointer to nullptr
				rootPtr = nullptr;
			}
			else {
				if (pTree == pParent->getLeftPtr()) {
					// if pTree is pParent's left child, set pParent's left child to nullptr
					pParent->setLeftPtr(nullptr);
				}
				if (pTree == pParent->getRightPtr()) {
					// if pTree is pParent's right child, set pParent's right child to nullptr
					pParent->setRightPtr(nullptr);
				}
			}

			delete pTree;
		}
		else {
			if (pTree->getLeftPtr() != nullptr) {
				// if pTree has a left child, go to that left child
				deleteNode(pTree->getLeftPtr(), pTree);
			}
			if (pTree->getRightPtr() != nullptr) {
				// if pTree has a right child, go to that right child
				deleteNode(pTree->getRightPtr(), pTree);
			}
		}
	}
}




/*
* Function name: BST::inorderTraversal()
* Programmer: Aabhwan Adhikary
* Created: 3/15/2025
* Description: Traverses the left subtree of the node first, then prints the node's data (English character), and finally traverses the
*				right subtree of the node
* Input parameters: BSTNode *pTree is the root pointer of the tree the function is traversing, and also the current node of the function
* Returns: None
*/
void BST::inorderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr) {
		inorderTraversal(pTree->getLeftPtr()); // go left
		cout << pTree->getEnglishCharacter() << " "; // print current node's English character
		inorderTraversal(pTree->getRightPtr()); // go right
	}
}