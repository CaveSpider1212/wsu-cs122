/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 5
* Assignment: PA 6
* Created: 3/10/2025
* Description: This program reads a text file of a morse code table into a binary search tree, then uses that binary search tree to convert text from another text file
*				into morse code and printing the morse code to the screen.
* Note: Obtained get() in Line 30 from "https://www.geeksforgeeks.org/how-to-read-file-character-by-character-in-cpp/"
*/

#include "BST.hpp"
#include <cctype>

using std::cout;
using std::endl;
using std::toupper;

int main(void)
{
	BST morseCodeTree;

	// prints out the morse code binary search tree
	cout << "Morse Code Tree (left subtree first, then node, then right subtree):" << endl;
	morseCodeTree.print();

	ifstream convertFile;
	convertFile.open("Convert.txt", ios::in);

	// converts english sentence to morse code and prints out result
	cout << "Conversion to Morse Code:" << endl;
	char currentChar = '\0';
	while (convertFile.get(currentChar)) {
		/*
		* get() was obtained from "https://www.geeksforgeeks.org/how-to-read-file-character-by-character-in-cpp/"
		* This function inputs the current character in the line into currentChar regardless of whether it is a white space or not
		*/

		// loops until there are no characters from convertFile to read into currentchar

		if (currentChar == ' ') {
			// if the current character is a space, add 3 spaces
			cout << "   ";
		}
		else {
			// if current character is a letter/number/key, print it out in morse code and add 1 space
			cout << morseCodeTree.search(toupper(currentChar), morseCodeTree.getRootPtr());
			cout << " ";
		}
	}
	cout << "\n\n";

	convertFile.close();

	return 0;
}