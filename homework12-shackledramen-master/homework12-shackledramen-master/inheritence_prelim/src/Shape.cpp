#include "Shape.h"


using namespace std;

Shape::Shape(){
	size = 0;
}

Shape::Shape(int size_of_shape) {
	size = size_of_shape;
}

Triangle::Triangle(){
	size = 0;
}

Triangle::Triangle(int size_of_shape){
	size = size_of_shape;
	if (size % 2 == 0) {
		size++;
		cout<<"Invalid Size for specified Shape, making larger"<<endl;
	}
}

Square::Square(){
	size = 0;
}

Square::Square(int size_of_shape){
	size = size_of_shape;
	cout << "Making square of size" + size << endl;
}

Diamond::Diamond(){
	size = 0;
}

Diamond::Diamond(int size_of_shape){
	size = size_of_shape;
	if (size < 3) {
		size = 3;
		cout<<"Making diamond minimum size of 3"<<endl;
	}
	if ( ( (size - 3) % 2) != 0) {
		size++;
		cout<<"Invalid Size for specified shape, making larger"<<endl;
	}
}

void Triangle::printTriangle() {
	//first row - single star
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<"*";
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<endl;
	//row 2-(last-1) spaces * spaces * spaces
	for (int i=0; i < (size - 3)/2; i++) {
		for (int j=1; j< (size-1)/2-i; j++) cout<<" ";
		cout<<"*";
		for (int j=0; j<(i*2+1); j++) cout<<" ";
		cout<<"*";
		for (int j=0; j< size/2-i; j++) cout<<" ";
		cout<<endl;
	}
	//last row all *s
	for (int i=0; i< size; i++){
		cout<<"*";
	}
	cout<<endl;
}
void Diamond::printDiamond() {
	//first row - single star
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<"*";
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<endl;
	//row 2-middle spaces * spaces * spaces
	for (int i=0; i < (size - 3)/2; i++) {
		for (int j=1; j< (size-1)/2-i; j++) cout<<" ";
		cout<<"*";
		for (int j=0; j<(i*2+1); j++) cout<<" ";
		cout<<"*";
		for (int j=0; j< size/2-i; j++) cout<<" ";
		cout<<endl;
	}
	//middle row - (last-1)
	for (int i=0; i < ((size - 3)/2); i++){
		for(int j = 0; j < i + 1;j ++)
			cout<< " ";
		cout << "*";
		for(int j = 0; j < (size-4) - i*2;j ++)
			cout<< " ";
		cout << "*";
		cout <<endl;
	}
	//last row - single star
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<"*";
	for (int j=0; j< size/2; j++) {
		cout<<" ";
	}
	cout<<endl;
}
void Square::printSquare() {
    //first row of all asterisks according to size
    int size = 5;
    for (int j=0; j< size; j++) {
		cout<<"*";
	}
	//2nd row - (last-1) * spaces *
	cout<<endl;
	for (int j=0; j< size-2; j++) {
		cout<<"*";
        for (int j=0; j< size-2; j++) {
		    cout<<" ";
	    }
	    cout<<"*";
	    cout<< endl;
	}
    //last row //first row of all asterisks according to size
    for (int j=0; j< size; j++) {
		cout<<"*";
	}
	cout<<endl;
}
void Shape::print(){
		cout<< "This is a shape of unknown type with size " + size << endl;
}

