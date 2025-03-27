// LAB 2 - 1/23/25

#include "Header.h"

Node* makeNode(Contact newData)
{
	Node* pMem = NULL;

	pMem = (Node *) malloc(sizeof(Node));
	pMem->data = newData;
	pMem->pNext = NULL;

	return pMem;
}

Boolean insertContactInOrder(Node** pList, Contact newData)
{
	Node* pMem = makeNode(newData);

	if (pMem == NULL) { // if program did not allocate space for a new node
		return FALSE;
	}
	else {
		if (*pList != NULL) { // if the list is not empty
			int targetIndex = searchForInsertIndex(*pList, newData); // keeps passing in "Todd"

			insertInOrder(*pList, pMem, targetIndex);
			printf("inserted %s\n", newData.name);
		}
		else {
			*pList = pMem;
		}

		return TRUE;
	}
}

Boolean deleteContact(Node** pList, Contact searchContact)
{
	Node* pTemp = *pList;
	Contact data = pTemp->data;

	int targetDeleteIndex = searchForEqualIndex(*pList, searchContact);
	
	if (targetDeleteIndex == -1) {
		return FALSE;
	}
	else {
		deleteInOrder(*pList, pTemp, targetDeleteIndex);
		return TRUE;
	}
}

void printList(Node* pList)
{
	while (pList != NULL) {
		printf("--> %s, %s, %s, %s\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
}

int searchForInsertIndex(Node* pList, Contact searchContact)
{
	int index = 0, spotFound = 0;

	while (pList != NULL && !spotFound) {
		printf("%s %s\n", searchContact.name, pList->data.name);
		printf("%d\n", strcmp(searchContact.name, pList->data.name));

		if (strcmp(searchContact.name, pList->data.name) > 0) { // if the contact name comes after the current node's contact name
			index++;
			printf("new index: %d\n", index);

			// if the contact name comes after the current node's contact name and before the next node's contact name
			if (pList->pNext != NULL) {
				if (strcmp(searchContact.name, pList->data.name) > 0 && strcmp(searchContact.name, pList->pNext->data.name) < 0) {
					spotFound = 1;
				}
			}
			else {
				spotFound = 1;
			}

			pList = pList->pNext;
		}
		else {
			spotFound = 1;
		}
	}

	return index;
}

// inserts pMem into pList at targetIndex
void insertInOrder(Node* pList, Node *pMem, int targetIndex)
{
	printf("target index: %d\n", targetIndex);
	for (int i = 0; i < targetIndex; i++) { // iterates the list of nodes until we reach the target index
		pList = pList->pNext;
	}

	// this should insert the node at the target index
	pMem->pNext = pList;
	pList = pMem;

	printList(pList);
}

int searchForEqualIndex(Node* pList, Contact searchContact)
{
	int index = 0, spotFound = 0;

	while (pList != NULL && !spotFound) {
		if (strcmp(searchContact.name, pList->data.name) != 0) {
			index++;

			if (strcmp(searchContact.name, pList->data.name) == 0) {
				spotFound = 1;
			}

			pList = pList->pNext;
		}
	}

	if (!spotFound) {
		index = -1;
	}

	return index;
}

void deleteInOrder(Node* pList, Node* pTemp, int targetIndex)
{
	for (int i = 0; i < targetIndex; i++) { // iterates the list of nodes until we reach the target index
		pList = pList->pNext;
	}

	pList = pTemp->pNext;
	free(pTemp);
}

