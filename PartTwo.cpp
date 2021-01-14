/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Main function
Author: Chu-An Tsai, Ahmet Y. Cengiz
*/

#include "utility.h"

inline void partTwo_generateCodeTable()
{
	// Read data from file
	ifstream readFile;
	readFile.open("freq.txt");

	// Give a warning and exit if fail to read the file
	if (readFile.fail())
	{
		cout << "Unable to find codetable.txt!";
		exit(1);
	}

	// Import the characters and their frequencies by ASCII index (for encoding use)
	priority_queue< Node*, vector<Node*>, CompareFrequency > q; // <frequency, character (in ASCII), comparison method (top element is min)>
	string first;
	string second;
	int freq;
	stringstream converter; //to convert from char to int

	while (readFile >> first >> second)
	{
		converter.clear();
		converter.str(second);
		converter >> freq; //we need freq as an int for the priority queue
		Node* node = nullptr;

		if (first == "LF")
		{
			node = new Node(freq, 10);
		}
		else if (first == "SP")
		{
			node = new Node(freq, 32);
		}
		else
		{
			node = new Node(freq, static_cast<int>(first[0]));
		}

		q.push(node);
	}
	readFile.close();

	Node* parent = nullptr;
	Node* join = nullptr;
	Node* min1 = nullptr;
	Node* min2 = nullptr;
	bool keepGoing = true;

	//building Huffman Tree
	do {
		min1 = q.top(); //get the min frequency node
		q.pop();
		if (!q.empty()) {
			min2 = q.top(); //get the second min frequency node if there is one
			q.pop();
		}
		else { //if only one node is left, the tree is done. Last node is the parent
			keepGoing = false;
			parent = min1;
		}
		if (keepGoing) {
			join = new Node(min1->frequency + min2->frequency, -1, min1, min2); //-1 as character ASCII to show this is not a leaf node
			q.push(join);
		}

	} while (!q.empty() && keepGoing);

	// Prepare to output the codetable
	ofstream writeFile;
	writeFile.open("codetable.txt");
	if (writeFile.fail())
	{
		cout << "Unable to find output file!";
		exit(1);
	}

	printCodeTable(parent, "", writeFile); //prints the code table

	writeFile.close();
}
