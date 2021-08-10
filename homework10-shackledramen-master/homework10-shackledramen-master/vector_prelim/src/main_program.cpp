/*
 * ToDoList Assignment
 *  *
 *  Created on: Nov 9, 2020
 *      Author: cj6bo
 */

#include "ToDoList.h"
#include <stdio.h>

using namespace std;

int main() {
	ToDoList list;
	string item1 = "grocery shopping";
	string item2 = "clean bathrooms";
	string item3 = "homework";
	string item4 = "laundry";
	list.add(item1);
	list.add(item2);
	list.add(item3);
	list.printList();
	string lastItem = list.getLast();
	string firstItem = list.getFirst();
	if (list.howManyItems() != 3) {
		exit(1);
	}
	list.remove(item4);
	list.remove(firstItem);
	list.remove(lastItem);
	if (list.howManyItems() != 1) {
		exit(1);
	}
	list.printList();
	return (0);
}
