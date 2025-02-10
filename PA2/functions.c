/*
* Programmer: Aabhwan Adhikary
* Assignment: PA 2
* Class: CptS 122, Spring 2025; Lab Section 9
* Created: 1/22/2025
* Description: This file has all of the function declarations of the program.
*/

#include "Header.h"



/*
* Function name: mainMenu()
* Programmer: Aabhwan Adhikary
* Created: 1/22/2025
* Description: Displays the menu options and allows the user to choose an option.
* Input parameters: integer pointer *menuChoice which is used for the user to choose an option
* Returns: none
*/
void mainMenu(int *menuChoice)
{
	printf("Choose a number:\n");
	printf("(1) load\n");
	printf("(2) store\n");
	printf("(3) display\n");
	printf("(4) insert\n");
	printf("(5) delete\n");
	printf("(6) edit\n");
	printf("(7) sort\n");
	printf("(8) rate\n");
	printf("(9) play\n");
	printf("(10) shuffle\n");
	printf("(11) exit\n");

	scanf("%d", menuChoice);
}




/*
* Function name:
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Reads through the music playlist file and stores each line into a linked list, parsing each of the fields into the
*				Records struct in the Node.
* Input parameters: FILE *musicFile, the file that the program is reading from; Node **records, which is the linked list where the
*					records are being stored
* Returns: none
*/
void loadFromFile(FILE* musicFile, Node** records)
{
	char line[100] = ""; // current line in the file
	musicFile = fopen("musicPlayList.csv", "r");

	while (fgets(line, 100, musicFile)) { // reads each line in the file
		Record r;

		if (line[0] == '\"') { // if the current line starts with a quotation mark
			strcpy(r.artist, strtok(line, "\""));
		}
		else {
			strcpy(r.artist, strtok(line, ","));
		}

		// copies each field separated by commas into each field in the records struct
		strcpy(r.albumTitle, strtok(NULL, ","));
		strcpy(r.songTitle, strtok(NULL, ","));
		strcpy(r.genre, strtok(NULL, ","));
		r.songLength.minutes = atoi(strtok(NULL, ":"));
		r.songLength.seconds = atoi(strtok(NULL, ","));
		r.timesPlayed = atoi(strtok(NULL, ","));
		r.rating = atoi(strtok(NULL, ","));

		int success = insertAtFront(records, r);
	}

	fclose(musicFile);

	printf("Successfully loaded records from file.\n");
	system("pause");
}




/*
* Function name: storeIntoFile()
* Programmer: Aabhwan Adhikary
* Created: 1/26/2025
* Description: Stores the data in the linked list into the music playlist file
* Input parameters: FILE *musicFile is the file the program is storing the linked list data into; Node *records is the linked list
* Returns: none
*/
void storeIntoFile(FILE* musicFile, Node* records)
{
	if (records != NULL) { // checks that the records list is not empty
		musicFile = fopen("musicPlayList.csv", "w");

		while (records != NULL) { // continues until end of node list is reached
			if (isMultipleWords(records->data.artist)) { // checks if the artist name is multiple words long/contains a comma
				fprintf(musicFile, "\"%s\",", records->data.artist);
			}
			else {
				fprintf(musicFile, "%s,", records->data.artist);
			}

			// prints each data field into the file
			fprintf(musicFile, "%s,", records->data.albumTitle);
			fprintf(musicFile, "%s,", records->data.songTitle);
			fprintf(musicFile, "%s,", records->data.genre);
			fprintf(musicFile, "%d:%d,", records->data.songLength.minutes, records->data.songLength.seconds);
			fprintf(musicFile, "%d,", records->data.timesPlayed);
			fprintf(musicFile, "%d\n", records->data.rating);

			// iterates to the next node in the list
			records = records->pNext;
		}

		printf("Successfully stored list onto file.\n");
		fclose(musicFile);
	}
	else {
		printf("List is empty.\n");
	}

	system("pause");
}




/*
* Function name: displayRecords()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Displays either all of the records in the linked list or the records belonging to a specific artist to the screen
* Input parameters: Node *records is the linked list the program will be reading off of
* Returns: none
*/
void displayRecords(Node* records)
{
	printf("Choose an option from below:\n");
	printf("(1) Print all records\n");
	printf("(2) Print all records that match an artist\n");

	char uniqueArtists[200][20] = { "" }; // list of all unique artists in the list (max 200 artists)
	int artistNum = 0; // number of artists in the uniqueArtists list

	int choice = 0;
	scanf("%d", &choice);

	switch (choice) {
	case 1: // printing the entire list
		printList(records, NULL);
		break;
	case 2: // printing all songs by one artist
		printf("Which artist's records are you searching for? Enter the number of the artist from the list below:\n");
		displayArtists(records, uniqueArtists, &artistNum);
		
		int artistChoice = 0;
		scanf("%d", &artistChoice);

		if (artistChoice <= 0 || artistChoice > artistNum) { // checks that the number is on the artist list displayed on the screen
			printf("Choose a number out of the list.\n");
		}
		else {
			printList(records, uniqueArtists[artistChoice - 1]);
		}

		break;
	default:
		printf("Choose one of the options on the list.\n");
	}

	system("pause");
}




