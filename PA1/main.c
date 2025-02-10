/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 1
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/15/2025
* Description: This program reads the Fitbit data of a particular target patient from a file into a single array (while filtering out 
				other data, removing duplicates, etc.), and then computes totals for the values, average heart rate, max steps, etc. 
				and outputs them to another file
*/


#include "Header.h"

int main(void) {
	FILE* dataFile = NULL, *resultsFile = NULL;

	FitbitData data[1440]; // all records of the target that passed
	char otherData[100][200]; // filtered, deduped, and cleansed data in the file

	dataFile = fopen("FitbitData.csv", "r"); // data file
	resultsFile = fopen("Results.csv", "w"); // results file
	
	int dataNum = -1; // number of the data array, increments by 1 after successfully reading entire line
	int otherDataNum = 0; // used as index of otherData array and the length

	if (dataFile != NULL) { // check for success
		readFile(dataFile, data, otherData, &dataNum, &otherDataNum);
	}

	double totalCalories = 0.0, totalDistance = 0.0;
	int totalFloors = 0, totalSteps = 0, avgHeartRate = 0, maxSteps = 0;
	char sleepStart[10] = "", sleepEnd[10] = "";

	computeTotals(data, &totalCalories, &totalDistance, &totalFloors, &totalSteps);
	computeAvgHeartRate(data, &avgHeartRate);
	findMaxSteps(data, &maxSteps);
	findPoorSleep(data, sleepStart, sleepEnd);

	writeResults(resultsFile, otherData, otherDataNum, totalCalories, totalDistance, totalFloors, totalSteps, avgHeartRate, maxSteps, sleepStart, sleepEnd);

	fclose(dataFile);
	fclose(resultsFile);
	return 0;
}