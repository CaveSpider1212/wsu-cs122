/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 1
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/15/2025
* Description: Function definitions of the program
*/

#include "Header.h"

/*
* Function name: readFile()
* Programmer: Aabhwan Adhikary
* Created: 1/15/25
* Description: This function reads each line from the input file.
* Input parameters: FILE *inputStream is the input file the program is reading from; FitbitData *data is the array of data for the
*					target patient from each minute; char others[][200] is an array of strings which holds each other line that
*					was filtered, deduped, or cleansed; int *dataNum and int *otherDataNum are integer pointers that represent the
*					indices of the *data and *others arrays
* Returns: None
*/
void readFile(FILE* inputStream, FitbitData* data, char others[][200], int* dataNum, int* otherDataNum) {
	char line[200] = ""; // current line in the file
	
	// reads the first two lines of the file
	fgets(line, 200, inputStream);
	fgets(line, 200, inputStream);

	while (fgets(line, 200, inputStream) != NULL) { // continues for each line until there are no more lines in the file to read

		// entries in each line in the file
		char patient[10], minute[9];
		double calories = 0.0, distance = 0.0;
		int floors = 0, heartRate = 0, steps = 0, sleepLevel = 0;

		readLine(data, others, line, *dataNum, otherDataNum, patient, minute, &calories, &distance, &floors, &heartRate, &steps, &sleepLevel);
		filterAndDedupe(data, others, dataNum, otherDataNum, line, patient, minute, calories, distance, floors, heartRate, steps, sleepLevel);
	}
}





/*
* Function name: readLine()
* Programmer: Aabhwan Adhikary
* Created: 1/17/25
* Description: This function reads the current line in the file, and depending on the number of commas passed fills in the corresponding
*				field in the struct in the array of FitbitData structs.
* Input parameters: FitbitData *data and char others[][200] are the arrays of structs and strings representing the patient's data each
*					minute and the other lines in the file (filtered, deduped, cleansed); char *line is a string representing the
*					current line in the file; int dataNum and int *otherDataNum represent the indices of the data and others arrays;
*					The remaining paramenters (char *patient up to int *sleepLevel) represent each field in the data array
* Returns: None
*/
void readLine(FitbitData *data, char others[][200], char* line, int dataNum, int* otherDataNum, char* patient, char* minute, double* calories, double* distance, int* floors, int* heartRate, int* steps, int* sleepLevel) {
	int commasPassed = 0; // how many commas we have passed

	for (int i = 0; i < strlen(line) - 1; i++) { // iterates until end of line is reached
		char entry[50] = "";
		int j = i;

		for (; line[j] != ',' && line[j] != '\n'; j++) {
			strncat(entry, &line[j], 1);
		}

		switch (commasPassed) { // fills in value in data/other array based on how many commas program has passed in the line
		case 0: // patient
			strcpy(patient, entry);
			break;
		case 1: // minute
			strcpy(minute, entry);
			break;
		case 2: // calories
			fillInRecordDouble(data, others, dataNum, otherDataNum, line, calories, commasPassed + 1, entry);
			break;
		case 3: // distance
			fillInRecordDouble(data, others, dataNum, otherDataNum, line, distance, commasPassed + 1, entry);
			break;
		case 4: // floors
			fillInRecordInt(data, others, dataNum, otherDataNum, line, floors, commasPassed + 1, entry);
			break;
		case 5: // heart rate
			fillInRecordInt(data, others, dataNum, otherDataNum, line, heartRate, commasPassed + 1, entry);
			break;
		case 6: // steps
			fillInRecordInt(data, others, dataNum, otherDataNum, line, steps, commasPassed + 1, entry);
			break;
		case 7: // sleep level
			fillInRecordInt(data, others, dataNum, otherDataNum, line, sleepLevel, commasPassed + 1, entry);
			break;
		}

		commasPassed++;
		i = j;
	}
}





/*
* Function name: fillInRecordDouble()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function either fills in the corresponding field in the data array or fills in the previous value if the line is
*				empty
* Input parameters: FitbitData *data and char others[][200] are arrays of structs and strings representing either the target patient's 
					data for each minute or each line that was filtered, dededuped, or cleansed; int dataNum and int *otherDataNum
					are the indices of the data or others array; char *line is the current line in the file; double *field is the
					field that the program is updating; int fieldNum is used to determine exactly which field in the data struct
					to access; char *entry is the entry in the line that was read
* Returns: None
*/
void fillInRecordDouble(FitbitData* data, char others[][200], int dataNum, int* otherDataNum, char* line, double* field, int fieldNum, char* entry) {
	if (strcmp(entry, "") == 0) { // if the entry is equal to "" (meaning there was nothing in the record)
		strcpy(*others[(*otherDataNum)++], strtok(line, "\n"));

		switch (fieldNum) {
		case 3:
			*field = data[dataNum].calories;
			break;
		case 4:
			*field = data[dataNum].distance;
			break;
		}
	}
	else { // if the entry is not empty, fill in the corresponding field passed into the function with the entry as a float
		*field = atof(entry);
	}
}





