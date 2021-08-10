/*
 * SequenceTestFramework.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: cj6bo
 *      edited by Jason Chung on Sept 5, 2020
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int getNextNumber( int num) {
	int nextNumber; //stores the next number in the sequence
	if(num % 2 == 0) //if the number is even the next number is the original number divided by two
	{
		nextNumber = num / 2;
	}
	else //if the number is odd, the next number is the sum of original number multiplied by 3 and 1
	{
		nextNumber = (num * 3) + 1;
	}
	return nextNumber; //return the next number in the sequence
	return 0;
}
int stepsToResolveToOne(int num) {
	int steps = 0; //stores the number of steps it took for sequence to resolve to 1. Since steps haven't been taken yet, steps = 0
	while(getNextNumber(num) != 1) //when the next number is not 1, continue to move through the sequence while adding to steps
	{
		steps++; //add 1 to steps because the next number does not equal 1 yet
		num = getNextNumber(num); //make the next number in the sequence the one we work with to move through the sequence
	}
	steps++; //number of steps for the number to be 1
	return steps; //return the number of steps taken for the sequence to resolve to 1
	return 0;
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




