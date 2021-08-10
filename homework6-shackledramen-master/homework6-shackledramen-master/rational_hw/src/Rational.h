/*
 * Rational Class
 *
 *  Created on: Sep 27, 2020
 *      Author: cj6bo
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Rational
{
    private:
        int numerator;
        int denominator;
        void reduce();

    public:
        Rational();
        Rational(int n);
        Rational(int n, int d);
        int getNumerator();
        int getDenominator();
        void add(Rational addend);
        void sub(Rational subtractor);
        void mul(Rational multiplicand);
        void div(Rational dividend);
        int greatestCommonDenominator(int a,int b);
        bool less(Rational comparator);
        bool eq(Rational comparator);
        bool neq(Rational comparator);
        void output(std::ostream& oss);
};
