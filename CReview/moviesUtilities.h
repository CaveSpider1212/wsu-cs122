#ifndef MOVIES_UTILITIES // guard code
#define MOVIES_UTILITIES


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // printf(), scanf()
#include <string.h> // strcat(), strcpy(), strcmp(), strlen(), strtod(), strtok()
#include <stdlib.h>

typedef struct movie {
	char* title[25];
	int year;
} Movie;

#endif