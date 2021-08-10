#include "Rational.h"

using namespace std;

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int n) {
	numerator = n;
	denominator = 1;
}

Rational::Rational(int n, int d) {
//	cout<<"Creating rational number "<<n<<"/"<<d<<endl;
	numerator = n;
	denominator = d;

	if (numerator < 0 and denominator < 0) {
		numerator = -numerator;
		denominator = - denominator;
	}
	if (numerator*denominator < 0) {
		cout<<"Error negative fraction"<<std::endl;
		exit(1);
	}
}
int Rational::getNumerator() {
	return numerator;
}
int Rational::getDenominator() {
	return denominator;
}
int Rational::greatestCommonDenominator(int a, int b) {
	//cout<<"Finding greatest common denominator of "<<a<<" and "<<b<<endl;
	int gcd = 1;
	int smallerNum = a;
	if ( a > b ) {
		smallerNum = b;
	}
	for ( int i = 1; i <= smallerNum; i++ ) {
		if (((a % i) == 0) and ((b % i) == 0)) {
			gcd = i;
		}
	}
	//cout<<"Greatest common denominator is "<<gcd<<endl;
	return gcd;
}
void Rational::reduce() {
	int gcd = greatestCommonDenominator(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
}

void Rational::add(const Rational addend) {
	numerator = numerator*addend.denominator + addend.numerator*denominator;
	denominator = denominator*addend.denominator;
	reduce();
	return;
}
void Rational::sub(Rational subtractor) {
	numerator = numerator*subtractor.denominator - subtractor.numerator*denominator;
	denominator = denominator*subtractor.denominator;
	if ( numerator < 0 ) {
		cout<<"Error - negative fraction"<<std::endl;
	}
	reduce();
	return;

}
void Rational::mul(Rational multiplicand) {
	numerator *= multiplicand.numerator;
	denominator *= multiplicand.denominator;
	reduce();
}

void Rational::div(Rational dividend) {
	denominator *= dividend.numerator;
	numerator *= dividend.denominator;
	reduce();
}

bool Rational::less(Rational comparator) {
	return (numerator*comparator.denominator < comparator.numerator*denominator);
}

bool Rational::eq(Rational comparator) {
	return (numerator*comparator.denominator == comparator.numerator*denominator);
}

bool Rational::neq(Rational comparator) {
	return !eq(comparator);
}

void Rational::output(std::ostream& oss) {
	oss<<numerator<<"/"<<denominator<<std::endl;
}
