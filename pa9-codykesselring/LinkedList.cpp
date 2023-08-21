/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2023
Date: 5/2/2023
Description: declares the definition for each linked list function in order to run task 4, which involves a list that we're finding the maximum value of
*/
#include "LinkedList.h"

/*
Function: LinkedList::LinkedList()
Description: Constructor for the LinkedList class. Initializes the head of the list to NULL.
Input Parameters: None
Returns: None
*/
LinkedList::LinkedList() {
	head = NULL;
}

/*
Function: LinkedList::~LinkedList()
Description: Destructor for the LinkedList class. Deletes all nodes in the list and sets the head to NULL.
Input Parameters: None
Returns: None
*/
LinkedList::~LinkedList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	
	head = NULL;
}

/*
Function: LinkedList::displayList()
Description: Displays the linked list in the format "head->value->value->...->NULL".
Input Parameters: None
Returns: None
*/
void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

/*
Function: LinkedList::appendNode(int newValue)
Description: Appends a new node with the given value to the end of the list.
Input Parameters: int newValue - the value to be added to the new node
Returns: None
*/
void LinkedList::appendNode(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
	} 
	else {
		Node * currNode = head;
		while (currNode->next != NULL) {
			currNode = currNode->next;
		}
		currNode->next = newNode;
	}
}


// TODO: finish this function
/*
Function: LinkedList::getMaxValueHelper(Node *nodePtr, int largest)
Description: A helper function that recursively finds the maximum value in the linked list.
Input Parameters: Node *nodePtr - a pointer to the current node being checked
int largest - the current largest value found in the list
Returns: int - the maximum value in the list
*/
int LinkedList::getMaxValueHelper(Node *nodePtr, int largest) {	
	if(nodePtr == NULL){
    return largest;
  }
  if(nodePtr->value > largest){
    largest = nodePtr->value;
  }
  return getMaxValueHelper(nodePtr->next, largest);
}


// TODO: finish this function
/*
Function: LinkedList::getMaxValue()
Description: Finds the maximum value in the linked list.
Input Parameters: None
Returns: int - the maximum value in the list
*/
int LinkedList::getMaxValue() {
  Node * currNode = head;
	return getMaxValueHelper(currNode, -1);
}
