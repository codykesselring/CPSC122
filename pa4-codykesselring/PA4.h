#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
// TODO: add your additional function prototypes here
int lineCount(ifstream&);

//EXTRA CREDIT
/*const int numLetters = 52; // There are 26 uppercase and 26 lowercase letters

struct LetterOccurrence {
    int count;
    double frequency;
};
void extraCreditPrint(LetterOccurrence);*/


#endif