/*
* Function name: editRecord()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Chooses a specific song in the list of records and edits any field of that song
* Input parameters: Node *records is the linked list the program will be editing, and the program accesses their artists and songs
* Returns: none
*/
void editRecord(Node* records)
{
	char uniqueArtists[200][20] = { "" }; // list of all unique artists in the list (max 200 artists)
	int artistNum = 0; // number of artists in the uniqueArtists list

	printf("Choose an artist to edit a record (enter the number):\n");
	displayArtists(records, uniqueArtists, &artistNum);

	int artistChoice = 0;
	scanf("%d", &artistChoice);

	if (artistChoice <= 0 || artistChoice > artistNum) { // checks that the number chosen is actually on the list displayed to the screen
		printf("Choose a number out of the list.\n");
	}
	else {
		char songList[200][20] = { "" }; // list of all of the songs that belong to the chosen artist that will be displayed to the screen (max 200)
		int songNum = 0; // number of songs in the songList list

		printf("Choose a song by the artist (enter the number):\n");
		displaySongs(records, uniqueArtists[artistChoice - 1], songList, &songNum);

		int songChoice = 0;
		scanf("%d", &songChoice);

		if (songChoice <= 0 || songChoice > songNum) { // if the song number is in bounds
			printf("Choose a number out of the list.\n");
		}
		else {
			printf("Choose a field of the record to edit (enter the number):\n");
			printf("(1) Artist\n");
			printf("(2) Album title\n");
			printf("(3) Song title\n");
			printf("(4) Genre\n");
			printf("(5) Song length\n");
			printf("(6) Times played\n");
			printf("(7) Rating\n");

			int editChoice = 0;
			scanf("%d", &editChoice);
			getchar(); // reads the \n character to prevent issues with fgets() in the switch statement below
			/*
			* The line above was obtained from "https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/"
			*/

			// iterates through the nodes until we reach the node with the same song title as the chosen song
			for (int i = 1; strcmp(records->data.songTitle, songList[songChoice - 1]) != 0; i++) {
				records = records->pNext;
			}
			
			switch (editChoice) {
			case 1: // edit artist
				printf("Enter the new artist name (if the artist name has multiple words, enter in \"lastname, firstname\" format):\n");
				gets(records->data.artist);
				printf("Changed artist name to \"%s\".\n", records->data.artist);
				break;
			case 2: // edit album title
				printf("Enter the new album title:\n");
				gets(records->data.albumTitle);
				printf("Changed album title to \"%s\".\n", records->data.albumTitle);
				break;
			case 3: // edit song title
				printf("Enter the new song title:\n");
				gets(records->data.songTitle);
				printf("Changed song title to \"%s\".\n", records->data.songTitle);
				break;
			case 4: // edit genre
				printf("Enter the new genre:\n");
				gets(records->data.genre);
				printf("Changed genre to \"%s\".\n", records->data.genre);
				break;
			case 5: // edit song length
				printf("Enter the new song length (in \"minutes:seconds\" format):\n");
				scanf("%d:%d", &records->data.songLength.minutes, &records->data.songLength.seconds);
				printf("Changed song length to %d:%d.\n", records->data.songLength.minutes, records->data.songLength.seconds);
				break;
			case 6: // edit times played
				printf("Enter the new times played:\n");
				scanf("%d", &records->data.timesPlayed);
				printf("Changed times played to %d.\n", records->data.timesPlayed);
				break;
			case 7: // edit rating
				printf("Enter the new rating:\n");
				scanf("%d", &records->data.rating);
				printf("Changed rating to %d.\n", records->data.rating);
				break;
			default:
				printf("Choose a number out of the list.\n");
			}
		}
	}

	system("pause");
}




