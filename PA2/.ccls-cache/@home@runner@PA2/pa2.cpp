#include "pa2funcs.h"

int main() {
  srand(time(0));
  ofstream insertionFile, bubbleFile, selectionFile;

  insertionFile.open("insertion_sort_results.csv");
  
  vector<int> vect1R,vect1A,vect1D;
  //vector<int> vect2R[1000],vect2A[1000],vect2D[1000];
  //vector<int> vect3R[5000],vect3A[5000],vect3D[5000];
  //vector<int> vect4R[10000],vect4A[10000],vect4D[10000];

  fillVectRandom(vect1R, 500);
  insertionSort(vect1R, 500);
  printVector(vect1R, insertionFile);
  
}
  