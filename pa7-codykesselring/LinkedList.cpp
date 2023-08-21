#include "LinkedList.h"
/*
Function: LinkedList()
Description: Constructor for the LinkedList class that initializes the head pointer to NULL
Input Parameters: None
Returns: None
*/
LinkedList::LinkedList() {
	head = NULL;
}

/*
Function: ~LinkedList()
Description: Destructor for the LinkedList class that frees each Node's memory in the list by calling the destroyList() function
Input Parameters: None
Returns: None
*/
LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

/*
Function: destroyList()
Description: Traverses the linked list and deletes each Node to free up memory. Sets the head pointer to NULL for good practice.
Input Parameters: None
Returns: None
*/
void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

/*
Function: displayList()
Description: Traverses the linked list and prints out each Node's value in order, starting from the head node.
Input Parameters: None
Returns: None
*/
void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

// TODO: finish this function
/*
Function: insertAtFront(string newValue)
Description: Inserts a new Node at the front of the linked list with the specified value.
Input Parameters: A string newValue, representing the value of the new Node to be inserted
Returns: None
*/
void LinkedList::insertAtFront(string newValue) {
  Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	
	// 2 cases
	if (head == NULL) {
		head = newNode;
	} 
	else {
		// list is not empty
		newNode->next = head;
		head = newNode;
	}
}

// TODO: finish this function
/*
Function: deleteAtFront()
Description: Deletes the first Node in the linked list and returns its value. If the list is empty, returns -1.
Input Parameters: None
Returns: A string value, representing the value of the deleted Node or -1 if the list is empty.
*/
string LinkedList::deleteAtFront() {
	// check to make sure there is something to delete
  string deletion = "-1";
	if (head != NULL) {
		Node * nodeToDelete = head;
    deletion=nodeToDelete->value;
		head = head->next;
		delete nodeToDelete;
	}
	return deletion; // TODO: fix this
}