/*
* Function name: rateRecord()
* Programmer: Aabhwan Adhikary
* Created: 1/26/2025
* Description: Changes the rating of any song in the list of records
* Input parameters: Node *records is the linked list the program will be searching to find the song to change the rating
* Returns: none
*/
void rateRecord(Node* records)
{
	char songList[200][20] = { "" }; // list of all of the songs that belong to the chosen artist that will be displayed to the screen (max 200)
	int songNum = 0; // number of songs in the songList list

	printf("Choose a song from the list below (enter the number):\n");
	displaySongs(records, NULL, songList, &songNum);

	int songChoice = 0;
	scanf("%d", &songChoice);

	if (songChoice <= 0 || songChoice > songNum) { // if the song number chosen is on the list displayed to the screen (if it is in bounds)
		printf("Choose a number out of the list.\n");
	}
	else {
		for (int i = 1; i < songChoice; i++) { // iterates through the nodes until we reach target node
			records = records->pNext;
		}

		printf("What is the new rating for this song?:\n");
		int newRating = 0;
		scanf("%d", &newRating);
		
		if (newRating < 1 || newRating > 5) { // if the new rating is between 1-5
			printf("Rating needs to be between 1 and 5.\n");
		}
		else {
			records->data.rating = newRating; // changes the current node's rating to the new rating
			printf("Changed rating to %d.\n", records->data.rating);
		}

		system("pause");
	}
}

// created: 1/26/2025
// done
/*
* Function name: playRecord()
* Programmer: Aabhwan Adhikary
* Created: 1/26/2025
* Description: Chooses a song from the list to play and plays that song and all of the following songs in order (shows to the screen,
*				waits 3 seconds, and goes to the next song)
* Input parameters: Node *records is the linked list the program will be reading from to find the song
* Returns: none
*/
void playRecord(Node* records)
{

	char songList[200][20] = { "" }; // max of 200 songs
	int songNum = 0; // number of songs in the songList list

	printf("Choose a song from the list below to play (enter the number):\n");
	displaySongs(records, NULL, songList, &songNum);

	int songChoice = 0;
	scanf("%d", &songChoice);

	if (songChoice <= 0 || songChoice > songNum) { // if the song number is in bounds
		printf("Choose a number out of the list.\n");
	}
	else {
		for (int i = 1; i < songChoice; i++) { // iterates through the nodes until we reach target node
			records = records->pNext;
		}

		while (records != NULL) { // iterates through the nodes until we reach the end
			system("cls");
			printf("Playing \"%s\"...\n", records->data.songTitle);
			Sleep(3000); // waits 3 seconds
			records = records->pNext;
		}

		system("cls");
		printf("Finished playing.\n");
		system("pause");
	}
}




/*
* Function name: displayArtists()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Displays all of the unique artists to the screen and also adds them to an array
* Input parameters: Node *records is the linked list the program will be reading, and will be looking at the artists; char uniqueArtists[][]
*					is an array of strings (each of max length 20) where the unique artists will be stored; int *artistNum is the length
*					of the uniqueArtists array
* Returns: none
*/
void displayArtists(Node* records, char uniqueArtists[][20], int *artistNum)
{
	while (records != NULL) {
		if (isUnique(records->data.artist, uniqueArtists, *artistNum)) { // checks if the current node's artist value is unique (there is no other value matching the artist name in the array)
			strcpy(uniqueArtists[*artistNum], records->data.artist); // if it is, then copy the value to the uniqueArtists array at the current index
			printf("(%d) %s\n", ++(*artistNum), records->data.artist);
		}

		records = records->pNext;
	}
}




/*
* Function name: displaySongs()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Displays all of the songs (either in the entire list or ones that belong to a specific artist) to the screen and adds
*				them to an array of strings
* Input parameters: Node *records is the linked list the program will be reading, and will be looking at the song titles; char
*					songList[][20] is an array of strings that contain all of the song names that are being displayed to the screen	
*					(either all of the songs or those belonging to a specific artist); char *artist is a string representing the artist
*					(if there is any specific one) the program should be searching for specifically; int *songNum represents the length
*					of the song list array
* Returns: none
*/
void displaySongs(Node* records, char* artist, char songList[][20], int *songNum)
{
	if (artist == NULL) { // executes if there is no target artist
		while (records != NULL) { // iterates through the entire list of nodes until the end
			strcpy(songList[*songNum], records->data.songTitle); // copies the song title to the songList array at the current index
			printf("(%d) %s\n", ++(*songNum), records->data.songTitle);

			records = records->pNext;
		}
	}
	else { // executes if there is a particular artist's songs we are getting
		while (records != NULL) { // iterates through the entire list of nodes until the end
			if (strcmp(records->data.artist, artist) == 0) { // checks if the current node's artist value is equal to the target artist
				strcpy(songList[*songNum], records->data.songTitle); // copies the song title to the songList array at the current index
				printf("(%d) %s\n", ++(*songNum), records->data.songTitle);
			}

			records = records->pNext;
		}
	}
}




