#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie
{
    char title[25];
    int year;
}Movie;

typedef struct node
{
    Movie data;
    struct node* pNext, * pPrev;
} Node;

void initList(Node** pList); // making changes to pList, so need double pointer
Node* createNode(Movie newData); // helper for insert
int insertFront(Node **pList, Movie newData); // insertFront (L, e) ADT

// precondition: list is in dictionary ordering
int insertInOrder(Node** pList, Movie newData);

// precondition: list must not be empty -> *pList != NULL
Movie deleteFront(Node** pList);

void printList(Node* pList); // not changing pList, so only need single pointer

void destroyList(Node** pList);

#endif