/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2022
 Date: 4/20/2023                                                 
 Description: header file containing fuunction protypes to convert infix to postfix and evaluating them, contais a stack object and symbol table
*/
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include "Stack.h"
#include "PA7.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);
};

#endif