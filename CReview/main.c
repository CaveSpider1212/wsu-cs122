#include "moviesUtilities.h"

int main(int argc, char* argv[]) {
	// pointers
	int* pInt = NULL;
	int num = 50;
	pInt = &num;


	// files/strings
	FILE* inputStream = fopen("movies.csv", "r");
	char line[100] = ""; // empty string puts null character at position 0; = '\0'
	Movie records[10] = { {.title = "", .year = -1}, {"", -1} };
	int numRecords = 0;

	// char* line = ""; immutable, value cannot be modified
	if (inputStream != NULL) { // file opened successfully
		fgets(line, 100, inputStream); // reads a single line in the file; "line" is the same thing as "&line[0]"; 100 is the max buffer size
		puts(line);

		while (fgets(line, 100, inputStream) != NULL) {
			// Wicked, 2027\n\0
			strcpy(records[numRecords].title, strtok(line, ","));
			puts(records[numRecords].title);

			records[numRecords].year = atoi(strtok(NULL, "\n"));
			printf("%d\n", records[numRecords].year);

			++numRecords;
		}
	}

	return 0;
}