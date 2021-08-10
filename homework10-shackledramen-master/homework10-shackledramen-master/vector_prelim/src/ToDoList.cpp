/*
 * ToDoList.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: gatep
 */

#include "ToDoList.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

ToDoList::ToDoList() {

}

void ToDoList::add(string item) {
	list.push_back(item);
	return;
}

void ToDoList::printList() {
	cout << "The vector elements are : ";
	for(int i=0; i < list.size(); i++){
		cout << list.at(i) << ", ";
	}
	cout << endl;
	return;
}

void ToDoList::remove(string item) {
	for(int i = 0; i < list.size(); i++) {
	    if(list.at(i).compare(item) == 0){
	    	list.erase(list.begin() + i);
	    }
	}
	return;
}

void ToDoList::remove(int index) {
	list.erase(list.begin() + index);
}

string ToDoList::getFirst() {
	return list.at(0);
}

string ToDoList::getLast() {

	return list.at(list.size()-1);
}

int ToDoList::howManyItems() {
	return list.size();
}



