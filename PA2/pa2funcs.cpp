#include "pa2funcs.h"

void selectionSortVector(vector<int> vect, int size, ofstream &file){
    auto start = high_resolution_clock::now();
  long dataComparisons=0, loopControlComparisons=0, dataAssignments=0, loopControlAssignments=0, other=0;
  
  int minIndex, minValue;
  bool sorted = false;
  other++;
  loopControlAssignments++;
  for(int start = 0; start<size-1 && !sorted; start++){
    loopControlComparisons++;
    loopControlAssignments++;
    minIndex=start;
    minValue=vect[start];
    dataAssignments+=2;
    loopControlAssignments++;
    for(int index=start+1; index<size; index++){
      loopControlComparisons++;
      loopControlAssignments++;
      dataComparisons++;
      if(vect[index]<minValue){
        minValue=vect[index];
        minIndex=index;
        sorted = false;
        dataAssignments+=2;
      }
    }
    loopControlComparisons++;

    int temp = vect[minIndex];
    vect[minIndex] = vect[start];
    vect[start] = temp;
    dataAssignments+=3;

    loopControlComparisons++;
    if (minIndex == start) sorted = true;
  }
  loopControlComparisons++;   

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "N=" << size <<"," << duration.count() << "," << dataComparisons << "," << loopControlComparisons << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << dataComparisons+loopControlComparisons+dataAssignments+loopControlAssignments+other<< endl;
  
  /*auto start = high_resolution_clock::now();
  long dataComparisons=0, loopControlComparisons=0, dataAssignments=0, loopControlAssignments=0, other=0;
  
  int minIndex, minValue;
  other +=2; //for initialization
  
  loopControlAssignments++; //for int start=0
  for(int start = 0; start<size-1; start++){
    loopControlComparisons++; // for boolean condition evaluates to true
    loopControlAssignments++; //for start++
    minIndex=start;
    other++; //for minIndex assignment
    minValue=vect[start];
    dataAssignments++; //for minVal assignment

    loopControlAssignments++; //index assignment
    for(int index=start+1; index<size; index++){
      loopControlComparisons++;//boolean condition evaluates to true
      loopControlAssignments++; //for index++
      dataComparisons++;
      if(vect[index]<minValue){
        minValue=vect[index];
        dataAssignments++;//for minVal assignment
        minIndex=index;
        other++; // for minIndex assignment
      }
    }
    loopControlComparisons++; // for inner for loop boolean eval to false
    swap(vect[minIndex], vect[start]);
    dataAssignments+=3; // for swap
  }
  loopControlComparisons++; // for boolean condition eval to false
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "N=" << size <<"," << duration.count() << "," << dataComparisons << "," << loopControlComparisons << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << dataComparisons+loopControlComparisons+dataAssignments+loopControlAssignments+other<< endl;*/
}




void bubbleSort(vector<int> vect, int size, ofstream &file){
  auto start = high_resolution_clock::now();
	long dataComparisons=0, loopControlComparisons=0, dataAssignments=0, loopControlAssignments=0, other=0;
  
  bool sorted = false;
  loopControlAssignments++;
  loopControlComparisons++;
  while (!sorted){
    sorted = true;
    loopControlAssignments+=2;//for sorted being true and int i
    for (int i = 0; i < size - 1; ++i){
      loopControlComparisons++;
      loopControlAssignments++;
      dataComparisons++;
      if (vect[i] > vect[i + 1]) {
        swap(vect[i], vect[i + 1]);
        dataAssignments+=3;
        sorted = false;
        loopControlAssignments++;
      }
    }
    loopControlComparisons++;
  }
  loopControlComparisons++;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "N=" << size <<"," << duration.count() << "," << dataComparisons << "," << loopControlComparisons << "," << dataAssignments << "A," << loopControlAssignments << "," << other << "," << dataComparisons+loopControlComparisons+dataAssignments+loopControlAssignments+other<< endl;
}

void insertionSort(vector<int> vect, int size, ofstream &file) {
  auto start = high_resolution_clock::now();
	long dataComparisons=0, loopControlComparisons=0, dataAssignments=0, loopControlAssignments=0, other=0;
  int currValue;
  other++;

  loopControlAssignments++;
	for (int i = 1; i < size; i++) {
    loopControlComparisons++;
    loopControlAssignments++;
    
		currValue = vect[i];
    dataAssignments++;
		int j = i - 1;
    other++;
    loopControlComparisons++;
		while (j >= 0 && currValue < vect[j]) {
      loopControlComparisons++;
			vect[j + 1] = vect[j];
			j--;
      dataAssignments++;
      loopControlAssignments++;
		}
    loopControlComparisons++;
		vect[j + 1] = currValue;
    dataAssignments++;
	}
  loopControlComparisons++;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count()<<endl;
  file << "N=" << size <<"," << duration.count() << "," << dataComparisons << "," << loopControlComparisons << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << dataComparisons+loopControlComparisons+dataAssignments+loopControlAssignments+other<< endl;
}

void fillVectRandom(vector<int> &vect, int size){
  for(int i=0; i<size; i++){
    vect.push_back((int)(rand() % (9999+1)));
  }
}

void fillSortedAscending(vector<int> &vect, int size){
  int num=1;
  for(int i=0; i<size; i++){
    vect.push_back(num);
    num++;
  }
}

void fillSortedDescending(vector<int> &vect, int size){
  int num=size;
  for(int i=0; i<size; i++){
    vect.push_back(num);
    num--;
  }
}

void swap(int &a, int &b){
  int temp=a;
  a=b;
  b=temp;
}

