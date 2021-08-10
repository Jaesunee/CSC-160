/*
 * Homework5.cpp
 *
 *  Created on: Sep 27, 2020
 *      Author: cj6bo
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Rational.h"
#include <string>

using namespace std;

int main() {
	int testNumerator1, testNumerator2, testDenominator1, testDenominator2;
	string testRational2, testStringNumerator2, testStringDenominator2;
	string delimiter = ",";

	cout << "Please enter two non-zero integers: ";
	cin >> testNumerator1;
	cin >> testDenominator1;

	Rational fraction1(testNumerator1, testDenominator1);

	cout << "Please enter Rational number as two values in parenthesis separated by a comma: ";
	cin >> testRational2; //stores user input as a string to process

	//the following lines parse the string with the two values so that the fraction's values are the user input integers
	testStringNumerator2 = testRational2.substr(1, testRational2.find(delimiter)-1);
	testStringDenominator2 = testRational2.substr(testRational2.find(delimiter)+1);
	testStringDenominator2.pop_back();
	testNumerator2 = stoi(testStringNumerator2);
	testDenominator2 = stoi(testStringDenominator2);

	//making fractions 2-4 using different constructors
	Rational fraction2(testNumerator2, testDenominator2);
	Rational fraction3;
	Rational fraction4(10);

	//testing Rational class
	cout<<"Here are all the fractions:"<<endl;
	fraction1.output(cout);
	fraction2.output(cout);
	fraction3.output(cout);
	fraction4.output(cout);
	fraction1.add(fraction2);
	cout << "Your two fractions added together are: ";
	fraction1.output(cout);

	fraction1.sub(fraction2);
	cout<< "The original first fraction is: ";
	fraction1.output(cout);
	cout<< "If that worked, subtraction function works." << endl;
	if (fraction1.eq(fraction3)) {
		cout<<"The first fraction is 0"<<endl;
	}else{
		cout<< "The first fraction is not 0"<<endl;
	}
	if(fraction3.neq(fraction4)){
		cout<< "0 does not equal 10, so the not equal function works." << endl;
	}
	fraction1.mul(fraction4);
	cout<< "The first fraction times 10 is ";
	fraction1.output(cout);
	fraction1.div(fraction4);
	cout<< "Before the multiplication the fraction was: ";
	fraction1.output(cout);
	cout << "If that worked, division function works." << endl;
	if(fraction3.less(fraction4)){
		cout<< "0 is less than 10";
	}
	return (0);
}
