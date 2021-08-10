/*
 * Rational.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: gatep
 */

#include "Rational.h"

Rational::Rational(int numerator, int denominator)
{
	rationalNumerator = numerator;
	rationalDenominator = denominator;
	reduce();
}

Rational::Rational()
{
	rationalNumerator = 0;
	rationalDenominator = 1;
}

void Rational::reduce()
{
	int numerator = rationalNumerator;
	int denominator = rationalDenominator;
	int gcf;

	//If one number is negative, end program
	if((rationalNumerator < 0) || (rationalDenominator < 0))
		{
			cout << "Negative values for numerator or denominator are not legal. \n";
			exit(1);
		}

	//this loop subtracts the smaller number from larger number so that that number is stored in place of the larger number
	//In this way, the loop continues until the two numbers equal each other and equal the greatest common factor
	while(numerator != denominator)
	{
		if(numerator > denominator)
		{
			numerator -= denominator;
		}
		else
		{
			denominator -= numerator;
		}
	}

	gcf = numerator; //both numbers are equal to gcf, so set gcf to numerator (this is not the numerator of the object)

	//divide the numerator and denominator by the gcf to reduce the rational
	rationalNumerator /= gcf;
	rationalDenominator /= gcf;
}

void Rational::add(Rational rational)
{
	rationalNumerator *= rational.getDenominator();
	rationalNumerator += rational.getNumerator() * rationalDenominator;
	rationalDenominator *= rational.getDenominator();
	reduce();
}

void Rational::sub(Rational rational)
{
	rationalNumerator *= rational.getDenominator();
	rationalNumerator -= rational.getNumerator() * rationalDenominator;
	rationalDenominator *= rational.getDenominator();
	reduce();
}

void Rational::mul(Rational rational)
{
	rationalNumerator *= rational.getNumerator();
	rationalDenominator *= rational.getDenominator();
	reduce();
}

void Rational::div(Rational rational)
{
	rationalNumerator *= rational.getDenominator();
	rationalDenominator *= rational.getNumerator();
	reduce();
}

bool Rational::less(Rational rational){
	return ((rationalNumerator * rational.getDenominator()) < (rational.getNumerator() * rationalDenominator));
}

bool Rational::eq(Rational rational){
	return ((rationalNumerator == rational.getNumerator()) && (rationalDenominator == rational.getDenominator()));
}

bool Rational::neq(Rational rational){
	return ((rationalNumerator != rational.getNumerator()) || (rationalDenominator != rational.getDenominator()));
}

int Rational::getNumerator()
{
	return rationalNumerator;
}

int Rational::getDenominator()
{
	return rationalDenominator;
}

void Rational::outputRational(ostream& out)
{
	out << rationalNumerator << "/" << rationalDenominator;
}
