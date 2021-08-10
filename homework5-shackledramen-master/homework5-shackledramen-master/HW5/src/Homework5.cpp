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
using namespace std;

int main() {
	//insert any test code for Rational class
	Rational rational1, rational2(5,10), rational3(5,15), rational4(5,20);
	ofstream outputFractions;

	//open fractions file in output stream in append mode because we're adding fractions to the text file
	outputFractions.open("fractions.txt", std::ios_base::app);
	if(outputFractions.fail()) //if opening the fractions file fails...
	{
		cout << "main file opening failed.\n"; //print fraction file failed to open
		exit(1); //exit program
	}

	//prints reduced fractions 0, 1/2, 1/3, and 1/4
	cout << rational1.getNumerator() << endl;
	cout << rational2.getNumerator() << "/" << rational2.getDenominator() << endl;
	cout << rational3.getNumerator() << "/" << rational3.getDenominator() << endl;
	cout << rational4.getNumerator() << "/" << rational4.getDenominator() << endl;

	//adds 1/2 and 1/3 which is 5/6 and prints it out
	rational2.add(rational3);
	cout << rational2.getNumerator() << "/" << rational2.getDenominator() << endl;

	//subtract 1/3 from 5/6 which is 1/2
	rational2.sub(rational3);
	cout << rational2.getNumerator() << "/" << rational2.getDenominator() << endl;

	//multiply 1/2 by 1/4 which is 1/8
	rational2.mul(rational4);
	cout << rational2.getNumerator() << "/" << rational2.getDenominator() << endl;

	//divide 1/8 by 1/3 which is 3/8
	rational2.div(rational3);
	cout << rational2.getNumerator() << "/" << rational2.getDenominator() << endl;

	//writes rational2 to output file fractions
	rational2.outputRational(outputFractions);

	//checks whether .less member function works
	if (rational4.less(rational2))
	{
		cout << "1/4 is less than 3/8" << endl;
	}

	//checks whether .eq() member function works
	if(!(rational2.eq(rational1)))
	{
		cout << "3/8 does not equal 0" << endl;
	}

	//checks whether .neq() member function works
	if(rational2.neq(rational1))
	{
		cout << "3/8 does not equal 0" << endl;
	}

	//print out that this doesn't work because negative values in rational are illegal and stops program
	//rational4.sub(rational2);

	return 0;
}
