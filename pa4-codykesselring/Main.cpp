/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2022
 Date: 3/9/2023
 Programming Assignment: PA4                                                                     
 Description: This program reads information about the inventory of a package delivery truck from an input file that is provided to the program via command line arguments. It reads from the file the driver name, id, weight, width, length, and height for each package and displays and makes computations on them.
*/
#include "PA4.h"

// TODO: add parameters to main() for command line args
int main(int argc, char* argv[]) {
	// TODO: your code here
  int numPackages, heaviestId;
  double heaviestWeight, avgWeight = 0;
  string driverName;
  string newLine = "";
  
  ifstream file(argv[1]);
  if (argc < 2) {
    cout << "Please provide the filename via command line arguments." << endl;
    return 1;
  }

  
  if (!file.is_open()) {
    cout << "not open" << endl;
  }
  
  Package* myPackage = NULL;

  myPackage = loadPackages(file, &driverName, &numPackages);
  computePackageStats(myPackage, numPackages, &heaviestId, &heaviestWeight, &avgWeight);
  
  cout << "Package information\n" << "------------" << endl;
  cout << "Number of packages in " << driverName << "s truck: " << numPackages << endl << endl;
  for(int i=0; i<numPackages; i++){
    cout << "Package ID: " << myPackage[i].id << endl;
    cout << "Package Weight: " << myPackage[i].weight << endl;
    cout << "Package Width: " << myPackage[i].width << endl;
    cout << "Package Length: " << myPackage[i].length << endl;
    cout << "Package Height: " << myPackage[i].height << endl << endl;
  }

  cout << "Package stats\n" << "------------" << endl;
  cout << "ID of heaviest package: " << heaviestId << endl;
  cout << "Weight of heaviest package: " << heaviestWeight << endl;
  cout << "Average weight of packages on truck: " << avgWeight << endl << endl;
  
  file.close();
  delete[] myPackage;

  return 0;
}
