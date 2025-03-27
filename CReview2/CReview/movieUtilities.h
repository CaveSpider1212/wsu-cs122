/* comment block */

#ifndef MOVIE_UTILITIES // guard code
#define MOVIE_UTILITIES

#define _CRT_SECURE_NO_WARNINGS // Need to ignore the scanf_s () warnings generated
                                // by a Microsoft compiler

#include <stdio.h>  // printf (), scanf ()
#include <string.h> // strcat (), strcpy (), strcmp (), strlen (), 
                    // strtod (), strtok ()
#include <stdlib.h> // atoi (), atof ()


typedef struct movie
{
    char title[25];
    int year;
}Movie;

#endif