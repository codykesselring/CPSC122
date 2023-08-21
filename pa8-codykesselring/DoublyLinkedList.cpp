#include "DoublyLinkedList.h"

/*
Function: DoublyLinkedList()
Description: Constructor for the DoublyLinkedList class. Initializes head and tail pointers to NULL.
Input Parameters: None
Returns: None
*/
DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

/*
Function: ~DoublyLinkedList()
Description: Destructor for the DoublyLinkedList class. Frees the memory allocated for each Node in the list.
Input Parameters: None
Returns: None
*/
DoublyLinkedList::~DoublyLinkedList() {
	// free each Node's memory in the list
	destroyList();
}

/*
Function: getHead()
Description: Getter function that returns a pointer to the head Node of the linked list.
Input Parameters: None
Returns: Pointer to the head Node of the list.
*/
Node * DoublyLinkedList::getHead() const {
	return head;
}

/*
Function: getTail()
Description: Getter function that returns a pointer to the tail Node of the linked list.
Input Parameters: None
Returns: Pointer to the tail Node of the list.
*/
Node * DoublyLinkedList::getTail() const {
	return tail;
}

/*
Function: setHeadAndTail()
Description: Sets head and tail pointers to the provided new head and new tail pointers. If head is not NULL, it destroys the current list.
Input Parameters:
- Node * newHead: Pointer to the new head Node
- Node * newTail: Pointer to the new tail Node
Returns: None
*/
void DoublyLinkedList::setHeadAndTail(Node * newHead, Node * newTail) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
	tail = newTail;
}

/*
Function: destroyList()
Description: Deallocates memory for each Node in the list and sets head and tail pointers to NULL.
Input Parameters: None
Returns: None
*/
void DoublyLinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

/*
Function: displayList()
Description: Displays the linked list in the format "head->value<->value<->...->NULL". Also displays the value of the tail Node.
Input Parameters: None
Returns: None
*/
void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
	if (tail != NULL) {
		cout << "tail->" << tail->value << endl;
	}
	else {
		cout << "tail->NULL" << endl;
	}
}

// TODO: finish this function
/*
Function: addToEnd()
Description: Adds a new Node with the provided value to the end of the linked list.
Input Parameters:
- int newValue: Value to be added to the new Node
Returns: None
*/
void DoublyLinkedList::addToEnd(int newValue) {
	// make a new Node
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
  newNode->prev = NULL;
	
	// 2 cases
	if (head == NULL) {
		head = newNode;
    tail = newNode;
	} 
	else {
		// list is not empty
		// tail points to the last node in the list
    tail->next = newNode;
		newNode->prev = tail;
    tail = newNode;
	}
}

// TODO: finish this function
/*
Function: deleteAtFront()
Description: Deletes the first Node in the linked list and returns its value. If the list is empty, returns 0.
Input Parameters: None
Returns: An integer value, representing the value of the deleted Node or 0 if the list is empty.
*/
int DoublyLinkedList::deleteAtFront() {
  int deletion = 0;
  // check to make sure there is something to delete
	if (head != NULL) {
		Node * nodeToDelete = head;
		head = head->next;
    if(head!=NULL){//checks if list is empty
      head->prev=NULL;
    }
    else{ //if list is empty
      tail = NULL;
    }
    deletion = nodeToDelete->value;
		delete nodeToDelete;
	}
  return deletion;
}

// TODO: finish this function
/*
Function: deleteNode()
Description: Deletes the Node with the target value in the linked list and returns the target value. If the target value is not found, returns -1.
Input Parameters:
- int targetValue: Value of the Node to be deleted
Returns: An integer value, representing the value of the deleted Node or -1 if the target value is not found in the list.
*/
int DoublyLinkedList::deleteNode(int targetValue) {
  int deletion = 0;
  // check case 1
	if (head != NULL) {
		// list is not empty
		// need to traverse list, stopping at the last node
		Node * currNode = head;
		// check case 2... the node to delete is the first node
		if (head->value == targetValue)  {
			head = head->next;
      if(head!=NULL){
        head->prev = NULL;
      }
      else{
        tail = NULL;
      }
      deletion = currNode->value;
			delete currNode;
		}
		else { // case 3... the node to delete is not the first node, but might not even be in the list
			while (currNode != NULL && currNode->value != targetValue) {
				currNode = currNode->next;
			}
			// check if we found targetValue
			if (currNode != NULL) {
				// did find it
				currNode->prev->next = currNode->next; //curNodes prev points to curNodes next bc we delete curNode
				if(currNode->next!=NULL){//is node we're deleting at end
          currNode->next->prev = currNode->prev;
        }
        else{//currNode is the last node in the list
          tail = currNode->prev;
        }
        deletion = currNode->value;
        delete currNode;
			}
		}
	}
  if (deletion == 0) {
    return -1; // targetValue was not found in the list
  }
  return deletion;
}

// TODO: BONUS ONLY finish this function
void DoublyLinkedList::addToFront(int newValue) {

}

// TODO: BONUS ONLY finish this function
int DoublyLinkedList::deleteAtEnd() {
  return -1;
}

// TODO: BONUS ONLY finish this function
void DoublyLinkedList::insertInOrder(int newValue) {
  
}
