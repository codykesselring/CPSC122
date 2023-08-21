#ifndef PA3_H
#define PA3_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;

// task 1
void answerIntegerQuestions(const int num, bool *, bool *, bool *);
// TODO: add your additional function prototypes for task 1 here
void runTask1(ifstream&);

// task 2
bool findWinningLotteryTicket(int, const int *, const int);
// TODO: add your additional function prototypes for task 2 here
void runTask2();

// task 3
string * createWordsArray(ifstream&, const int);
void generateSentence(string *, const string *, const int, const string *, const int, const string *, const int, const string *, const int);
// TODO: add your additional function prototypes for task 3 here
void runTask3(ifstream&);
void insertionSort(string *, const int);

#endif
