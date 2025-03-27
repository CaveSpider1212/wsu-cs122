#pragma once

// This file contains a stack class template. The underlying data structure for the 
// stack is an array allocated from the heap.

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T& newItem);
	bool pop(T& poppedItem);
	bool peek(T& item);

	bool isEmpty();

	char postfix(string line);

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T* mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T& newItem)
{
	mTop[0] = newItem;
	return true;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T& poppedItem)
{
	if (!this->isEmpty()) {
		poppedItem = mTop[0];
		mTop[0] = mTop[1];
	}
	return false;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
bool Stack<T>::peek(T& item)
{
	return mTop[0];
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	return mTop == nullptr;
}

template<class T>
inline char Stack<T>::postfix(string line)
{
	for (int i = 0; i < strlen(line); i++) {
		if (line[i] == NULL) {
			cout << "Error -- no characters to read" << endl;
		}
		else {
			char c = line[i];
			int digit = c - '0';

			if (line[i] == '=') {
				if (this->isEmpty()) {
					cout << "Error -- empty stack" << endl;
				}
				else if (mSize > 1) {
					cout << "Error -- more than one element" << endl;
				}
				else if (mSize == 1) {
					char e = c;
					return e;
				}
			}
			else if (digit >= 0 && digit <= 9) {
				this->push(c);
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/') {
				char o = c;

				if (mSize < 2) {
					cout << "Error -- less than two elements in stack" << endl;
				}
				else {
					int s1, s2;
					this->pop(s2);
					this->pop(s1);

					int v = 0;

					switch (o) {
					case '+':
						v = s1 + s2;
						break;
					case '-':
						v = s1 - s2;
						break;
					case '*':
						v = s1 * s2;
						break;
					case '/':
						v = s1 / s2;
						break;
					default:
						cout << "Not an operator" << endl;
					}

					this->push(v);
				}
			}
		}
	}
}

