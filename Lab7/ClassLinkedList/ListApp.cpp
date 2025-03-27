#include "ListApp.h"

ListApp::ListApp()
{
	// ios::in indicates create input file stream - already input by default since mInputStream is a ifstream type;
	// could leave out the ios::in
	mInputStream.open("ExamScores.csv", ios::in);
	// ios::out indicates create output file stream - already output by default since mOutputStream is a ofstream type;
	// could leave out the ios::out
	mOutputStream.open("ExamStats.txt", ios::out);
}

ListApp::~ListApp()
{
	cout << "Inside ListApp's destructor! Closing open files!" << endl;

	// is_open returns true of file is open! If open () failed during in the construction of the ListApp,
	// then we will not try to close the stream!
	if (mInputStream.is_open())
	{
		mInputStream.close();
	}
	if (mOutputStream.is_open())
	{
		mOutputStream.close();
	}
}

void ListApp::runApp(void)
{
	// files are opened in the constructor!
	if (mInputStream.is_open()) // verify file is in fact open!
	{
		mInputStream >> mList; // apply the overloaded stream extraction operator that matches (ifstream, List)
		mOutputStream << mList;     // could you write an overloaded stream insertion operator for (ostream, List)
	}
}


////////////////////// nonmember functions ////////////////////////////

// This overloaded operator >> will read each line of the input .csv file and extract the scores. 
// It will then place the scores into a linked list!
// precondition: file must already be open!
ifstream& operator>> (ifstream& input, List& rhs)
{
	char line[100] = "";
	input.getline(line, 100); // read in the line that contains header information (Name, Score)!

	while (!input.eof()) // read all lines from the file, populate the list with the scores only!
	{
		// example format: "Smith,John",99
		input.getline(line, 100, ','); // split line based on comma (last name)
		input.getline(line, 100, ','); // still on same line because stopped at first comma, get next word (first name)
		input.getline(line, 100);      // read the rest of the line (score)
		// convert char * line to int score type
		int score = atoi(line); // atoi() converts char * to int
		rhs.insertAtFront(score); // no need to retain the same order as in the file, use insertAtFront () because it's efficient!
	}

	return input;
}

int findHighScore(const List* pHead)
{
	int max = 0;

	ListNode* pCur = pHead->getHeadPtr();
	while (pCur != nullptr) {
		if (pCur->getData() > max) {
			max = pCur->getData();
		}

		pCur = pCur->getNextPtr();
	}

	return max;
}

int findLowScore(const List* pHead)
{
	int min = pHead->getHeadPtr()->getData();

	ListNode* pCur = pHead->getHeadPtr();
	while (pCur != nullptr) {
		if (pCur->getData() < min) {
			min = pCur->getData();
		}

		pCur = pCur->getNextPtr();
	}

	return min;
}

double findMeanScores(const List* pHead)
{
	int sum = 0, count = 0;

	ListNode* pCur = pHead->getHeadPtr();
	while (pCur != nullptr) {
		sum += pCur->getData();
		count++;

		pCur = pCur->getNextPtr();
	}

	double mean = (double)sum / count;

	return mean;
}

ofstream& operator<<(ofstream& output, List& rhs)
{
	output << "High score: " << findHighScore(&rhs) << endl;
	output << "Low score: " << findLowScore(&rhs) << endl;
	output << "Mean: " << findMeanScores(&rhs) << endl;

	return output;
}