/*
* Function name: isUnique()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Looks through an array to see if a string is already in the array or not (in other words if the string is unique or not)
* Input parameters: char *str is the string the program will be comparing all of the strings in the string array with; char arr[][20]
*					is the array of strings the program will be checking the string with; int num is the length of the array
* Returns: int unique which represents if the string is unique (not already in the array, 1) or not (already in the array, 0)
*/
int isUnique(char *str, char arr[][20], int num)
{
	int unique = 1;
	for (int i = 0; i < num; i++) { // iterates up to a certain number/part of the array
		if (strcmp(str, arr[i]) == 0) { // checks if the target string is equal to the current value of arr
			unique = 0;
			break;
		}
	}

	return unique;
}




/*
* Function name: isMultipleWords()
* Programmer: Aabhwan Adhikary
* Created: 1/26/2025
* Description: Checks if a particular string has a comma (meaning they have multiple words)
* Input parameters: char *str is the string the program will be checking to see if it has commas or is multiple words long
* Returns: int multiple representing whether the program has multiple words/contains a comma (1) or not (0)
*/
int isMultipleWords(char* str)
{
	int multiple = 0;

	for (int i = 0; i < strlen(str); i++) { // iterates through the entire string
		if (str[i] == ',') { // checks if there is a comma in the string
			multiple = 1;
			break;
		}
	}
	
	return multiple;
}




/*
* Function name: insertAtFront()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Creates a node with the Record struct data provided, and inserts it to the front of the linked list
* Input parameters: Node **records is the linked list which the program will be modifying by adding the new Node to the front;
*					Record newRecord is the data that will be contained by the newly created Node
* Returns: int success representing whether the new node pMem was successfully created (1) or not (0)
*/
int insertAtFront(Node** records, Record newRecord)
{
	Node* pMem = createNode(newRecord); // creates a new node with the newRecord data
	int success = 0;

	if (pMem != NULL) { // checks if we allocated space for a node using createNode() successfully
		success = 1;

		if (*records == NULL) { // checks if the records list is empty
			*records = pMem;
		}
		else {
			pMem->pNext = *records;
			(*records)->pPrev = pMem;
			*records = pMem;
		}
	}

	return success;
}




/*
* Function name: createNode()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Allocates memory space for a new node pMem, and sets the new Node's data to the Record struct data passed into the function
* Input parameters: Record newRecord is the data that the new Node will contain
* Returns: Node *pMem which is the node that was just created
*/
Node* createNode(Record newRecord)
{
	Node* pMem = malloc(sizeof(Node));

	if (pMem != NULL) { // checks if we allocated memory successfully
		pMem->pNext = NULL, pMem->pPrev = NULL;
		pMem->data = newRecord;
	}

	return pMem;
}




/*
* Function name: printList()
* Programmer: Aabhwan Adhikary
* Created: 1/25/2025
* Description: Prints each Node data in the linked list to the screen if not looking for a specific artist, or prints all Node data
*				of a specific artist if looking for a specific artist's songs
* Input parameters: Node *records is the linked list which the program will be iterating through to print to the screen; char *artist
*					is the specific artist the program should look for (can be NULL)
* Returns: none
*/
void printList(Node* records, char* artist)
{
	system("cls");

	if (artist == NULL) { // not looking for any specific artist
		while (records != NULL) { // iterates through entire list of nodes
			printf("--> Artist: %s; Album: %s; Song name: %s; Genre: %s; Song length: %d:%d; Times played: %d; Rating: %d\n",
				records->data.artist, records->data.albumTitle, records->data.songTitle, records->data.genre,
				records->data.songLength.minutes, records->data.songLength.seconds, records->data.timesPlayed,
				records->data.rating);

			records = records->pNext;
		}
	}
	else { // looking for a specific artists songs
		while (records != NULL) { // iterates through entire list of nodes
			if (strcmp(records->data.artist, artist) == 0) { // checks if the artist value of the current node is equal to the target artist
				printf("--> Artist: %s; Album: %s; Song name: %s; Genre: %s; Song length: %d:%d; Times played: %d; Rating: %d\n",
					records->data.artist, records->data.albumTitle, records->data.songTitle, records->data.genre,
					records->data.songLength.minutes, records->data.songLength.seconds, records->data.timesPlayed,
					records->data.rating);
			}

			records = records->pNext;
		}
	}

	printf("\n");
}