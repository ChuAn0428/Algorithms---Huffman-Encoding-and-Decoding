/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Main function
Author: Chu-An Tsai, Ahmet Y. Cengiz
*/
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <set>
#include <map>
#include <unordered_map> 
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

struct WordFreq
{
	int character = { 0 };
	int counts = 0;
};

//Used in Part3A and Part4A
struct charCode
{
	string character;
	string code;
};

struct Node{
    int frequency;
    int character;
    Node * left;
    Node * right;

    Node(int fr, int ch) 
        : frequency(fr), character(ch), left(nullptr), right(nullptr) {}

    Node(int fr, int ch, Node * lt, Node * rt) 
        : frequency(fr), character(ch), left(lt), right(rt) {}
};

struct CompareFrequency { 
    bool operator()(Node const * n1, Node const * n2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return n1->frequency > n2->frequency; 
    } 
};

inline void printCodeTable(Node * node, string code, ostream & writeFile){
	if (node == nullptr) 
		return; 

	string codeLeft = code + '0';
	printCodeTable(node->left, codeLeft, writeFile); 

	if(node->character != -1){
		if(node->character == 10){
			writeFile << "LF" << " " << code << endl;
		}
		else if(node->character == 32){
			writeFile << "SP" << " " << code << endl;
		}
		else{
			writeFile << static_cast<char>(node->character) << " " << code << endl;
		}
	}

	string codeRight = code +'1';
	printCodeTable(node->right, codeRight, writeFile); 
	
	delete node; //free the memory
}

#endif //UTILITY_H
#pragma once

