/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2022
Date: 4/27/2023
Description: Header file containing the LinkedList class declaration. Defines a LinkedList object with common linked list operations such as adding and deleting nodes, as well as some bonus operations such as appending a node.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// LinkedList class needed for task 4
// no need for any changes here
class LinkedList {
	private:
	   struct Node {
		  int value;
		  struct Node * next;
	   }; 

	   Node * head;
	   
	   // task 4 prototype
	   int getMaxValueHelper(Node *, int);

	public:
	   LinkedList(); 
	   ~LinkedList(); 
	   void insertAtFront(int);
	   void displayList();
	   void appendNode(int);
	   
	   // task 4 prototype
	   int getMaxValue();
};

#endif
