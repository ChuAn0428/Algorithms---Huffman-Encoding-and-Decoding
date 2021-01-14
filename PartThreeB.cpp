/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Program 5 - Part Three B
Team 1: Ahmet Y. Cengiz, Chu-An Tsai
*/

#include "utility.h"

void partThreeB_decoding(){

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

    //initialiazing codeList
    for(int i=0; i<128; i++){
        codeList[i].character = "-1";
    }

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

    Node * parent = new Node(0,-1); //0 frequency, and -1 to show it is not a leaf node
    Node * node = nullptr;
	Node * temp = parent;
	string currentCode = "";
	string code;
	char currentBit;
	int counter = 0;

    for(int i=0; i<128; i++){
        if(codeList[i].character != "-1"){ //if there is a charcter
            code = codeList[i].code;
			temp = parent;
			counter++;
			while(code.length() > 0){
				currentBit = code[0];
				if(code.length() == 1){ //if this is the last bit of the code
					node = new Node(0, i); // create a node with the character
				}
				else{
					node = new Node(0,-1);
				}
				code = code.substr(1); //delete the current bit

				if(currentBit == '0'){	
					if(temp->left == nullptr){
						temp->left = node;	
					}
					temp = temp->left;
				}
				else if(currentBit == '1'){
					if(temp->right == nullptr){
						temp->right = node;
					}
					temp = temp->right;
				}
				else{
					cout << "Unexpected character in codetable.txt";
					delete node;
					exit(1);
				}
			}
        }
    }

    // Read data from source file
	ifstream readCodedFile("coded.txt", ios::in);
	// Give a warning and exit if fail to read the file
	if (readCodedFile.fail())
	{
		cout << "Unable to find coded.txt!";
		exit(1);
	}

	// Prepare to output the codetable
	ofstream writeFile;
	writeFile.open("decoded.txt");
	if (writeFile.fail())
	{
		cout << "Unable to find decoded.txt!";
		exit(1);
	}

	// Output the decoded.txt by replacing the code with its character
	int ch;
	char readChar;
    Node * current = parent;
	temp = nullptr;
	while ((ch = readCodedFile.get()) != EOF){

		readChar = static_cast<char>(ch);
		temp = current;

		if (readChar == '0') {
			current = temp->left;
			//cout << "0";
		}
		else if (readChar == '1') {
			current = temp->right;
			//cout << "1";
		}
		else {
			cout << "Unexpected input from coded.txt!";
			exit(1);
		}

		if (current->character == -1) { //Current is not a leaf node
			//do nothing
		}
		else {
			writeFile << static_cast<char>(current->character);
			//cout << static_cast<char>(current->character);
			current = parent; //go back to the root
		}
	}
	readCodedFile.close();
	writeFile.close();
}
