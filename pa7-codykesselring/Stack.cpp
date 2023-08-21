#include "Stack.h"

// TODO: finish this function
/*
Function: push
Description: Adds a new element to the top of the stack
Input Parameters: A string newValue
Returns: None
*/
void Stack::push(string newValue) {
  insertAtFront(newValue);
}

// TODO: finish this function
/*
Function: pop
Description: Removes and returns the top element from the stack
Input Parameters: None
Returns: The string value of the element removed from the top of the stack
*/
string Stack::pop() {
	return deleteAtFront(); // TODO: fix this
}

// TODO: finish this function
/*
Function: peek
Description: Returns the string value of the element at the top of the stack without removing it
Input Parameters: None
Returns: The string value of the element at the top of the stack, or an empty string if the stack is empty
*/
string Stack::peek() {
  if(head!=NULL){
    return head->value;
  }
  return "";
}

// TODO: finish this function
/*
Function: isEmpty
Description: Checks if the stack is empty
Input Parameters: None
Returns: A boolean value representing whether the stack is empty (true) or not (false)
*/
bool Stack::isEmpty() {
  if(head!=NULL){
    return false;
  }
	return true; // TODO: fix this
}
