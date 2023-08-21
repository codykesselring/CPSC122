#include "DoublyLinkedQueue.h"

/*
Function: displayQueue()
Description: Displays the values of the Nodes in the DoublyLinkedQueue separated by spaces.
Input Parameters: None
Returns: None
*/
void DoublyLinkedQueue::displayQueue() {
	Node * currNode = head;
	
	while (currNode != NULL) {
		cout << currNode->value << " ";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << endl;
}

// TODO: finish this function
/*
Function: enqueue()
Description: Adds a new Node with the provided value to the end of the DoublyLinkedQueue.
Input Parameters: int newValue: Value to be added to the new Node
Returns: None
*/
void DoublyLinkedQueue::enqueue(int newValue) {
  addToEnd(newValue);
}

// TODO: finish this function
/*
Function: dequeue()
Description: Removes the first Node in the DoublyLinkedQueue and returns its value. If the queue is empty, returns 0.
Input Parameters: None
Returns: An integer value, representing the value of the removed Node or 0 if the queue is empty.
*/
int DoublyLinkedQueue::dequeue() {
	return deleteAtFront();
}

// TODO: finish this function
/*
Function: clear()
Description: Deallocates memory for each Node in the DoublyLinkedQueue and sets head and tail pointers to NULL.
Input Parameters: None
Returns: None
*/
void DoublyLinkedQueue::clear() {
  destroyList();
}

// TODO: finish this function
/*
Function: isEmpty()
Description: Checks if the DoublyLinkedQueue is empty.
Input Parameters: None
Returns: A boolean value, true if the queue is empty, false otherwise.
*/
bool DoublyLinkedQueue::isEmpty() {
  if(head!=NULL){
    return false;
  }
	return true; 
}

// TODO: finish this function
/*
Function: size()
Description: Returns the number of Nodes in the DoublyLinkedQueue.
Input Parameters: None
Returns: An integer value, representing the number of Nodes in the queue.
*/
int DoublyLinkedQueue::size() {
  Node * currNode = head;
	int count = 0;
	while (currNode != NULL) {
		currNode = currNode->next;
    count++;
	}
	return count;
}

// TODO: finish this function
/*
Function: removeDivisibleBy()
Description: Removes Nodes from the DoublyLinkedQueue if their values are divisible by the provided integer 'p'.
Input Parameters: int p: The integer value used to determine if a Node's value is divisible by it.
Returns: None
*/
void DoublyLinkedQueue::removeDivisibleBy(int p) {
  Node *currNode = head;
  int nodeVal;
  while (currNode != NULL) {
    if ((currNode->value) % p == 0) {
        nodeVal = currNode->value;
        Node *nextNode = currNode->next; // Save the next node before deleting the current one
        deleteNode(nodeVal);
        currNode = nextNode; // Update the current node
    } else {
        currNode = currNode->next;
    }
  }
}

