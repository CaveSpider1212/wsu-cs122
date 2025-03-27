// Lab 9 - 3/20/2025

#include "BST.hpp"
#include <fstream>

using std::ifstream;
using std::getline;

int main(void)
{
	ifstream namesFile;
	namesFile.open("Names.txt", std::ios::in);

	std::string names[200], currentName = "";
	int count = 0;
	while (getline(namesFile, currentName)) {
		names[count++] = currentName;
	}

	BST tree;
	for (int i = 0; i < count; i++) {
		tree.insertNode(names[i], tree.getRoot());
	}

	int insertCount = 0;
	tree.inOrderTraversal(tree.getRoot(), names, &insertCount);

	for (int j = 0; j < count; j++) {
		std::cout << names[j] << std::endl;
	}
	return 0;
}