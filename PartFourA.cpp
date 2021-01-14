/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Main function
Author: Chu-An Tsai, Ahmet Y. Cengiz
*/

#include "utility.h"

inline void partFourA_encoding()
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
	ifstream readSourceFile("clear.txt", ios::in);

	// Give a warning and exit if fail to read the file
	if (readSourceFile.fail())
	{
		cout << "Unable to find clear.txt!";
		exit(1);
	}

	// Prepare to output the codetable
	ofstream writeFile;
	writeFile.open("codedalt.txt", ios_base::binary);

	bitset<8> byteToSend;
	string code;
	int indexToWrite = 0;
	int currentBit;

	// Output the codedalt.txt by replacing the character with its code
	int oneChar;
	while ((oneChar = readSourceFile.get()) != EOF)
	{
		code = codeList[oneChar].code;

		while (code.length() > 0) {
			currentBit = code[0] - 48;
			code = code.substr(1);
			byteToSend[indexToWrite] = currentBit;
			indexToWrite = (indexToWrite + 1) % 8;
			if (indexToWrite == 0) { //bitset is full
				writeFile << char(byteToSend.to_ulong());
				//cout << char(byteToSend.to_ulong()) << endl;
				byteToSend.reset(); //sets all the bits to 0
			}
		}
	}
	writeFile << char(byteToSend.to_ulong());
	//cout << char(byteToSend.to_ulong()) << endl;
	readSourceFile.close();
	writeFile.close();
}