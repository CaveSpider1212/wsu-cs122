// In this example we'll build a binary search tree (BST) from scratch. We'll use
// the BST to search for names.

// History: 3/7/25 - Implemented inorderTraversal (). Note: this project uses
//                   specifically std::string for the data in the Nodes. The other
//                   BST project shows class templates that can work with any
//                   comparable type T.
// 
//          3/5/25 - Completed implementing insert (). Also, implemented more
//                   setters, getters for the Node class.
// 
//          3/3/25 - Implemented the BST constructor, Node constructor,
//                   public BST::insert (), and started the 
//                   private BST::insert ().
// 
//          2/28/25 - Add the private data members to the Node class.

#include "BST.hpp"

int main(void)
{
	BST tree;

	tree.insert("Max");
	tree.insert("Erin");
	tree.insert("Noah");
	tree.insert("Frank");
	tree.insert("Naomi");

	tree.inorderTraversal();

	return 0;
}