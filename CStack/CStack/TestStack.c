#include "TestStack.h"

void testPushOnEmptyStack(void)
{
	// test point?
	Stack s = { NULL };
	Data testData = { 'A' };
	int success = 0;

	success = push(&s, testData);

	// expected results?
	// success = 1
	// top stack data = 'A'
	// pTop != NULL

	if (s.pTop != NULL) {
		printf("Test for pTop passed.\n");

		if (s.pTop->myData.symbol == testData.symbol) {
			printf("Test for data at top passed.\n");
		}
		else {
			printf("Test for data at top failed.\n");
		}
	}
	else {
		printf("Test for pTop failed.\n");
	}

	if (success == 1) {
		printf("Test for success passed.\n");
	}
	else {
		printf("Test for success failed.\n");
	}
}