/*
* Function name: fillInRecordInt()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function either fills in the corresponding field in the data array or fills in the previous value if the line is
*				empty
* Input parameters: FitbitData *data and char others[][200] are arrays of structs and strings representing either the target patient's
					data for each minute or each line that was filtered, dededuped, or cleansed; int dataNum and int *otherDataNum
					are the indices of the data or others array; char *line is the current line in the file; int *field is the
					field that the program is updating; int fieldNum is used to determine exactly which field in the data struct
					to access; char *entry is the entry in the line that was read
* Returns: None
*/
void fillInRecordInt(FitbitData* data, char others[][200], int dataNum, int* otherDataNum, char* line, int* field, int fieldNum, char* entry) {
	if (strcmp(entry, "") == 0) { // if the entry is equal to "" (meaning there was nothing in the record)
		strcpy(others[(*otherDataNum)++], strtok(line, "\n"));

		switch (fieldNum) {
		case 5:
			*field = data[dataNum].floors;
			break;
		case 6:
			*field = data[dataNum].heartRate;
			break;
		case 7:
			*field = data[dataNum].steps;
			break;
		}
	}
	else { // if the entry is not empty, fill in the corresponding field passed into the function with the entry as an integer
		*field = atoi(entry);
	}
}





/*
* Function name: checkDuplicate()
* Programmer: Aabhwan Adhikary
* Created: 1/16/25
* Description: This function looks through the data array to see if the same patient and minute are already in the array.
* Input parameters: char *patient and char *minute are strings representing the patient and minute entries in the line; FitbitData
*					*data is the array of structs that the program is checking; int dataNum is the length of the data array
* Returns: int isDuplicate, an integer representing whether there is a duplicate (1) or not (0)
*/
int checkDuplicate(char* patient, char* minute, FitbitData* data, int dataNum) {
	int isDuplicate = 0;

	for (int i = 0; i <= dataNum; i++) { // iterates through data array up to dataNum (the length)
		if (strcmp(patient, data[i].patient) == 0 && strcmp(minute, data[i].minute) == 0) { // if the current patient and minute values are the same as ones that are already in data, then it is a duplicate
			isDuplicate = 1;
			break;
		}
	}

	return isDuplicate;
}





/*
* Function name: isTargetPatient()
* Programmer: Aabhwan Adhikary
* Created: 1/16/25
* Description: Checks if the patient value passed into the function is equal to the target patient ("12cx7")
* Input parameters: char *patient, a string representing the patient value read from the file
* Returns: int isTarget, an integer representing whether the patient passed into the function is equal to the target patient (1) or not (0)
*/
int isTargetPatient(char* patient) {
	int isTarget = 0;

	if (strcmp(patient, "12cx7") == 0) { // if the patient is equal to "12cx7", then it is the target patient
		isTarget = 1;
	}
	
	return isTarget;
}





/*
* Function name: filterAndDedupe()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function determines if the patient is the target patient and the line isn't a duplicate, and if so calls another
*				function to add it to the data array (otherwise adds it to the others string array).
* Input parameters: FitbitData *data and char others[][200] are arrays that this function may be adding to depending on if the line
*					is the target patient's and isn't a duplicate; int *dataNum and int *otherDataNum are the indices of those arrays,
*					which will be increased in this function; char *line is the current line in the file; The remaining parameters
*					(char *patient to int sleepLevel) represent each of the entries in the line which will be added to the data array
* Returns: None
*/
void filterAndDedupe(FitbitData* data, char others[][200], int* dataNum, int* otherDataNum, char* line, char* patient, char* minute, double calories, double distance, int floors, int heartRate, int steps, int sleepLevel) {
	if (isTargetPatient(patient)) {
		if (!checkDuplicate(patient, minute, data, *dataNum)) { // is target patient and not a duplicate, add to data array
			(*dataNum)++;
			addToData(data, *dataNum, patient, minute, calories, distance, floors, heartRate, steps, sleepLevel);
		}
		else { // is a duplicate, add to other data array
			strcpy(others[(*otherDataNum)++], strtok(line, "\n"));
		}
	}
	else { // data is not for target patient, add to other data array
		strcpy(others[(*otherDataNum)++], strtok(line, "\n"));
	}
}





/*
* Function name: addToData()
* Programmer: Aabhwan Adhikary
* Created: 1/17/25
* Description: This function adds each parameter to their corresponding fields in the data array.
* Input parameters: FitbitData *arr is the data array that the function is adding to, and int num is the index of that array; The
*					remaining parameters are the values that will be added to each field in the array
* Returns: None
*/
void addToData(FitbitData* arr, int num, char* patient, char* minute, double cal, double dist, int floor, int hr, int step, int sl) {
	strcpy(arr[num].patient, patient);
	strcpy(arr[num].minute, minute);
	arr[num].calories = cal;
	arr[num].distance = dist;
	arr[num].floors = floor;
	arr[num].heartRate = hr;
	arr[num].steps = step;
	arr[num].sleepLevel = sl;
}





