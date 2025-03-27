/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: Lab 1
* Created: 1/16/25
* Description: Prints hello world, plus other tasks
*/

#include "Header.h"

int main(void) {
	// TASK 1
	printf("TASK 1\n\n");
	printf("Hello World, I am in CptS 122!\n");
	
	printf("-----------------------------------------------------------\n");


	// TASK 2
	printf("TASK 2\n\n");

	char str1[10] = { 'r', 'a', 'c', 'e', '\0' };
	char str2[4] = { 'c', 'a', 'r', '\0' };

	puts(myStrCat(str1, str2));


	char reverseStr[6] = "phone";
	reverseString(reverseStr, 0, 4);
	puts(reverseStr);

	char* arr1[10];
	char str3[4] = { 'k', 'e', 'y', '\0' };
	char str4[4] = { 'b', 'o', 'y', '\0' };
	mergeIntoArray(arr1, str3, str4);
	puts(arr1);

	printf("\n");

	char* arr2 = NULL;
	arr2 = (char*)malloc(arr2, sizeof(char));
	mergeIntoDynamicArray(arr2, str3, str4);
	puts(arr2);
	free(arr2);
	
	return 0;
}