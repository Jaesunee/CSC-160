/*
 * Homework7.cpp
 *
 *  Created on: Sep 27, 2020
 *      Author: cj6bo
 */

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

namespace color {
       enum color{
         red   = 0xFF0000,
		 green = 0x009900,
		 blue  = 0x0000FF

  };
}
namespace shape {
       enum color{
         circle = 0,
		 triangle = 1,
		 square = 2
  };
}

void print_object(int color, int shape) {
	int redValue, greenValue, blueValue;
	blueValue = color & 0xff;
	greenValue = (color>>8) & 0xff;
	redValue = (color>>16) & 0xff;

	if((redValue > greenValue) && (redValue > blueValue)){
		switch (shape){
			case 0:
				cout << "This is a red circle" << endl;
				break;
			case 1:
				cout << "This is a red triangle" << endl;
				break;
			case 2:
				cout << "This is a red square" << endl;
				break;
			default:
				cout << "Invalid number for shape used. It should be an int between 1 and 3" << endl;
		}
	}else if ((greenValue > redValue) && (greenValue > blueValue)){
		switch (shape){
			case 0:
				cout << "This is a green circle" << endl;
				break;
			case 1:
				cout << "This is a green triangle" << endl;
				break;
			case 2:
				cout << "This is a green square" << endl;
				break;
			default:
				cout << "Invalid number for shape used. It should be an int between 1 and 3" << endl;
		}
	}else if((blueValue > redValue) && (blueValue > greenValue)){
		switch (shape){
			case 0:
				cout << "This is a blue circle" << endl;
				break;
			case 1:
				cout << "This is a blue triangle" << endl;
				break;
			case 2:
				cout << "This is a blue square" << endl;
				break;
			default:
				cout << "Invalid number for shape used. It should be an int between 1 and 3" << endl;
		}
	}else{
		cout << "invalid hexadecimal value for color or red, green, or blue values are equal (for example: black or white)." << endl;
	}
}

int main() {
	int random_color = 0;
	int random_shape = 0;
	srand(time(NULL));
	print_object(color::red, shape::circle);
	print_object(color::green, shape::square);
	print_object(color::blue, shape::triangle);
	for (int i=0; i < 10; i++) {
		random_color = rand() % 0xFFFFFF;
		random_shape = rand() % 3;
		print_object(random_color, random_shape);
	}
	return (0);
}
