#include "PA7.h"
#include "Calculator.h"
/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2022
 Date: 4/20/2023
 Programming Assignment: PA7                                                           
 Description: This program reads from an input file with values assigned to different letters and assigns the value to the letters ascii value index in an array. It then grabs infix equations from the file and passes them into functions that convert it to post fix and evaluates the result
*/
int main() {
	// TODO: your code here
  ifstream inFile;
  inFile.open("../input.txt");
  if (!inFile) {
      cerr << "Error: Unable to read input file." << endl;
      return -1;
  }
  
  Calculator calc;
  string symbolTable['Z'+1];
  string *equationTable = new string[1000];
  string equation;
  string value;
  char letter;
  int count = 0;
  
  while(inFile >> letter >> value){
    if(letter == '#'){
      break;
    }
    symbolTable[letter] = value;
	  calc.setSymbolTable(symbolTable);
  }
  
  while(inFile >> equation){
    if(equation == "#"){
      break;
    }
    cout << "Infix Expression: " << equation << endl;
    equationTable[count] = calc.convertInfixToPostfix(equation);
    calc.evaluatePostfix(equationTable[count]);
    count++;
  }
  
	
	return 0;
}
