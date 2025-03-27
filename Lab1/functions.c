// LAB 1 - 1/16/25

#include "Header.h"

char* myStrCat(char* destination, const char* source) {
	int nullIndex = 0;
	
	for (int i = 0; destination[i] != '\0'; i++) { // loops through destination string to find end
		nullIndex = i + 1; // where source should start adding to the end of destination
	}

	for (int j = 0; source[j] != '\0'; j++) { // loops through source string to add it to destination
		destination[nullIndex] = source[j];
		nullIndex++;
	}

	destination[nullIndex] = '\0'; // sets the last character of the string to '\0'

	return destination;
}

void reverseString(char *str, int first, int last) {
	if (first >= last) {
		return;
	}
	else {
		char temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		reverseString(str, first + 1, last - 1);
	}
}

char* myStrTok(char* str, char *delim) {
	static char* pToken;

	if (str != NULL) {
		int startIndex = 0; // start index of str
		while (startIndex < strLen(delim) && str[startIndex] == delim[0]) { // loop searches for index of first character not in delim
			startIndex++;
		}

		if (startIndex == strLen(delim)) { // all of str is delim, there is no token
			return NULL;
		}
		else {
			int delimIndex = 0;
			for (int i = 0; str[startIndex + i] != delim[0]; i++) {
				pToken[i] = str[startIndex + i];
				delimIndex = i + 1;
			}
		}
	}
}

int strLen(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	return len;
}


void sortArray(char* arr) {
	for (int k = 0; arr[k] != '\0'; k++) {
		for (int l = k + 1; arr[l] != '\0'; l++) {
			if (arr[l] < arr[k]) {
				char temp = arr[k];
				arr[k] = arr[l];
				arr[l] = temp;
			}
		}
	}
}

void mergeIntoArray(char* arr, char* str1, char* str2) {
	int arrIndex = 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		arr[arrIndex] = str1[i];
		arrIndex++;
	}

	for (int j = 0; str2[j] != '\0'; j++) {
		arr[arrIndex] = str2[j];
		arrIndex++;
	}

	arr[arrIndex] = '\0';

	puts(arr);

	sortArray(arr);
}

void mergeIntoDynamicArray(char* arr, char* str1, char* str2) {
	int arrIndex = 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		arr = (char *) realloc(arr, sizeof(char) * (i + 1));
		arr[arrIndex] = str1[i];
		arrIndex++;
	}

	for (int j = 0; str2[j] != '\0'; j++) {
		arr = (char *) realloc(arr, sizeof(char) * (arrIndex + j));
		arr[arrIndex] = str2[j];
		arrIndex++;
	}

	arr[arrIndex] = '\0';

	puts(arr);
	sortArray(arr);
}