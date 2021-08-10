/*
 * Fortune Teller
 *  *
 *  Created on: Nov 9, 2020
 *      Author: cj6bo
 */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	std::vector<std::string> fortunes; //string vector of fortunes
	ifstream fortunesFile; //input stream of fortunes
	int fortuneCount = 0; //stores the number of fortunes in fortunesFile (# of lines)
	char response; //stores the response of the user when prompted
	int random; // stores the random integer for the random fortune picked
	srand(time(0)); //initialize random seed for random function using time

	fortunesFile.open("answer_list.txt"); //open answer_list as input file

	if(fortunesFile.fail()) //if opening the fortunes file fails...
	{
		cout << "fortunes file opening failed.\n"; //print fortunes file failed to open
		exit(1); //exit program
	}

	string str; //placeholder for each fortune

	while (getline(fortunesFile, str)){ //while there are lines to be read in
		if (str.size() > 0){ //if the line isn't empty..
			fortunes.push_back(str); //add the string to the vector fortunes
			fortuneCount++; //increase fortune count by 1
		}
	}

	fortunesFile.close(); //close the fortunes file because we've already read values in

	cout<<"Do you want your fortune read? Type y if you want your fortune read and anything else if not." << endl; //prompt user to read fortune
	cin >> response; //read in user response to response char
	if(response == 'y'){ //if the user wants their fortune...
		random = rand() % fortuneCount; //create random value between 0 and last index of vector
		cout<< "Your fortune is: " + fortunes[random] << endl; //print the random fortune
	}else{ //if the user didn't want their fortune...
		cout<< "maybe you can get your fortune next time :)"; //print goodbye message
		exit(1); //exit program
	}
	return (0); //exit program
}
