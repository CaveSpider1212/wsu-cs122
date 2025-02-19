/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 3
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/30/2025
* Description: This file contains all of the function prototypes, struct definitions, and preprocessor directives of the program.
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct records {
	char artist[40];
	char albumTitle[40];
	char songTitle[40];
	char genre[25];
	Duration songLength;
	int timesPlayed;
	int rating;
} Record;

typedef struct node {
	Record data;
	struct node* pNext;
	struct node* pPrev;
} Node;


// Main project functions
void mainMenu(int* menuChoice);
void loadFromFile(FILE* musicFile, Node** records);
void storeIntoFile(FILE* musicFile, Node* records);
void displayRecords(Node* records);
void insertIntoRecords(Node** records); // new function
void deleteFromRecords(Node** records); // new function
void editRecord(Node* records);
void sortRecords(Node* records); // new function
void rateRecord(Node* records);
void playRecord(Node* records);
void shuffleRecords(Node* records); // new function

// Helper project functions
void displayArtists(Node* records, char uniqueArtists[][40], int* artistNum);
void displaySongs(Node* records, char* artist, char songList[][40], int* songNum);
int isUnique(char* str, char arr[][40], int num);
int isMultipleWords(char* str);
int countRecords(Node* records);
void addToIntegerArray(int* arr, int* index, int num); // new function
int checkDuplicateInIntegerArray(int *arr, int numRecords, int num); // new function
void playInOrder(Node* records, int* playOrder, int numRecords); // new function
Node* sortListByField(Node* records, int fieldNum); // new function

// Node functions
int insertAtFront(Node** records, Record newRecord);
int deleteNodeByTitle(Node** records, char *deleteTitle); // new function
Node* createNode(Record newRecord);
void printList(Node* records, char* artist);

#endif