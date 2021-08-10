/*
 * Pointer Assignment Base
 *  *
 *  Created on: Nov 9, 2020
 *      Author: cj6bo
 */

#include <iostream>
using namespace std;
//takes two integer arguments
//swaps the values stored in teh integer arguments
void swapInt(int &firstNumber, int &secondNumber) {
	int temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;
	return;
}

//takes two integer pointers
//swaps pointer values without changing
//the values in the address pointed to by
//the pointers
void swapIntPtr(int *&firstPointer, int *&secondPointer) {
	int *temp = firstPointer;
	firstPointer = secondPointer;
	secondPointer = temp;
	return;
}

//takes two integer pointers
//swaps the values of the integers
//pointed to by the pointers
//without editing the pointers
void swapIntPtrValues(int *firstPointer, int *secondPointer) {
	int temp = *firstPointer;
	*firstPointer = *secondPointer;
	*secondPointer = temp;
	return;
}
int main() {

	int val1 = 1;
	int val2 = 2;
	int* ptr1 = &val1;
	int* ptr2 = &val2;
	int* ptr1a = &val1;
	int* ptr2a = &val2;

	swapInt(val1, val2);
	cout<<"Executing test 1 integer swap"<<endl;
	if ( ( val1 == 2 ) and ( val2 == 1 ) and (ptr1 == ptr1a) and (ptr2 == ptr2a) ) {
		cout<<"Test1 passed"<<endl;
	}
	else {
		cout<<"Test1 failed"<<endl;
		exit(1);
	}

	cout<<"Executing test 2 swap pointer values"<<endl;
	swapIntPtr(ptr1, ptr2);
	if ( (val1 == 2) and (val2 == 1) and (ptr1 == ptr2a) and (ptr2 == ptr1a) ) {
		cout<<"Test2 passed"<<endl;
	}
	else {
		cout<<"Test2 failed"<<endl;
		exit(1);
	}

	cout<<"Executing test 3 swap values of objects pointed to"<<endl;
	swapIntPtrValues(ptr1, ptr2);
	if ( (val1 == 1) and (val2 == 2) and (ptr1 == ptr2a) and (ptr2 == ptr1a) ) {
		cout<<"Test3 passed"<<endl;
	}
	else {
		cout<<"Test3 failed"<<endl;
		exit(1);
	}


	return (0);
}
