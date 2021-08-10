/*
 * Homework8.cpp
 *
 *  Created on: Sep 27, 2020
 *      Author: cj6bo
 *  edited on: 10/25/2020 by Jason C
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <limits.h>

namespace color {
       enum color{
         red   = 0xFF0000,
		 green = 0x00FF00,
		 blue  = 0x0000FF,
		 white = 0x000000

  };
}
namespace shape {
       enum shape{
         circle = 0,
		 triangle = 1,
		 square = 2
  };
}

void print_object(int color, int shape) {

	int r = color >> 16 & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	color::color estimated_color = color::white;

	//check for exception for shape value, value has to be between 0 and 2 inclusive
	try{
		if(shape < 0 || shape > 2){
			throw shape;
		}
	}
	catch(int shape){
		std::cout<< "Your shape, " << shape << ", is invalid because it isn't a number between(inclusive) 0 and 2"<<std::endl;
		exit(1);
	}

	if ( (r > g) and (r > b) ) {
		estimated_color = color::red;
	}
	else if ( (g > r) and (g > b) ) {
		estimated_color = color::green;
	}
	else if ( (b > r) and (b> g) ) {
		estimated_color = color::blue;
	}
	std::cout<<"The object is a ";
	switch ( estimated_color ) {
	case color::red: std::cout<<"red "; break;
	case color::green: std::cout<<"green "; break;
	case color::blue: std::cout<<"blue "; break;
	default:
		//if none of the colors are dominant over the others, we check for equal values causing exception
		try{ //throw different numbers depending on case, which is determined by which colors match
			if (r == g && (r == b && b == g)){
				throw 1;
			}else if(r == g){
				throw 2;
			}else if(r == b){
				throw 3;
			}else if(b == g){
				throw 4;
			}
		}
		catch(int exceptionCase){
			switch(exceptionCase){
				case 1:std::cout << "The color is invalid because the red, green, and blue values are the same"<<std::endl; break;
				case 2:std::cout << "The color is invalid because the red value is the same as green one."<<std::endl; break;
				case 3:std::cout << "The color is invalid because the red value is the same as the blue one."<<std::endl; break;
				case 4:std::cout << "The color is invalid because the blue value is the same as the green one"<<std::endl; break;
				default: break;
			}
		}
		std::cout<< "Your color is invalid"<<std::endl;
		exit(1);
	}

	switch ( shape ) {
	case shape::triangle: std::cout<<"triangle";break;
	case shape::square: std::cout<<"square "; break;
	case shape::circle: std::cout<<"circle "; break;
	default: std::cout<< "Your shape is invalid"<<std::endl;
		exit(1);
	}
	std::cout<<std::endl;
}

int main() {
	int random_color = 0;
	int random_shape = 0;
	srand(time(NULL));
	print_object(color::red, shape::circle);
	print_object(color::green, shape::square);
	print_object(color::blue, shape::square);
	for (int i=0; i < 10; i++) {
		random_color = rand() % 0xFFFFFF;
		random_shape = rand() % 3;
		print_object(random_color, random_shape);
	}
	return (0);
}
