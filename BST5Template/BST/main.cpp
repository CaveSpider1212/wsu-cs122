// In this example we'll build a binary search tree (BST) from scratch. We'll use
// the BST to search for names.

// History: 3/7/25 - Implemented public and private versions of inorderTraversal ().
//                   We deleted the Node.cpp and BST.cpp files because we transitioned
//                   our BST code base to use templates. All the class template code
//                   should be placed in the corresponding .hpp files. We have officially
//                   created class templates for the BST and Node. Could the class Node
//                   be a struct instead? Yes, it could be!
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
	BST<string> tree; // the compiler uses our class BST template to create
	                  // code that uses type string for the "T" type - we don't
	                  // have to specifically write an instance of the functions
	                  // for a string type anymore!!!
	BST<int> tree2; // the compiler uses our class BST template to create
	                // code that uses type int for the "T" type

	tree.insert("Max");
	tree.insert("Erin");
	tree.insert("Noah");
	tree.insert("Frank");
	tree.insert("Naomi");

	tree.inorderTraversal();

	tree2.insert(10);
	tree2.insert(15);
	tree2.insert(20);
	tree2.insert(5);
	tree2.insert(68);

	tree2.inorderTraversal();

	return 0;
}