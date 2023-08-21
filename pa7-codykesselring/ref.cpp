#include "Calculator.h"

void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

// TODO: finish this function
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
    //assigns the list of order of opportations and checks between the two operators that are passed into the function


    int operatorOnStack_precedence, currentOperator_precedence;

    // Set the precedence for operatorOnStack
    if (operatorOnStack == "+" || operatorOnStack == "-")
        operatorOnStack_precedence = 1;
    else if (operatorOnStack == "*" || operatorOnStack == "/" || operatorOnStack == "%")
        operatorOnStack_precedence = 2;
    else if (operatorOnStack == "^")
        operatorOnStack_precedence = 3;
    else
        operatorOnStack_precedence = 0;

    // Set the precedence for currentOperator
    if (currentOperator == "+" || currentOperator == "-")
        currentOperator_precedence = 1;
    else if (currentOperator == "*" || currentOperator == "/" || currentOperator == "%")
        currentOperator_precedence = 2;
    else if (currentOperator == "^")
        currentOperator_precedence = 3;
    else
        currentOperator_precedence = 0;

    return operatorOnStack_precedence >= currentOperator_precedence;
}

// TODO: finish this function
string Calculator::convertInfixToPostfix(string infix) {
    //takes in an infix
    // then it converts the infix to a postfix and returns that from the function
    string postfix = "";
    string token;

    for (int i = 0; i < infix.length(); i++) {
        token = infix.substr(i, 1);

        if (isalpha(token[0])) { // if the token is a letter
            // std::cout << "letter" << std::endl;
            postfix += token;
        }
        else if (token == "(") { // if the token is an opening parenthesis
            stack.push(token);
        }
        else if (token == ")") { // if the token is a closing parenthesis
            while (!stack.isEmpty() && stack.peek() != "(") {
                postfix += stack.peek() ;
                stack.pop();
            }
            stack.pop(); // remove the opening parenthesis
        }
        else { // if the token is an operator
            while (!stack.isEmpty() && stack.peek() != "(" && checkOperatorOnStackPrecedence(stack.peek(), token)) {
                postfix += stack.peek() ;
                stack.pop();
            }
            stack.push(token);
        }
    }

    // pop remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }

    return postfix;
}

// TODO: finish this function
string Calculator::evaluatePostfix(string postfix) {
    //takes in a postfix
    //evaluates the postfix changing the letters back to numbers and solving
    // returns the answer to the equation
    Stack operand;
    std::string preValue = "";
    std::string postValue = "";
    int operationCount = 0;

    for (long unsigned int i = 0; i < postfix.size(); i++) {
        int tableID = int(postfix[i]);
        std::stringif s = symbolTable[tableID];
        if (s == "NULL") {
            return "ERROR";
        }
        if (isalpha(postfix[i])) {
            operand.push(s);
        } else {
            std::string rightOperand = operand.pop();
            std::string leftOperand = operand.pop();
            std::string op = string(1, postfix[i]);
            operationCount++;
            std::string result = evaluateFormPart(leftOperand, rightOperand, op);


            if (result == "ERROR") {
                return "ERROR";
            }
            operand.push(result);
        }
    }
	return operand.pop(); 
}


#include "Calculator.h"


void Calculator::symbolTableChange(int indexNum, std::string Value){
    //takes a index place and a value
    //changes the index places value
    char val = indexNum;
    symbolTable[indexNum] = Value;
}

string Calculator::evaluateFormPart(string leftOperand, string rightOperand, string op) {
    // takes in two string numbers and a operator
    // evaluates the operator and solves the formulas
    //returns the answer to the equation
    if (leftOperand == "" || rightOperand == "" || leftOperand == "NULL" || rightOperand == "NULL") {
        return "ERROR";
    }
    long int left = stol(leftOperand);
    long int right = stol(rightOperand);
    long int result = 0;
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
    std::string returnedResult = to_string(result);
    return returnedResult;
}