#include "Calculator.h"
/*
Function: setSymbolTable(string newSymbolTable[])
Description: Takes an array of strings newSymbolTable and sets the symbol table of the Calculator object to match it
Input Parameters: An array of strings newSymbolTable
Returns: Nothing
*/
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

// TODO: finish this function
/*
Function: checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator)
Description: Takes two strings, operatorOnStack and currentOperator, and returns a boolean indicating whether the operator on the stack has higher or equal precedence to the current operator
Input Parameters: Two strings operatorOnStack and currentOperator
Returns: A boolean indicating whether the operator on the stack has higher or equal precedence to the current operator
*/
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
  int precedenceOnStack = 0;
  int precedenceCurrent = 0;
  
  if(operatorOnStack == "("){
    precedenceCurrent = 4;
  } else if (operatorOnStack == "^") {
    precedenceOnStack = 3;
  } else if (operatorOnStack == "*" || operatorOnStack == "/" || operatorOnStack == "%") {
    precedenceOnStack = 2;
  } else if (operatorOnStack == "+" || operatorOnStack == "-") {
    precedenceOnStack = 1;
  }

  if(currentOperator == "("){
    precedenceCurrent = 4;
  } else if (currentOperator == "^") {
    precedenceCurrent = 3;
  } else if (currentOperator == "*" || currentOperator == "/" || currentOperator == "%") {
    precedenceCurrent = 2;
  } else if (currentOperator == "+" || currentOperator == "-") {
    precedenceCurrent = 1;
  }
  if(currentOperator == "^" && operatorOnStack== "^"){
    return false;
  }

  // Compare the precedence values
  return precedenceOnStack >= precedenceCurrent;
}

// TODO: finish this function
/*
Function: convertInfixToPostfix(string infix)
Description: Takes a string infix and converts it to postfix notation using a stack of strings
Input Parameters: A string infix
Returns: A string containing the postfix equivalent of the input infix expression
*/
string Calculator::convertInfixToPostfix(string infix) {
  Stack s;
  string postfix = "";
  for (int i = 0; i < infix.length(); i++) {
    string c = string(1, infix[i]);
    if(!isOperator(c) && c != ")"){
      postfix+=c;
    }
    else if(c==")"){
      while(!s.isEmpty() && s.peek() != "("){
        postfix+=s.pop();
      }
      if (!s.isEmpty() && s.peek() == "(") {
        s.pop();
      }
    }
    else{
      while(!s.isEmpty() && s.peek() != "(" && checkOperatorOnStackPrecedence(s.peek(), c)){
        postfix+=s.pop();
      }
      s.push(c);
    }
  }
  while (!s.isEmpty()) {
    postfix += s.pop();
  }
  cout << "Postfix Equivalent: " << postfix << endl;
  return postfix;
}

// TODO: finish this function
/*
Function: evaluatePostfix(string postfix)
Description: Takes a string postfix and evaluates it as a postfix expression using the stack of strings and taking values from the symbol table to assign to the operands
Input Parameters: A string postfix
Returns: A string containing the result of the evaluation, or "ERROR" if an error occurs during the evaluation
*/
string Calculator::evaluatePostfix(string postfix) {
  Stack operand;
  int opCount = 0;
  for(int i=0; i<postfix.size(); i++){
    string c = symbolTable[i];
    
    if (c == "NULL") {
      return "ERROR";
    }
    else if(isLetter(postfix[i])){
      int tableIndex = int(postfix[i]);;
      string symbol = symbolTable[tableIndex];
      operand.push(symbol);
    }
    else{
      string op1 = operand.pop();
      string op2 = operand.pop();
      string op = string(1, postfix[i]);
      string resultString;
      opCount++;

      if (op1 == "" || op2 == "" || op1 == "NULL" || op2 == "NULL") {
        return "ERROR";
      }
      long int right = stol(op1);
      long int left = stol(op2);
      long result = 0;
      if (op == "+") {
        result = left+right;
      } else if (op == "-") {
        result = left-right;
      } else if (op == "*") {
        result = left*right;
      } else if (op == "/") {
        if (right == 0) {
          return "ERROR";
        }
        result = left/right;
      } else if (op == "^") {
        if (right < 0) {
          return "ERROR";
        }
        result = pow(left,right);
      } else if (op == "%") {
        if (right <= 0) {
            return "ERROR";
        }
        result = left%right;
      } else {
        cout << "Unrecognized operator: " << op << endl;
      }
      string returnedResult = to_string(result);
      operand.push(returnedResult);
    }
  }
  cout << "Postfix result: " << operand.peek() << endl << endl;
	return operand.pop();
}