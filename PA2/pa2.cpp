#include "pa2funcs.h"

int main() {
  srand(time(0));
  ofstream insertionFile, bubbleFile, selectionFile;

  insertionFile.open("insertion_sort_results.csv");
  bubbleFile.open("bubble_sort_results.csv");
  selectionFile.open("selection_sort_results.csv");

  insertionFile << "Vector Configuration,Microseconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total"<<endl;
  bubbleFile << "Vector Configuration,Microseconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total"<<endl;
  selectionFile << "Vector Configuration,Microseconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total"<<endl;
  
  vector<int> vect1R,vect1A,vect1D;
  vector<int> vect2R,vect2A,vect2D;
  vector<int> vect3R,vect3A,vect3D;
  vector<int> vect4R,vect4A,vect4D;

  //bubble sort
  fillSortedAscending(vect1A, 500);
  bubbleFile << "Sorted ";
  bubbleSort(vect1A, 500, bubbleFile);
  fillSortedAscending(vect2A, 1000);
  bubbleFile << "Sorted ";
  bubbleSort(vect2A, 1000, bubbleFile);
  fillSortedAscending(vect3A, 5000);
  bubbleFile << "Sorted ";
  bubbleSort(vect3A, 5000, bubbleFile);
  fillSortedAscending(vect4A, 10000);
  bubbleFile << "Sorted ";
  bubbleSort(vect4A, 10000, bubbleFile);

  fillSortedDescending(vect1D, 500);
  bubbleFile << "Descending sorted ";
  bubbleSort(vect1D, 500, bubbleFile);
  fillSortedDescending(vect2D, 1000);
  bubbleFile << "Descending sorted ";
  bubbleSort(vect2D, 1000, bubbleFile);
  fillSortedDescending(vect3D, 5000);
  bubbleFile << "Descending sorted ";
  bubbleSort(vect3D, 5000, bubbleFile);
  fillSortedDescending(vect4D, 10000);
  bubbleFile << "Descending sorted ";
  bubbleSort(vect4D, 10000, bubbleFile);
  
  fillVectRandom(vect1R, 500);
  bubbleFile << "Random ";
  bubbleSort(vect1R, 500, bubbleFile);
  fillVectRandom(vect2R, 1000);
  bubbleFile << "Random ";
  bubbleSort(vect2R, 1000, bubbleFile);
  fillVectRandom(vect3R, 5000);
  bubbleFile << "Random ";
  bubbleSort(vect3R, 5000, bubbleFile);
  fillVectRandom(vect4R, 10000);
  bubbleFile << "Random ";
  bubbleSort(vect4R, 10000, bubbleFile);

  //selection sort
  selectionFile << "Sorted ";
  selectionSortVector(vect1A, 500, selectionFile);
  selectionFile << "Sorted ";
  selectionSortVector(vect2A, 1000, selectionFile);
  selectionFile << "Sorted ";
  selectionSortVector(vect3A, 5000, selectionFile);
  selectionFile << "Sorted ";
  selectionSortVector(vect4A, 10000, selectionFile);
 
  selectionFile << "Descending sorted ";
  selectionSortVector(vect1A, 500, selectionFile);
  selectionFile << "Descending sorted ";
  selectionSortVector(vect2A, 1000, selectionFile);
  selectionFile << "Descending sorted ";
  selectionSortVector(vect3A, 5000, selectionFile);
  selectionFile << "Descending sorted ";
  selectionSortVector(vect4A, 10000, selectionFile);
  
  selectionFile << "Random ";
  selectionSortVector(vect1A, 500, selectionFile);
  selectionFile << "Random ";
  selectionSortVector(vect2A, 1000, selectionFile);
  selectionFile << "Random ";
  selectionSortVector(vect3A, 5000, selectionFile);
  selectionFile << "Random ";
  selectionSortVector(vect4A, 10000, selectionFile);

  //insertion sort
  insertionFile << "Sorted ";
  insertionSort(vect1A, 500, insertionFile);
  insertionFile << "Sorted ";
  insertionSort(vect2A, 1000, insertionFile);
  insertionFile << "Sorted ";
  insertionSort(vect3A, 5000, insertionFile);
  insertionFile << "Sorted ";
  insertionSort(vect4A, 10000, insertionFile);
  
  insertionFile << "Descending sorted ";
  insertionSort(vect1D, 500, insertionFile);
  insertionFile << "Descending sorted ";
  insertionSort(vect2D, 1000, insertionFile);
  insertionFile << "Descending sorted ";
  insertionSort(vect3D, 5000, insertionFile);
  insertionFile << "Descending sorted ";
  insertionSort(vect4D, 10000, insertionFile);

  insertionFile << "Random ";
  insertionSort(vect1R, 500, insertionFile);
  insertionFile << "Random ";
  insertionSort(vect2R, 1000, insertionFile);
  insertionFile << "Random ";
  insertionSort(vect3R, 5000, insertionFile);
  insertionFile << "Random ";
  insertionSort(vect4R, 10000, insertionFile);
 
}
  