Task #1 Output Parameters 
Write a program that reads integers from a file called numbers.txt until all integers have been read. As each integer is read from the file, your program should answer the following three questions for that particular integer:
Is the value a multiple of 7, 11, or 13?
Is the sum of the digits odd or even?
Is the value a prime number?
The answers to the questions are to be displayed to the screen. 
Additional Requirements
The program must call the required function:
void answerIntegerQuestions(const int num, bool * isMultiple, bool * isSumEven, bool * isPrime) 

This function accepts a single integer value (the number read from the file to answer the questions about) and accepts three output parameters (one for each answer to each question). You need to define three additional functions, one for computing the answer to each question.

Note: If numbers.txt is in a different directory than your executable (e.g. it is not in the build directory), then you will need to use a more specific path (e.g. "../numbers.txt").
-------------------------------

Task #2 Pointer Notation 
A lottery ticket buyer purchases 10 tickets a week, always playing the same 5-digit lucky combinations: 13579 26791 26792 33445 55555 62483 77777 79422 85647 93121

Write a program that initializes an array with these numbers and then prompts the user to enter this week's winning 5-digit number. Inform the user if they have won the lottery or not 💰💰💰
Additional Requirements
The program must call the required function:
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers);

This function performs a linear search through the list of the player’s numbers and returns whether or not one of the tickets is a winner this week. findWinningLotteryTicket() uses only pointer notation instead of array notation :) 

Do not hardcode the size of the array to be 10. Use numPlayerNumbers for the size!!
--------------------------------------

Task #3 Dynamic Memory Allocation 
Write a program to create random sentences. Read from an input file called input_words.txt that contains article, nouns, verbs, and prepositions. An example input_words.txt file:
10
Articles 5
the a one some any
Nouns 5
boy girl dog town car
Verbs 5
drove jumped ran walked skipped
Prepositions 5
to from over under on

The first integer in the file (10 in the example) specifies the number of sentences to generate. The rest of the input file has sections for each part of speech. The first string will label the part of speech (“Articles” in the example) and an integer specifying the number of that type of word that is on the next line (5 in the example). 

The words given for each part of speech are to be stored in a dynamically allocated array of strings, one array for each part of speech. Each of these arrays (articles, nouns, verbs, prepositions) should be displayed in alphabetical order (implement your choice of sorting algorithm). 

After the arrays are set up and sorted, generate the random sentences and display them numbered. A sentence is of the form: article noun verb preposition article noun. Capitalize the first letter and add an exclamation point to the end. 
