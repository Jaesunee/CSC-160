/*
 * Homework4.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: cj6bo
 *      edited by Jason Chung on Sept 20, 2020
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main() {
	ifstream mainTextInStream; //declare first input-file stream variable
	ifstream subTextInStream; //declare second input-file stream variable
	std::string str; //placeholder string for each line in main file
	std::string str2; //placeholder string for each line in subset file
	string main; //string to contain text in main file
	string subset; //string to contain text in subset file

	mainTextInStream.open("MobyDick.txt"); //connects first input stream to main file
	if(mainTextInStream.fail()) //if opening the main file fails...
	{
		cout << "main file opening failed.\n"; //print main file failed to open
		exit(1); //exit program
	}

	subTextInStream.open("subset.txt");//connects first input stream to subset file
	if(subTextInStream.fail())//if opening the subset file fails...
	{
		cout << "subset file opening failed.\n";//print subset file failed to open
		exit(1);//exit program
	}

	while(mainTextInStream >> str){ //loops through the main file and sets placeholder string to each word
		main += str; //adds the placeholder string to the main string which reads the file to a string
	}

	while(subTextInStream >> str2){ //loops through the main file and sets placeholder string to each word
		subset += str2; //adds the placeholder string to the subset string which reads the file to a string
	}

	if (main.find(subset) != std::string::npos){ //if the main string contains the subset string...
		cout <<"\nEntire substring found!" << std::endl; //print that the subset string was found in the main one
	}
	else { //otherwise...
		cout <<"\nRan out of words in master file" <<std::endl; //print that the subset string was not found in the main one
	}

	mainTextInStream.close(); //dissociates the main file from input stream 1
	subTextInStream.close(); //dissociates the subset file from input stream 2

	return(0); //end the program
}
