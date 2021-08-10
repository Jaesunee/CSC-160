/*
 * Rational.h
 *
 *  Created on: Oct 4, 2020
 *      Author: gatep
 */
#ifndef SRC_RATIONAL_H_
#define SRC_RATIONAL_H_
#include <iostream>
#include <fstream>
using namespace std;

class Rational {
public:
	Rational(int numerator, int denominator); //overloaded constructor for Rational class that accepts integer numerator and denominator
	Rational(); //default constructor for Rational class
	void add(Rational rational); //adds argument to rational
	void sub(Rational rational); //subtracts argument from rational
	void mul(Rational rational);//multiplies rational by argument
	void div(Rational rational); //divides rational by argument
	bool less(Rational rational); //returns true if rational is less than argument
	bool eq(Rational rational); //returns true if rational is equal to argument
	bool neq(Rational rational); //returns true if rational is not equal to argument
	int getNumerator(); //accessor function for rational's numerator
	int getDenominator(); //accessor function for rational's denominator
	void outputRational(ostream& out); //writes rational to output stream

private:
	int rationalNumerator; //stores rational's numerator
	int rationalDenominator; //stores rational's denominator
	void reduce(); //reduces fraction
};

#endif /* SRC_RATIONAL_H_ */
