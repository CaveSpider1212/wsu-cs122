// LAB 1 - 1/16/25

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

char* myStrCat(char* destination, const char* source);

void reverseString(char* str, int first, int last);

char* myStrTok(char* str, char delim);
int strLen(char* str);

void sortArray(char* arr);
void mergeIntoArray(char *arr, char* str1, char* str2);
void mergeIntoDynamicArray(char* arr, char *str1, char *str2);

#endif // !HEADER_H
