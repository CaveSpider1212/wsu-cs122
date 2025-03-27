// Lab 4 - 2/6/2025

#include "testStack.h"

void testPush(void)
{
	Stack s;
	
	Data d1 = { 0.5 };
	Data d2 = { 2.9 };
	Data d3 = { 30.4 };

	push(&s, d1);
	push(&s, d2);

	printf("Top value: %lf\n", s.pTop->nodeData.d); // should be d2, 2.9

	push(&s, d3);

	printf("Top value: %lf\n", s.pTop->nodeData.d); // should be d3, 30.4
}

void testPop(void)
{
	Stack s;

	Data d1 = { 0.5 };
	Data d2 = { 2.9 };
	Data d3 = { 30.4 };

	push(&s, d1);
	push(&s, d2);

	printf("Top value: %lf\n", s.pTop->nodeData.d); // should be d2, 2.9

	push(&s, d3);

	printf("Top value: %lf\n", s.pTop->nodeData.d); // should be d3, 30.4

	pop(&s);
	pop(&s);

	printf("Top value: %lf\n", s.pTop->nodeData.d); // should be d1, 0.5
}

void testPeek(void)
{
	Stack s;

	Data d1 = { 0.5 };
	Data d2 = { 2.9 };
	Data d3 = { 30.4 };

	push(&s, d1);
	push(&s, d2);

	printf("Top value: %lf\n", peek(&s).d); // should be d2, 2.9

	push(&s, d3);

	printf("Top value: %lf\n", peek(&s).d); // should be d3, 30.4
}
