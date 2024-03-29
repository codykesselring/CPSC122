#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2022
Date: 4/27/2023
Description: Header file containing the DoublyLinkedList class declaration. Defines a DoublyLinkedList object with common linked list operations such as adding and deleting nodes, as well as some bonus operations such as inserting nodes in order. This class is used as a building block for implementing a queue and a stack in other programs.
*/
#include <iostream>

using namespace std;

struct Node {
	int value; 
	struct Node * next; 
	struct Node * prev; // makes the Node have double links
}; 
		
class DoublyLinkedList {
	protected:
	   	Node * head; // list head pointer
	   	Node * tail; // list tail pointer

	public:
	   	DoublyLinkedList(); // DVC
	   	~DoublyLinkedList(); // destructor
	   	
	   	Node * getHead() const;
	   	Node * getTail() const;
	   	void setHeadAndTail(Node *, Node *);
		  
	   	// common linked list operations
	   	// implementations provided
	   	void destroyList();
	   	void displayList();
	   	
	   	// needed by DoublyLinkedQueue
	   	// implementations not provided
		void addToEnd(int); // AKA insert at end, append
	    int deleteAtFront();
	   	int deleteNode(int);
	   	
	   	// not needed by DoublyLinkedQueue
	   	// implementations not provided
	   	// implement for BONUS
		void addToFront(int);
	   	int deleteAtEnd();
	    void insertInOrder(int);
	   	
};

#endif
