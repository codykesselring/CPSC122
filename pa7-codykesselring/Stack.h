/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2022
 Date: 4/20/2023
 Programming Assignment: PA7                                                           
 Description: this header file utilizes the linked list to make a stack of strings that are used to evaluate the infix and postfix expressions
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Stack inherits from LinkedList
class Stack : public LinkedList {
	public:
	   // common stack operations
	   void push(string);
	   string pop();
	   string peek();
	   bool isEmpty();
};

#endif
