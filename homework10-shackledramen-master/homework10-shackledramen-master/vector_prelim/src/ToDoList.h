/*
 * ToDoList.h
 *
 *  Created on: Nov 15, 2020
 *      Author: gatep
 */

#ifndef SRC_TODOLIST_H_
#define SRC_TODOLIST_H_

#include <stdlib.h>
#include <string>
#include <vector>

class ToDoList
{
    private:
		std::vector<std::string> list;

    public:
        ToDoList();
        void add(std::string item);
        void printList();
        void remove(std::string item);
        void remove(int index);
        std::string getFirst();
        std::string getLast();
        int howManyItems();
};

#endif /* SRC_TODOLIST_H_ */
