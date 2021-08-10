/*
 * Inheritence homework
 *
 *  Created on: Dec 1, 2020
 *      Author: cj6bo
 */

#include <iostream>
#include <vector>

#include "Shape.h"

using namespace std;

int main() {
	std::vector<Shape*> shapes;
	shapes.push_back(new Triangle(3)); //will be replace with new Triangle(3)
	shapes.push_back(new Triangle(21));
	shapes.push_back(new Square(10)); //will be replaced with new Square(10)
	shapes.push_back(new Square(2));
	shapes.push_back(new Diamond(3)); //will be replaced with new Diamond(3)
	shapes.push_back(new Diamond(3));

	for (const auto& i:shapes) {
		i->print();
	}
	return (0);
}
