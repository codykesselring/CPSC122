#ifndef PA2FUNCS_H
#define PA2FUNCS_H

#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

void printVector(vector<int>, ofstream);
void swap(int &a, int &b);
void fillVectRandom(vector<int>&, int);
void fillSortedAscending(vector<int>&);
void fillSortedDescending(vector<int>&);
void insertionSort(vector<int>&, int);
void bubbleSort(vector<int>, int);
void selectionSortVector(vector<int>, int);

#endif