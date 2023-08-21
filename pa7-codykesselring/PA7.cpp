#include "PA7.h"

// TODO: your helper functions here
/*
Function: isOperator(string c)
Description: Checks if a given string is an arithmetic operator or a parenthesis
Input Parameters: A string c
Returns: True if the input string is an arithmetic operator or a parenthesis, False otherwise
*/
bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^" || c == "(" || c == "%");
}
/*
Function: isLetter(char c)
Description: Checks if a given character is an uppercase letter
Input Parameters: A character c
Returns: True if the input character is an uppercase letter, False otherwise
*/
bool isLetter(char c) {
    // check if the character is a letter
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}