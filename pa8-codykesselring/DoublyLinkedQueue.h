/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2022
Date: 4/27/2023
Description: Header file containing the DoublyLinkedQueue class declaration. Defines a DoublyLinkedQueue object that inherits from the DoublyLinkedList class, with common queue operations such as enqueueing and dequeuing elements, as well as some additional queue operations such as checking if the queue is empty and removing elements divisible by a given integer. This class is used in other programs, such as the Sieve algorithm.
*/
#ifndef DOUBLY_LINKED_QUEUE_H
#define DOUBLY_LINKED_QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class DoublyLinkedQueue : public DoublyLinkedList {
    public:    
		// common queue operations
		// implementation provided
		void displayQueue();

		// implementations not provided
		void enqueue(int);
		int dequeue();
		void clear();
		bool isEmpty();
		int size();

		// sieve specific queue operation
		// implementation not provided
		void removeDivisibleBy(int);

};

#endif
