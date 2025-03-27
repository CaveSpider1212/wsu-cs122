#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	double d;
} Data;

typedef struct node {
	Data nodeData;
	struct node* pNext;
} Node;

typedef struct stackNode {
	Node* pTop;
} Stack;

int isEmpty(const Stack* s);
int push(Stack *s, Data data);
void pop(Stack* s);
Data peek(const Stack* s);

#endif