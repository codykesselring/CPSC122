#include "PA3.h"

////////////////////////////////////
// TASK 1
////////////////////////////////////
// TODO: finish the function and define/call three additional functions
/*
answerIntegerQuestions()
created 2/15/2023, modified 2/18/2023
Description: checks if the num is is divisible by 7,11, or 13, then it asks if the sum of the integers is even or odd, and lastly finds if the number is prime, declared as pointers so we don't have to return something for each.
returns 3 bools based on if they satisfy the questions or not
Pre: num and 3 bools which apply to each question being asked
Post: bools returned based on the num provided
*/
void answerIntegerQuestions(int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
	// call a function to answer the first Q
  int sum = 0, numCopy=num;
  
  if(num%7==0){
    cout << "Integer is divisible by 7" << endl; 
    *isMultiple = true;
  }else if(num%11==0){
    cout << "Integer is divisible by 11" << endl; 
    *isMultiple = true;
  }else if(num%13==0){
    cout << "Integer is divisible by 13" << endl; 
    *isMultiple = true;
  }else{
    cout << "Integer not a multiple of 7, 11, or 13" << endl;
    *isMultiple = false;
  }
	// call a function to answer the second Q
  while (numCopy != 0) {
    sum += numCopy % 10;
    numCopy /= 10; 
  }
  if(sum%2 == 0){
    cout << "Integer sum is even" << endl;
    *isSumEven = true;
  }else{
    cout << "Integer sum is odd" << endl; 
    *isSumEven = false;
  }
	// call a function to answer the third Q
  if(num<=1){
    *isPrime = false;
  }
  for(int i=2; i<num; i++){
    if(num%i==0){
      *isPrime=false;
      break;
    }else{
      *isPrime=true;
    }
  }
  if(*isPrime ==true){
    cout << "Integer is prime" << endl;
  }else{
    cout << "Integer is not prime" << endl;
  }
}

/*
runTask1()
created 2/15/2023, modified 2/18/2023
Description: opens the input file needed to grab the integers that are passed into the answerIntegerQuestion function
returns nothing
Pre: ifstream file with integers
Post: bool variables assigned a value
*/
void runTask1(ifstream& file){
  int num =0;
  string newLine;
  bool isMultiple, isSumEven, isPrime;
  file.open("../numbers.txt");
  if (file.is_open()) {
    cout << "Successfully opened input file" << endl;
  }else{
    cout << "not open" << endl;
  }
  while(!file.eof()){
    file >> num;
    cout << "Integer: " << num << endl;
    getline(file, newLine);
    answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
  }
  file.close();
}


////////////////////////////////////
// TASK 2
////////////////////////////////////
// TODO: finish the function
/*
findWinningLotteryTicket()
created 2/16/2023, modified 2/16/2023
Description: looks through the player's array and checks if their 5 digit number combination matches the winning ticket
returns true or false if they won or not
Pre: winning ticket number and array with players ticket combinations with array's length
Post: true or false if a combination in the player's array matches the winning ticket
*/
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers) {
  //linear search with pointer notation;
  for(int i=0; i<numPlayerNumbers; i++){
    if(*(playerNumbers+i) == winningTicketNum){
      cout << winningTicketNum << " is the winning ticket" << endl;
      return true;
    }
  }
	return false;
}

