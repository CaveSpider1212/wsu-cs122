/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains all of the function definitions of the program.
*/

#include "Header.hpp"




/*
* Function name: runApplication()
* Programmer: Aabhwan Adhikary
* Created: 3/6/2025
* Description: This function prompts the user for the number of minutes to run the simulation for and calls another function,
*				runSimulation(), to run the actual simulation for the desired number of minutes.
* Input parameters: none
* Returns: none
*/
void runApplication()
{
	int targetMinutes = 0;
	cout << "How many minutes do you want to run the simulation for? (1 minute = 1 variable increase)" << endl;
	cin >> targetMinutes;

	runSimulation(targetMinutes);
}




/*
* Function name: runSimulation()
* Programmer: Aabhwan Adhikary
* Created: 3/6/2025
* Description: This function runs the simulation until the simulation has run for the target amount of minutes, passed into the function.
*				This function also handles the customers arriving and leaving both the express and normal lines, randomly generating
*				arrival and service times, printing, and modifying the elapsed time and service time values by calling another function,
*				passMinute().
* Input parameters: int targetMinutes, an integer representing the number of minutes to run the simulation for
* Returns: none
*/
void runSimulation(int targetMinutes)
{
	srand(time(nullptr));
	Queue expressLine, normalLine;

	int totalTimeElapsed = 0, customerNumber = 1, currentExpressServiceTime = 0, currentNormalServiceTime = 0;
	int nextExpressArrival = rand() % 5 + 1, nextNormalArrival = rand() % 6 + 3;

	while (totalTimeElapsed <= targetMinutes) { // loop runs until time elapsed reaches number of minutes we want to run the simulation for
		// 0 minutes until next arrival to express line, add to that line
		if (nextExpressArrival == 0) {
			// generate a random service time for the normal line
			int expressServiceTime = rand() % 5 + 1, expressTotalTime = expressServiceTime;

			// computes total time, the sum of the service time plus service times of everyone before in the line
			if (!expressLine.isEmpty()) {
				expressTotalTime += expressLine.getSumTimes();
			}

			// adds customer to express line
			Data* newExpressCustomerData = new Data(customerNumber, expressServiceTime, expressTotalTime);
			expressLine.enqueue(newExpressCustomerData);

			cout << "Customer #" << customerNumber << " has arrived in the express line (" << totalTimeElapsed << " minutes elapsed)" << endl;

			// generates the arrival time of the next customer to the express line randomly
			nextExpressArrival = rand() % 5 + 1;
			customerNumber++;
		}

		// 0 minutes until arrival to normal line, add to that line
		if (nextNormalArrival == 0) {
			// generate a random service time for the normal line
			int normalServiceTime = rand() % 6 + 3, normalTotalTime = normalServiceTime;

			// computes total time, the sum of the service time plus service times of everyone before in the line
			if (!normalLine.isEmpty()) {
				normalTotalTime += normalLine.getSumTimes();
			}

			// adds customer to normal line
			Data* newNormalCustomerData = new Data(customerNumber, normalServiceTime, normalTotalTime);
			normalLine.enqueue(newNormalCustomerData);

			cout << "Customer #" << customerNumber << " has arrived in the normal line (" << totalTimeElapsed << " minutes elapsed)" << endl;

			// generates the arrival time of the next customer to the normal line randomly
			nextNormalArrival = rand() % 8 + 3;
			customerNumber++;
		}

		// service times of the first customers in the express and normal lines
		if (!expressLine.isEmpty()) {
			currentExpressServiceTime = expressLine.getHeadPtr()->getData()->getServiceTime();
		}
		if (!normalLine.isEmpty()) {
			currentNormalServiceTime = normalLine.getHeadPtr()->getData()->getServiceTime();
		}

		if (!expressLine.isEmpty() && currentExpressServiceTime == 0) {
			Data* exitCustomerData = expressLine.getHeadPtr()->getData();
			cout << "Customer #" << exitCustomerData->getCustomerNumber() << " has exited the express line (" << exitCustomerData->getTotalTime() << " minutes spent in line)" << endl;
			expressLine.dequeue();
		}

		if (!normalLine.isEmpty() && currentNormalServiceTime == 0) {
			Data* exitCustomerData = normalLine.getHeadPtr()->getData();
			cout << "Customer #" << exitCustomerData->getCustomerNumber() << " has exited the normal line (" << exitCustomerData->getTotalTime() << " minutes spent in line)" << endl;
			normalLine.dequeue();
		}

		if (totalTimeElapsed % 10 == 0) {
			// prints out both queues every 10 minutes
			cout << "---------------------------------------------------------------" << endl;
			cout << "Minute " << totalTimeElapsed << " of the simulation -\n" << endl;

			cout << "EXPRESS LINE:" << endl;
			expressLine.printQueue(expressLine.getHeadPtr());

			cout << endl;

			cout << "NORMAL LINE:" << endl;
			normalLine.printQueue(normalLine.getHeadPtr());

			cout << "---------------------------------------------------------------" << endl;
		}

		// pass 1 minute, update time
		passMinute(&totalTimeElapsed, &nextExpressArrival, &nextNormalArrival, expressLine, normalLine);
	}
}




/*
* Function name: passMinute()
* Programmer: Aabhwan Adhikary
* Created: 3/8/2025
* Description: This function represents a minute passing. This function increments the elapsed time by 1 and decrements the arrival
*				times in both of the lines by 1, and also decrements the service time for the current customer in each line by 1.
* Input parameters: int *elapsedTime, a pointer to an integer representing the time elapsed in the simulation; int *nextExpress,
*					a pointer to an integer representing the arrival time for the next customer to the express line; int *nextNormal,
*					a pointer to an integer representing the arrival time for the next customer to the normal line; Queue express
*					and Queue normal are both used to decrement the service time of the head pointer (current customer) by 1
* Returns: none
*/
void passMinute(int* elapsedTime, int* nextExpress, int* nextNormal, Queue express, Queue normal)
{
	(*elapsedTime)++;
	(*nextExpress)--;
	(*nextNormal)--;

	if (!express.isEmpty()) {
		// decrease the head pointer's service time by 1
		int currentExpressServiceTime = express.getHeadPtr()->getData()->getServiceTime();
		express.getHeadPtr()->getData()->setServiceTime(currentExpressServiceTime - 1);
	}

	if (!normal.isEmpty()) {
		// decrease the head pointer's service time by 1
		int currentNormalServiceTime = normal.getHeadPtr()->getData()->getServiceTime();
		normal.getHeadPtr()->getData()->setServiceTime(currentNormalServiceTime - 1);
	}
}
