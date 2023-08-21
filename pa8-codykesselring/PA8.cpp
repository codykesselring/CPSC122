#include "PA8.h"

// no need for changes here
/*
Function: runPrimesPrompt()
Description: Prompts the user to enter a value for 'n' representing the maximum number to compute prime numbers up to and including using the Sieve algorithm. Repeats until the user enters -1 to quit. For each valid input, creates a Sieve object and sets the value of 'n' to the input, then calls the Sieve's run() function to compute and report the prime numbers up to 'n'.
Input Parameters: None
Returns: None
*/
void runPrimesPrompt() {
	Sieve sieve; // reuse same Sieve object
	int n = -1;
	cout << "This program computes all prime numbers up to a maximum using the Sieve of Eratosthenes." << endl;
	do {
		cout << endl << "Please enter n, where n is max value to show primes up to and including (-1 to quit): ";
		cin >> n;
		if (n != -1) {
			sieve.setN(n);
			sieve.run();
		}
	} while (n != -1);
}