/*
runTask2()
created 2/16/2023, modified 2/16/2023
Description: declares the array and size, asks user for winning ticket number and passes the parameters into the findWinningLotteryTicket function
returns a cout statement regarding if they won or not
Pre: nothing
Post: tells the user if they won or not
*/
void runTask2(){
  int playerNums[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
  int playerNumsSize = 10;
  int winningNum = 0;
  bool winner = false;

  cout << "enter winning lottery number: ";
  cin >> winningNum;

  winner = findWinningLotteryTicket(winningNum, playerNums, playerNumsSize);
  if(winner){
    cout << "You won!" << endl;
  }else{
    cout << "You lost!" << endl;
  }
}

////////////////////////////////////
// TASK 3
////////////////////////////////////
// TODO: finish the functions and define additional functions
/*
runTask2()
created 2/16/2023, modified 2/21/2023
Description: fills an array with words from a text file in a specific part of speech
Returns a string array pointer
Pre: infstream file with words that match their part of speech and number of said words
Post: a filled array with words of a specific part of speech
*/
string * createWordsArray(ifstream& inFile, const int size) {
  string* arr = new string[size];
  string word, newline;
  
  for(int i=0; i<size; i++){
    inFile>>word;
    arr[i] = word;
  }
  
  insertionSort(arr, size);

	return arr;
}

/*
runTask2()
created 2/16/2023, modified 2/21/2023
Description: creates a random sentence based on the 4 parts of speech given to it with arrays and makes the sentence by daking random elements of each array and adding them into a string
Returns the sentence
Pre: sentence string with each part of speech's array and their sizes
Post: a complete sentence of random words
*/
void generateSentence(string * sentence,
		const string * articlesArr, const int articlesSize,
		const string * nounsArr, const int nounsSize,
		const string * verbsArr, const int verbsSize, 
		const string * prepsArr, const int prepsSize) {
  
  *sentence = articlesArr[(int)(rand() % (articlesSize))] + " " + nounsArr[(int)(rand() % (nounsSize))] + " " + verbsArr[(int)(rand() % (verbsSize))] + " " + prepsArr[(int)(rand() % (prepsSize))] + " " + articlesArr[(int)(rand() % (articlesSize))] + " " + nounsArr[(int)(rand() % (nounsSize))] + "!";
  (*sentence)[0] = toupper((*sentence)[0]);
  
}

/*
insertionSort()
created 2/20/2023, modified 2/20/2023
Description: works by dividing the input list into two parts: the sorted part, which is built up from left to right, and the unsorted part, which is everything to the right of the sorted part. Each iteration of the algorithm takes the next element from the unsorted part and inserts it into the correct position in the sorted part, until the entire list is sorted.
returns sorted array in alphabetical order
Pre: unsorted array of strings and array length
Post: sorted array of strings
*/
void insertionSort(string * arr, const int n) {
  int j;  
  string temp;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
} 

/*
runTask3()
created 2/16/2023, modified 2/21/2023
Description: initalizes each array for the parts of speech and looks through the ifstream text file which contains the associated part of speech with the amount of words associated with them, followed by the list of words. Once the curser has reached the word list the arrays are assigned the pointer that the createWordsArray function returns. Lastly it passes the arrays into the createSentence function for however many sentences are asked for it to make
Returns 10 random sentences and the word banks for each part of speech
Pre: ifstream file
Post: 10 random sentences 
*/
void runTask3(ifstream& inFile){
  string* articlesArr = nullptr;
  string* nounsArr = nullptr;
  string* verbsArr = nullptr;
  string* prepsArr = nullptr;
  int articlesSize, nounsSize, verbSize, prepsSize, sentenceCount;
  string article, newline, sentence="", partsOfSpeech;
  inFile.open("../input_words.txt");
  if (inFile.is_open()) {
    cout << "Successfully opened input file" << endl;
  }
  inFile >> sentenceCount;
  getline(inFile, newline);
  inFile >> article >> articlesSize;
  getline(inFile, newline);
  articlesArr = createWordsArray(inFile, articlesSize);
  
  getline(inFile, newline);
  inFile >> partsOfSpeech;
  cout << partsOfSpeech << endl;
  inFile >> nounsSize;
  getline(inFile, newline);
  nounsArr = createWordsArray(inFile, nounsSize);

  getline(inFile, newline);
  inFile >> partsOfSpeech;
  cout << partsOfSpeech << endl;
  inFile >> verbSize;
  getline(inFile, newline);
  verbsArr = createWordsArray(inFile, verbSize);

  getline(inFile, newline);
  inFile >> partsOfSpeech;
  cout << partsOfSpeech << endl;
  inFile >> prepsSize;
  getline(inFile, newline);
  prepsArr = createWordsArray(inFile, prepsSize);

  cout << "WORD BANK:" << "\nARTICLES: ";
  for(int i=0;i<articlesSize; i++){
    cout << articlesArr[i] << " ";
  }
  cout << "\nNOUNS:";
  for(int i=0;i<nounsSize; i++){
    cout << nounsArr[i] << " ";
  }
  cout << "\nVERBS:";
  for(int i=0;i<verbSize; i++){
    cout << verbsArr[i] << " ";
  }
  cout << "\nPREPOSITIONS:";
  for(int i=0;i<prepsSize; i++){
    cout << prepsArr[i] << " ";
  }
  
  cout << "\nGENERATED SENTENCES:" << endl;
  for(int i=0; i<sentenceCount; i++){
    generateSentence(&sentence, articlesArr, articlesSize, nounsArr, nounsSize, verbsArr, verbSize, prepsArr, prepsSize);
      cout << i+1 << ": "<< sentence << endl;
  }
  
  delete [] articlesArr;
  delete [] nounsArr;
  delete [] verbsArr;
  delete [] prepsArr;
  inFile.close();
}
