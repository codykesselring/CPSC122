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

void swap(int &a, int &b);
void fillVectRandom(vector<int>&, int);
void fillSortedAscending(vector<int>&, int);
void fillSortedDescending(vector<int>&, int);
void insertionSort(vector<int>, int, ofstream&);
void bubbleSort(vector<int>, int, ofstream&);
void selectionSortVector(vector<int>, int, ofstream&);

#endif