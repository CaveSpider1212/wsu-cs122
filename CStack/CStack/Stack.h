#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char symbol;
} Data;

typedef struct node
{
	Data myData;
	struct node* pNext;
} Node;

typedef struct stack
{
	Node* pTop; // same as pHead
} Stack;



void initStack(Stack* pStack);

int isEmpty(const Stack *pStack);

Node* createNode(Data newData);

// push == insertFront
int push(Stack* pStack, Data newData);

// precondition: stack must not be empty
Data peek(const Stack *pStack);

// precondition: stack must not be empty
void pop(Stack* pStack);

#endif