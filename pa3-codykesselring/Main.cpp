/* 
Cody Kesselrin
2/21/2023
CPSC122
PA3
performs 3 tasks; task 1 takes an integer from a text file and answers if the number is divisible by 7,11, or 13, then it asks if the sum of the integers is even or odd, and lastly finds if the number is prime. Task 2 looks through an array in to see if a buyer has won the lottery or not by matching their 5 digit combinations with the winning number. Task 3 creates random sentences by searching through a text file with articles, nouns, verbs, and prepositions that each have a certain number of words within them; with these words we make an array with each of the parts of speech and takes random elements of the array to form a sentence.
*/
#include "PA3.h"

int main() {
	srand(time(0)); // this should be the ONLY call to srand() in PA3
  ifstream textFile;
  ifstream task3File;
  string words;
  srand(time(0));
	
	// TODO: your task 1 code here
	runTask1(textFile);
	// TODO: your task 2 code here
	runTask2();
	// TODO: your task 3 code here
  runTask3(task3File);
  
	return 0;
}