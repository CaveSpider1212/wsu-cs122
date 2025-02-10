/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 1
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/15/2025
* Description: Header file of the program (contains function headers, preprocessor directives, and structs)
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


void readFile(FILE* inputStream, FitbitData *data, char others[][200], int* dataNum, int* otherDataNum);
void readLine(FitbitData *data, char others[][200], char* line, int dataNum, int* otherDataNum, char* patient, char* minute, double* calories, double* distance, int* floors, int* heartRate, int* steps, int* sleepLevel);

void fillInRecordDouble(FitbitData* data, char others[][200], int dataNum, int* otherDataNum, char* line, double* field, int fieldNum, char* entry);
void fillInRecordInt(FitbitData* data, char others[][200], int dataNum, int* otherDataNum, char* line, int* field, int fieldNum, char* entry);

int checkDuplicate(char* patient, char* minute, FitbitData* data, int dataNum);
int isTargetPatient(char* patient);

void filterAndDedupe(FitbitData* data, char others[][200], int* dataNum, int* otherDataNum, char* line, char* patient, char* minute, double calories, double distance, int floors, int heartRate, int steps, int sleepLevel);
void addToData(FitbitData* arr, int num, char* patient, char* minute, double cal, double dist, int floor, int hr, int step, int sl);

void computeTotals(FitbitData* data, double* totalCalories, double* totalDistance, int* totalFloors, int* totalSteps);
void computeAvgHeartRate(FitbitData* data, int* avgHeartRate);
void findMaxSteps(FitbitData* data, int* maxSteps);
void findPoorSleep(FitbitData* data, char* sleepStart, char* sleepEnd);

void writeResults(FILE* outputStream, char others[][200], int otherDataNum, double totalCalories, double totalDistance, int totalFloors, int totalSteps, int avgHeartRate, int maxSteps, char* sleepStart, char* sleepEnd);

#endif