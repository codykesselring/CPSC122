/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2023
Date: 5/2/2023
Description: header file with all prototypes for running tasks 1-5 along with their helper functions
*/
#ifndef PA9_H
#define PA9_H

#include <iostream>
#include <vector>

// for task 4
#include "LinkedList.h"

using namespace std;

// TODO: add your additional PA9.cpp function prototypes in the appropriate spot below

// task 1 prototypes
int countDigits(string);
int countDigitsHelper(string, int, int);
void runTask1();

// task 2 prototypes
int sumDigits(int);
void runTask2();

// task 3 prototypes
bool isPalindrome(string);
bool isPalindromeHelper(string s);
void runTask3();

// task 4 prototypes
void runTask4();

// task 5 prototypes
void generateSubstrings(string, vector<string>&);
void runTask5();
void substringHelper(string s, vector<string>& substrings);

// BONUS ONLY struct definition and prototypes
struct Coordinates {
	int row;
	int col;
};
bool traverseMaze(char[8][8], Coordinates[], int *, int, int);
void displayMaze(char[8][8]);
void runBONUSTask();

#endif
