#include "LinkedList.h"

void initList(Node** pList) {
	*pList = NULL; // assigning the list as an empty list
}

Node* createNode(Movie newData) {
	// goal is to allocate space on heap and init with Movie data
	Node* pMem = malloc(sizeof(Node));

	// is the space allocated on the heap?
	if (pMem != NULL) {
		// yes, we allocated space successfully

		// let's init the space - Node
		pMem->pNext = pMem->pPrev = NULL; // this node is not pointing to any other nodes yet
		pMem->data = newData; // struct assignment
	}

	return pMem; // it's possible that pMem contains NULL
}

int insertFront(Node** pList, Movie newData)
{
	Node* pMem = createNode(newData); // new node which will be inserted to the front
	int success = 0;

	if (pMem != NULL) {
		// yes, we allocated space for a Node
		success = 1;

		// is the list empty?
		if (*pList == NULL) {
			// yes, it's empty
			*pList = pMem; // modifying the direct value of pHead, setting it to the new node
			// above line sets the current list item (which is also the first item) to the newly created node
		}
		else {
			// no, list is not empty
			pMem->pNext = *pList; // sets next node to current item in the list, basically this node is pointing to the item that was originally at the front spot
			(*pList)->pPrev = pMem; // sets the current list item's previous node to the node just created (basically they are now pointing to each other)
			*pList = pMem; // sets current list item to the new node
		}
	}

	return success;
}

// precondition: list is in dictionary ordering
int insertInOrder(Node** pList, Movie newData)
{
	Node* pCur = *pList, * pPrev = NULL, * pMem = createNode(newData);
	int success = 0;

	if (pMem != NULL) {
		// yes, allocated space for a Node
		success = 1;

		/*
		if (*pList == NULL) {
			// the list is empty
			*pList = pMem;
		}
		else {
			// list is not empty
		}
		*/

		while (pCur != NULL && strcmp(pCur->data.title, newData.title) < 0) { // short-circuit evaluation
			pPrev = pCur; // sets what we currently have as the current node to the new previous node
			pCur = pCur->pNext; // sets the current node to the next node in the sequence
		}

		// we have found the spot to insert in order
		// are we inserting at front
		if (pPrev == NULL) { // if there is no previous node, then we are at the front
			// yes, we are
			pMem->pNext = *pList; // sets the created node's next node to *pList (what is currently at the front of the list)
			*pList = pMem; // the created node is now at the front of the list
		}
		else {
			// inserting somewhere in middle or at end of non empty list
			pMem->pNext = pCur; // sets the created node's next node to the current node 
			pPrev->pNext = pMem; // sets the previous node's next node to the current node
		}
	}

	return success;
}



// precondition: list must not be empty -> *pList != NULL
Movie deleteFront(Node** pList) {
	Node* pTemp = *pList; // initially sets pTemp as the node at the front of pList
	Movie data = pTemp->data; // struct assignment

	*pList = pTemp->pNext; // sets the front node to the next node after pTemp

	free(pTemp); // frees pTemp, which is set to the node that was at the front of the list

	return data; // making a copy of a struct
}

void printList(Node* pList)
{
	// base case
	if (pList == NULL) { // if there is no node/list item
		printf("-->\n");
	}
	else { // recursive step
		printf("--> %s, %d", pList->data.title, pList->data.year);
		printList(pList->pNext); // passes in the node the current node/list item is pointing to (this is the next node in the list)
	}
}

void destroyList(Node** pList)
{
	// recursive case
	if (*pList != NULL) { // checks that the node is not null (we have not reached the end of the list yet)
		destroyList(&((*pList)->pNext)); // passes in the address of the next node (current node's pNext node)
		printf("Deleting node with title: %s\n", (*pList)->data.title);
		free(*pList); // frees the current node from memory
		*pList = NULL; // need to set pointer to NULL to avoid a dangling pointer situation
	}
}

