#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum boolean {
	FALSE, TRUE
} Boolean;

typedef struct contact {
	char name[50];
	char phone[12]; // 18005557577
	char email[50];
	char title[20];
} Contact;

typedef struct node {
	Contact data;
	struct node* pNext;
} Node;

Node* makeNode(Contact newData);
Boolean insertContactInOrder(Node** pList, Contact newData);
Boolean deleteContact(Node** pList, Contact searchContact);
Boolean editContact(Node* pList, Contact searchContact);
Boolean loadContacts(FILE* infile, Node** pList);
Boolean storeContacts(FILE* infile, Node* pList);
void printList(Node* pList);

int searchForInsertIndex(Node* pList, Contact searchContact);
void insertInOrder(Node* pList, Node *pMem, int targetIndex);
int searchForEqualIndex(Node* pList, Contact searchContact);
void deleteInOrder(Node* pList, Node* pTemp, int targetIndex);

#endif