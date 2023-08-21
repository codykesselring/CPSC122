#include "PA4.h"
/*
loadPackages()
created 3/2/2023, modified 2/9/2023
Description: reads the id, weight, width, length, and height of each package in the text file and stores their values in their respecive struct
returns a filled struct array pointer of filled package structs
Pre: input file, variable for the drivers name and the number of packages
Post: filled struct array with id, weight, width, length, and height stored in the structs
*/
// TODO: finish the functions and define/call additional functions
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
  string newLine = "";
  int lines;
  lines = lineCount(inFile);
  *numPackages = (lines-2)/6; // -2 because top two lines are unnecessary in the struct array, divide by 6 because each package contains 6 lines
  
  Package *p = new Package[*numPackages];
  
  getline(inFile, *driverName);
  getline(inFile, newLine);
  
  for (int i = 0; i < *numPackages; i++) {
    getline(inFile, newLine);
    p[i].id = stoi(newLine);
  
    getline(inFile, newLine);
    p[i].weight = stod(newLine);
  
    getline(inFile, newLine);
    p[i].width = stoi(newLine);
  
    getline(inFile, newLine);
    p[i].length = stoi(newLine);
  
    getline(inFile, newLine);
    p[i].height = stoi(newLine);
    getline(inFile, newLine);
  }
  return p;
}

/*
computePackageStats()
created 3/5/2023, modified 2/9/2023
Description: reads through a struct array, checking the weight of each package and storing the largest weight and finds the average weight of all the packages
returns the heaviest weight, heaviest id, and average weight through pointers
Pre: filled stuct array, number of packages in the array, and the initialized variables for heaviest weight, id, and average weight.
Post: largest weight, id, and average weight found
*/
void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
  *heaviestId = packages[0].id;
  *heaviestWeight = packages[0].weight;
  *avgWeight = 0;
  
  for(int i=0; i<numPackages; i++){
    if(*heaviestWeight < packages[i].weight){
      *heaviestWeight = packages[i].weight;
      *heaviestId = packages[i].id;
    }
  }
  for(int i=0; i<numPackages; i++){
    *avgWeight += packages[i].weight;
  }
  *avgWeight = (*avgWeight/numPackages);
}

/*
lineCount()
created 3/2/2023, modified 2/9/2023
Description: reads each line of a text file to see how many lines are in it
returns the total number of lines in the text file
Pre: input text file
Post: number of lines acquired
*/
int lineCount(ifstream& inFile){
  int count=0;
  string newLine;
  while(!inFile.eof()){
    getline(inFile, newLine);
    count++;
  }
  inFile.clear();
  inFile.seekg (0, ios::beg);
  return count;
}

