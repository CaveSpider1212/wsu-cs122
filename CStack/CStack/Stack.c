#include "Stack.h"

void initStack(Stack* pStack)
{
	pStack->pTop = NULL; // empty stack
}

int isEmpty(const Stack* pStack) {
	return pStack->pTop == NULL;
}

Node* createNode(Data newData)
{
	Node* pMem = malloc(sizeof(Node));

	if (pMem != NULL) {
		// allocated space
		pMem->myData = newData; // struct assignment
		pMem->pNext = NULL;
	}

	return pMem;
}


int push(Stack* pStack, Data newData)
{
	// insertFront

	int success = 0;
	Node* pMem = createNode(newData);

	if (pMem != NULL) {
		success = 1;
		// insert the node into the top of the stack

		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}


// precondition: stack must not be empty
Data peek(const Stack *pStack)
{
	return pStack->pTop->myData;
}


// precondition: stack must not be empty
void pop(Stack* pStack)
{
	// deleteFront

	Node* pTemp = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);
}
