// Lab 4 - 2/6/2025

#include "Stack.h"

int isEmpty(const Stack* s)
{
	return s->pTop == NULL;
}

int push(Stack* s, Data newData)
{
	int success = 0;
	Node* pMem = malloc(sizeof(Node));
	pMem->nodeData.d = newData.d;

	if (pMem != NULL) {
		success = 1;

		pMem->pNext = s->pTop;
		s->pTop = pMem;
	}

	return success;
}

void pop(Stack* s)
{
	Node* pTemp = s->pTop;
	s->pTop = s->pTop->pNext;
	free(pTemp);
}

Data peek(const Stack* s)
{
	return s->pTop->nodeData;
}