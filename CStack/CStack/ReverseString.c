#include "ReverseString.h"

char* reverseString(char* str)
{
	Stack s;
	initStack(&s);

	Data d = { '\0' };
	int success = 0;
	int index = 0;

	while (str[index] != '\0') {
		d.symbol = str[index]; // copy character
		success = push(&s, d);
		index++;
	}

	index = 0;
	while (!isEmpty(&s)) {
		d = peek(&s);
		pop(&s);
		str[index] = d.symbol;
		index++;
	}

	return str;
}
