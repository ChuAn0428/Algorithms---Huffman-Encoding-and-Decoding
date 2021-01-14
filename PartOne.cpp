/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Program 5 - Part One
Team 1: Ahmet Y. Cengiz, Chu-An Tsai
*/

#include "utility.h"

void partOne_calculateFrequency()
{
	// Read data from file
	ifstream readFile;
	readFile.open("clear.txt");
	WordFreq dataArray[128];
	int lineCount = 0;

	// Give a warning and exit if fail to read the file
	if (readFile.fail())
	{
		cout << "Unable to find clear.txt!";
		exit(1);
	}

	// Load data while calculating the frequency
	string data;
	while (getline(readFile, data))
	{
		lineCount++;
		for (int i = 0; i < data.size(); i++)
		{
			dataArray[static_cast<int>(data[i])].character = static_cast<int>(data[i]);
			dataArray[static_cast<int>(data[i])].counts += 1;
		}
	}
	readFile.close();
	
	// Special operation for end-of-line character
	dataArray[static_cast<int>('\n')].character = '\n';
	dataArray[static_cast<int>('\n')].counts = lineCount;

	// Remove the rows that freq = 0 and write the output file
	ofstream writefile;
	writefile.open("freq.txt");
	int index = 0;
	for (int i = 0; i < 128; i++)
	{
		if (dataArray[i].counts != 0)
		{
			dataArray[index].character = dataArray[i].character;
			dataArray[index].counts = dataArray[i].counts;
			if (dataArray[i].character == 10)
			{
				writefile << "LF " << dataArray[index].counts << endl;
				//cout << "LF " << dataArray[index].counts << endl;		// print out for checking
			}
			else if (dataArray[i].character == 32)
			{
				writefile << "SP " << dataArray[index].counts << endl;
				//cout << "SP " << dataArray[index].counts << endl;		// print out for checking
			}
			else
			{
				writefile << static_cast<char>(dataArray[index].character) << " " << dataArray[index].counts << endl;
				//cout << static_cast<char>(dataArray[index].character) << " " << dataArray[index].counts << endl;	// print out for checking
			}
			index++;
		}
	}
	writefile.close();
}