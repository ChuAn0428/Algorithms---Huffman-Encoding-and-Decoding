/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Main function
Author: Chu-An Tsai, Ahmet Y. Cengiz
*/

#include "utility.h"

inline void partThreeA_encoding()
{
	// Read data from file
	ifstream readFile;
	readFile.open("codetable.txt");

	// Give a warning and exit if fail to read the file
	if (readFile.fail())
	{
		cout << "Unable to find codetable.txt!";
		exit(1);
	}

	// Import the characters and their frequencies by ASCII index (for encoding use)
	charCode codeList[128];
	string first;
	string second;
	int n = 0;
	while (readFile >> first >> second)
	{
		if (first == "LF")
		{
			codeList[static_cast<int>('\n')].character = first;
			codeList[static_cast<int>('\n')].code = second;
		}
		else if (first == "SP")
		{
			codeList[static_cast<int>(' ')].character = first;
			codeList[static_cast<int>(' ')].code = second;
		}
		else
		{
			codeList[static_cast<int>(first[0])].character = first;
			codeList[static_cast<int>(first[0])].code = second;
		}
		n++;
	}
	readFile.close();

	// Read data from file
	ifstream readSourseFile("clear.txt", ios::in);

	// Give a warning and exit if fail to read the file
	if (readSourseFile.fail())
	{
		cout << "Unable to find clear.txt!";
		exit(1);
	}

	// Prepare to output the codetable
	ofstream writefile;
	writefile.open("coded.txt");

	// Output the coded.txt by replacing the character with its code
	int oneChar;
	while ((oneChar = readSourseFile.get()) != EOF)
	{
		writefile << codeList[oneChar].code;
		//cout << codeList[oneChar].code << ", ";		// Print out for checking
	}
	readSourseFile.close();
	writefile.close();
}