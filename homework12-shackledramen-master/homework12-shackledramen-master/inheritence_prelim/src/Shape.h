/*
 * Shape Class
 *
 *  Created on: Dec 1, 2020
 *      Author: cj6bo
 */

#include <iostream>

class Shape
{
    protected:
		int size;

    public:
		Shape();
        Shape(int size_of_shape);
        void print();
};

class Triangle : public Shape
{
	private:
		void printTriangle();
	public:
		Triangle();
		Triangle(int size_of_shape);
};

class Square : public Shape
{
	private:
		void printSquare();
	public:
		Square();
		Square(int size_of_shape);
};

class Diamond : public Shape
{
	private:
		void printDiamond();
	public:
		Diamond();
		Diamond(int size_of_shape);
};
