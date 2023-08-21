/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2022
 Date: 4/20/2023
 Programming Assignment: PA7                                                           
 Description: this header file contains the linked list prototypes needed for the stack class
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
	protected:
		struct Node {
			string value; 
			struct Node * next; 
		}; 

	   	Node * head; // list head pointer

	public:
	   	LinkedList(); // DVC
	   	~LinkedList(); // destructor
		  
	   	// common linked list operations
	   	void destroyList();
	   	void displayList();
	   	void insertAtFront(string);
	   	string deleteAtFront();
};

#endif