/*
* Function name: computeTotals()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function computes the total calories, distance, floors, and steps in the data array for the whole day.
* Input parameters: FitbitData *data is the data array that will be used for adding the values (each field's value for each minute
*					is added to the total for that field); The remaining parameters are each of the output parameter totals, which
*					is the sum of all values in the field for that day
* Returns: None
*/
void computeTotals(FitbitData* data, double* totalCalories, double* totalDistance, int* totalFloors, int* totalSteps) {
	for (int i = 0; i < 1440; i++) { // iterates through entire data array (size 1440)
		*totalCalories += data[i].calories;
		*totalDistance += data[i].distance;
		*totalFloors += data[i].floors;
		*totalSteps += data[i].steps;
	}
}





/*
* Function name: computeAvgHeartRate()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function computes the average heart rate for the patient the whole day by adding all of the heart rates and dividing
*				by 1440.
* Input parameters: FitbitData *data is the data array the program will be looking at to compute the total heart rate; int *avgHeartRate
*					is an integer pointer that would contain the total heart rate divided by 1440 to find the average heart rate per
*					minute through the whole day
* Returns: None
*/
void computeAvgHeartRate(FitbitData* data, int* avgHeartRate) {
	int totalHeartRate = 0;

	for (int i = 0; i < 1440; i++) { // iterates through entire data array (size 1440)
		totalHeartRate += data[i].heartRate;
	}

	*avgHeartRate = totalHeartRate / 1440;
}





/*
* Function name: findMaxSteps()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function finds the max steps taken in a minute throughout the whole day.
* Input parameters: FitbitData *data is the data array the program will use to find the max steps; int *maxSteps is an integer pointer
*					representing the max steps the patient took in a minute the whole day
* Returns: None
*/
void findMaxSteps(FitbitData* data, int* maxSteps) {
	int max = 0;

	for (int i = 0; i < 1440; i++) { // iterates through entire data array (size 1440)
		if (data[i].steps >= max) { // checks if the steps in that minute is greater than the current max, if so set the new max to that
			max = data[i].steps;
		}
	}

	*maxSteps = max;
}





/*
* Function name: findPoorSleep()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function finds the longest consecutive range of poor sleep by finding the maximum sum of sleep values greater than
*				1 during the night and finding the time the range started and ended.
* Input parameters: FitbitData *data is the data array the program will be looking at (specifically, looking at the sleep values to
*					see if it is greater than 1 and taking the sum of each sleep value until reaching 1 again, then seeing if it is the
*					max or not); char *sleepStart and char *sleepEnd are strings representing the start and end times of the poorest
*					sleep
* Returns: None
*/
void findPoorSleep(FitbitData* data, char* sleepStart, char* sleepEnd) {
	int maxSleepSum = 0;

	for (int i = 0; i < 1440; i++) { // iterates through entire data array (size 1440)
		if (data[i].sleepLevel > 1) { // checks if the current minute sleep level > 1
			char *temp = data[i].minute; // temporary start time
			int sleepSum = data[i].sleepLevel;

			int j = i + 1;
			for (; data[j].sleepLevel > 1; j++) { // continues while the sleepLevel of the current entry > 1
				sleepSum += data[j].sleepLevel; // adds to the sleep sum
			}

			if (sleepSum > maxSleepSum) { // if the sleep sum we just found is greater than the current, then set the new max to that and change the start/end times
				maxSleepSum = sleepSum;
				strcpy(sleepStart, temp);
				strcpy(sleepEnd, data[j - 1].minute);
			}

			i = j;
		}
	}
}





/*
* Function name: writeResults()
* Programmer: Aabhwan Adhikary
* Created: 1/18/25
* Description: This function writes the results (totals and other lines) to the output file.
* Input parameters: FILE *outputStream is the output file the function is writing to; char others[][200] is the array of strings the
*					function will be writing to the file, which is all of the other lines that were filtered, deduped, or cleansed;
*					int otherDataNum is the length of the others array, and the function will iterate up to here to display the lines
*					The remaining parameters (double totalCalories to char *sleepEnd) are the total/average/poor sleep values to
*					write to the output file, which we computed previously with other functions
* Returns: None
*/
void writeResults(FILE* outputStream, char others[][200], int otherDataNum, double totalCalories, double totalDistance, int totalFloors, int totalSteps, int avgHeartRate, int maxSteps, char* sleepStart, char* sleepEnd) {
	fprintf(outputStream, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outputStream, "%f,%f,%d,%d,%d,%d,%s:%s\n", totalCalories, totalDistance, totalFloors, totalSteps, avgHeartRate, maxSteps, sleepStart, sleepEnd);

	for (int i = 0; i < otherDataNum; i++) {
		fprintf(outputStream, "%s\n", others[i]);
	}
}