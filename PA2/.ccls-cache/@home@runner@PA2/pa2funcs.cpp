#include "pa2funcs.h"

void selectionSortVector(vector<int> vect, int size){
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
}

void bubbleSort(vector<int> vect, int size){
  long dataComparisons=0, loopControlComparisons=0, dataAssignments=0, loopControlAssignments=0, other=0;
  
  bool swap;
  int temp;
  other+=2;
  
  do{
    swap = false;
    other++;
    loopControlAssignments++;
    for(int i=0; i<size-1; i++){
      loopControlComparisons++;//boolean condition evaluates to true
      loopControlAssignments++; //for i++
      
      temp = vect[i];
      vect[i] = vect[i+1];
      vect[i+1] = temp;
      dataAssignments+=3;
      swap = true;
      other++;
    }
    loopControlAssignments++;
    loopControlComparisons++;
  }while(swap);
  loopControlAssignments++;
}

void insertionSort(vector<int> &vect, int size) {
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

}

void fillVectRandom(vector<int> &vect, int size){
  for(int i=0; size; i++){
    vect.push_back((int)(rand() % (9999+1));
    }
}

void fillSortedAscending(vector<int> &vect){
  int num=1;
  for(int i=0; i<vect.size(); i++){
    vect[i] = num;
    num++;
  }
}

void fillSortedDescending(vector<int> &vect){
  int num = vect.size();
  for(int i=0; i<vect.size(); i++){
    vect[i]=num;
    num--;
  }
}


//in class
void swap(int &a, int &b){
  int temp=a;
  a=b;
  b=temp;
}

void printVector(vector<int> vect, ofstream file){
  for(int i=0; i<vect.size(); i++){
    file << vect[i];
  }
}
