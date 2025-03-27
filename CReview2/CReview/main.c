/* Comment Block

   The example will help us with reviewing the important topics from C. It will
   also help with PA 1. This application will read all of the movie records from
   a file, parse the records into an array of structs, and process the data.

   History: 1/10/25 - created a loop to read all records from the file. defined
                      a struct for movie records. separated the each field in
                      each record into the corresponding element and field of the
                      array of structs.
   
            1/8/25 - opened the "movies.csv" file. read one line from the file.
*/

// this an inline comment

#include "movieUtilities.h"

int main(int argc, char *argv[]) // command line arguments - we'll work with these
                                 // more in the future
{
    //int* pInt = NULL; // a pointer declaration - a pointer is a variable that
                        // stores as its contents an address to another variable
    //int num = 50;

    //pInt = &num;

    FILE* inputStream = fopen("movies.csv", "r");
    char line[100] = ""; // = '\0'
    Movie records[10] = { {.title = "", .year = -1}, {"", -1} };
    int numRecords = 0;
    //char* line = "";

    // did we open the file successfully?
    if (inputStream != NULL)
    {
        // yes, opened file successfully
        fgets(line, 100, inputStream); // read one line from file
        puts(line); // echo the read line back to the screen to see if
                    // we read it from the file correctly

        while (fgets(line, 100, inputStream) != NULL) // (!feof(inputStream)
        {
            // Wicked,2024\n\0
            strcpy(records[numRecords].title, strtok(line, ",")); // title
            // note: strtok () always returns a pointer to a char; or another way
            // to look at it is a pointer to the first character in the newly
            // created token or substring. for the movie year, we need to convert
            // the string like "2024" to integer 2024. atoi () in <stdlib.h>
            // does this conversion!
            records[numRecords].year = atoi (strtok(NULL, "\n"));
            printf("records[%d].title: %s\nrecords[%d].year: %d\n",
                numRecords, records[numRecords].title, 
                numRecords, records[numRecords].year);
            ++numRecords;
        }
    }

    return 0;
}