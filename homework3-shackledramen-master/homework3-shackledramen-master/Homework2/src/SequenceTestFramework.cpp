/*
 * SequenceTestFramework.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: cj6bo
 *      edited by Jason Chung on Sept. 12 2020
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void setNextNumber(int &num) {
	int value; //initializes integer value named value that will store the value of the number passed by reference
	value = num; //assigns the value of the number to value
	if ((value % 2) == 0) { //if the value of the number is even set number to half of value
		num = value/2;
	}
	else //if the value of the number is odd, set the number to the value times 3 plus 1
	{
		num = (value*3 + 1);
	}
}
int stepsToResolveToOne(int num) {
	int counter = 0; //declares integer named counter, and it equals zero because we haven't gone through any steps of the sequence
	do {
		counter++; //adds 1 to the counter
		setNextNumber(num); //changes the number passed by replacing it with the next number in the sequence
	} while (num != 1); //add to counter while the sequence has not resolved to one
	return counter; //returns the number of steps for the sequence to resolve to one
}

int main() {
	int inputValues[10] = {5, 16, 42, 10000, 17, 32, 1079, 1842, 100, 1};
	int outputValues[10] = {5, 4, 8, 29, 12, 5, 49, 130, 25, 3};
	bool passingFlag = true;
	for (int i=0; i < 10; i++) {
		if (stepsToResolveToOne(inputValues[i]) != outputValues[i]) {
			passingFlag = false;
		}
	}
	if (passingFlag) {
		cout <<"Auto test passed!"<<endl;
	}
	else {
		cout <<"Auto test failed"<<endl;
	}
	return 0;
}




