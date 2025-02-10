/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 2
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/22/2025
* Description: This file contains all of the function prototypes, struct definitions, and preprocessor directives of the program.
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct records {
	char artist[20];
	char albumTitle[25];
	char songTitle[20];
	char genre[15];
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
void mainMenu(int *menuChoice);
void loadFromFile(FILE* musicFile, Node** records);
void storeIntoFile(FILE* musicFile, Node* records);
void displayRecords(Node* records);
void editRecord(Node *records);
void rateRecord(Node* records);
void playRecord(Node* records);

// Helper project functions
void displayArtists(Node* records, char uniqueArtists[][20], int *artistNum);
void displaySongs(Node* records, char* artist, char songList[][20], int *songNum);
int isUnique(char *str, char arr[][20], int num);
int isMultipleWords(char* str);

// Node functions
int insertAtFront(Node **records, Record newRecord);
Node* createNode(Record newRecord);
void printList(Node* records, char* artist);

#endif
