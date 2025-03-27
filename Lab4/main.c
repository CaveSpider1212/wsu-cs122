// Lab 4 - 2/6/2025

#include "Header.h"
#include "testStack.h"

int main(void)
{
	// TASKS 1 AND 2
	printf("TASKS 1 AND 2 -\n\n");

	testPush();
	printf("---------------------------------\n");
	testPop();
	printf("---------------------------------\n");
	testPeek();

	printf("-------------------------------------------------------------------\n");



	// TASK 3
	printf("TASK 3 - TOWERS OF HANOI\n\n");

	Post p1, p2, p3; // 3 posts
	DiskData d1, d2, d3; // data (diameters) for 3 disks
	d1.diameter = 3, d2.diameter = 2, d3.diameter = 1;

	initPost(&p1);
	initPost(&p2);
	initPost(&p3);

	pushToPost(&p1, d1);
	pushToPost(&p1, d2);
	pushToPost(&p1, d3);

	// takes top disk, checks if diameter is bigger than any of the top disks on the other posts
	// if it is, then move to the next post
	// if the diameter is bigger than the top disk on both posts, then move to the smallest disk

	if (!postIsEmpty(&p1)) {
		DiskData curData1 = peekFromPost(&p1);
		printf("Post 1 top disk diameter: %d\n", curData1.diameter);
	}

	/*
	if (!postIsEmpty(&p2)) {
		DiskData curData2 = peekFromPost(&p2);
		printf("Post 2 top disk diameter: %d\n", curData2.diameter);
	}

	if (!postIsEmpty(&p3)) {;
		DiskData curData3 = peekFromPost(&p3);
		printf("Post 3 top disk diameter: %d\n", curData3.diameter);
	}
	*/

	DiskData curData = popFromPost(&p1);

	if (!postIsEmpty(&p2) && !postIsEmpty(&p3)) {
		pushToPost(&p2, curData);
	}
	else if (!postIsEmpty(&p2)) {
		pushToPost(&p3, curData);
	}
	else if (!postIsEmpty(&p3)) {
		pushToPost(&p2, curData);
	}
	else {

	}

	return 0;
}