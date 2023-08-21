/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2023
Date: 5/2/2023
Description: declares the definition for each recursive task, including finding the sum of digits, number of digits, seeing if a string is a palindrome, finding the max value in a list, and finding all substrings of a string
*/
#include "PA9.h"

// TODO: finish this function
/*
Function: countDigits(string s)
Description: Counts the number of digits in the given string by calling the helper function.
Input Parameters: string s - the input string to count digits from
Returns: int - the number of digits in the given string
*/
int countDigits(string s) {
  return countDigitsHelper(s, 0, 0); // TODO: fix this
}

// TODO: finish this function by testing countDigits()
/*
Function: runTask1()
Description: Prompts the user for an input string and calls countDigits() to count the number of digits in the string. Outputs the result.
Input Parameters: None
Returns: None
*/
void runTask1() {
  string s;
  int count;
  cout << "enter string with digits to find number of digits in the string: " << endl;
  getline(cin, s);
  count = countDigits(s);
  cout << count << " digits in string" << endl;
}

/*
Function: countDigitsHelper(string s, int count, int index)
Description: A helper function that recursively counts the number of digits in the input string.
Input Parameters: string s - the input string to count digits from
  int count - the current count of digits
  int index - the current index in the string
Returns: int - the number of digits in the input string
*/
int countDigitsHelper(string s, int count, int index){
    if (index >= s.length()) {
        return count;
    }
    if (s[index] >= '0' && s[index] <= '9') {
        return countDigitsHelper(s, count + 1, index + 1);
    }
  return countDigitsHelper(s, count, index+1);
}

// TODO: finish this function
/*
Function: sumDigits(int num)
Description: Calculates the sum of digits in the given integer recursively.
Input Parameters: int num - the input integer to calculate the sum of digits
Returns: int - the sum of the digits in the input integer
*/
int sumDigits(int num) {
  if(num == 0){
    return num;
  }
  return (num%10)+sumDigits(num/10);// TODO: fix this
}

// TODO: finish this function by testing sumDigits()
/*
Function: runTask2()
Description: Prompts the user for an input integer and calls sumDigits() to calculate the sum of the digits. Outputs the result.
Input Parameters: None
Returns: None
*/
void runTask2() {
  int num, sum;
  string numString;
  cout << "enter integer to find sum of digits:" << endl;
  getline(cin, numString);
  num = stoi(numString);
  sum = sumDigits(num);
  cout << "the sum is " << sum << endl;
}

// TODO: finish this function
/*
Function: isPalindrome(string s)
Description: Checks if the given string is a palindrome, ignoring spaces.
Input Parameters: string s - the input string to check for palindrome
Returns: bool - true if the input string is a palindrome, false otherwise
*/
bool isPalindrome(string s) {
  string noSpaces;
  for(int i=0; i<s.length(); i++){
    if(s[i]!=' '){
      noSpaces+=s[i];
    }
  }
  return isPalindromeHelper(noSpaces);
}

/*
Function: isPalindromeHelper(string s)
Description: A helper function that recursively checks if the input string is a palindrome.
Input Parameters: string s - the input string to check for palindrome
Returns: bool - true if the input string is a palindrome, false otherwise
*/
bool isPalindromeHelper(string s){
  if(s.length() == 1 || s.length() == 0){
    return true;
  }
  if(s[0] == ' '){
    return isPalindrome(s.substr(1, s.length() - 1));
  }
  if(s[s.length()-1] == ' '){
    return isPalindrome(s.substr(0, s.length() - 2));
  }
  if(s[0] == s[s.length()-1]){
    return isPalindrome(s.substr(1, s.length() - 2));
  }
	return false; 
}

// TODO: finish this function by testing isPalindrome()
/*
Function: runTask3()
Description: Prompts the user for an input string and calls isPalindrome() to check if the string is a palindrome. Outputs the result.
Input Parameters: None
Returns: None
*/
void runTask3() {
  string s;
  bool palindrome;
  cout << "enter string to find if palindrome: " << endl;
  getline(cin, s);
  palindrome = isPalindrome(s);
  if(palindrome == true){
    cout << "the string is a palindrome " << endl;
  }
  else{
    cout << "the string is not a palindrome" << endl;
  }

}

// TODO: finish this function by testing getMaxValue() and getMaxValueHelper()
/*
Function: runTask4()
Description: Prompts the user to input numbers to a linked list and calls getMaxValue() to find the maximum value in the list. Outputs the result.
Input Parameters: None
Returns: None
*/
void runTask4() {
  int max, num;
  LinkedList list;
  string n;
  cout << "add numbers to the list to find the max (type n stop): " << endl;
  while(true){
    getline(cin, n);
    if(n == "n"){
      break;
    }
    num = stoi(n);
    list.appendNode(num);
  }
  list.displayList();
  max = list.getMaxValue();
  cout << "The max is " << max << endl;
}

// TODO: finish this function
/*
Function: generateSubstrings(string s, vector<string>& substrings)
Description: Generates all possible substrings of the given string and stores them in a vector.
Input Parameters: string s - the input string to generate substrings
vector<string>& substrings - reference to a vector to store substrings
Returns: None
*/
void generateSubstrings(string s, vector<string>& substrings) {
  if(s == ""){
    substrings.push_back(s);
    return;
  }
  substringHelper(s, substrings);
  s = s.substr(1, s.size()-1);
  generateSubstrings(s, substrings);
}

/*
Function: substringHelper(string s, vector<string>& substrings)
Description: A helper function that recursively generates substrings of the input string by cutting off the end character and stores them in the substrings vector.
Input Parameters: string s - the input string to generate substrings
vector<string>& substrings - reference to a vector to store substrings
Returns: None
*/
void substringHelper(string s, vector<string>& substrings){
  if(s == ""){
    return;
  }
  substrings.push_back(s);
  substringHelper(s.substr(0, s.size()-1), substrings);
}

// TODO: finish this function by testing generateSubstrings()
/*
Function: runTask5()
Description: Prompts the user for an input string and calls generateSubstrings() to generate all possible substrings. Outputs the substrings.
Input Parameters: None
Returns: None
*/
void runTask5() {
  string s;
  vector<string>substrings;
  cout << "enter a string to generate substrings" << endl;
  getline(cin, s);
  generateSubstrings(s, substrings);
  for(int i =0; i<substrings.size(); i++){
    cout << substrings[i] << ", ";
  }
  cout << endl;
}

// BONUS ONLY: utility function for BONUS task
// no need for any changes here
void displayMaze(char maze[8][8]) {
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for(i = 0; i < 8; i++) {
		cout << i;
		for(j = 0; j < 8; j++) {
			cout << " " << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// TODO: BONUS ONLY finish this function
bool traverseMaze(char maze[8][8], Coordinates solution[], int * steps, int currRow, int currCol) {
	return false; // TODO: fix this
}

// TODO: BONUS ONLY finish this function by testing traverseMaze()
void runBONUSTask() {
	
}
