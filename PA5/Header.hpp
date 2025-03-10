#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains all of the preprocessor directives of the program and function prototypes for the main program.
*/

#include "Queue.hpp"

using std::cin;

// FUNCTIONS
void runApplication();
void runSimulation(int targetMinutes);
void passMinute(int* elapsedTime, int* nextExpress, int* nextNormal, Queue express, Queue normal);