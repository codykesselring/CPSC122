#include "Sieve.h"

/*
Function: Sieve()
Description: Constructor for the Sieve class. Initializes 'n' to 0 and creates two DoublyLinkedQueue objects for numsQ and primesQ.
Input Parameters: None
Returns: None
*/
Sieve::Sieve() {
	n = 0;
	numsQ = new DoublyLinkedQueue();
	primesQ = new DoublyLinkedQueue();
}

/*
Function: ~Sieve()
Description: Destructor for the Sieve class. Frees the memory allocated for numsQ and primesQ.
Input Parameters: None
Returns: None
*/
Sieve::~Sieve() {
	if (numsQ != NULL) {
		delete numsQ;
	}
	if (primesQ != NULL) {
		delete primesQ;
	}
}

/*
Function: getN()
Description: Getter function that returns the value of 'n' in the Sieve class.
Input Parameters: None
Returns: An integer value, representing the value of 'n'.
*/
int Sieve::getN() const {
	return n;
}

/*
Function: setN()
Description: Setter function that sets the value of 'n' in the Sieve class to the provided integer value.
Input Parameters: int nParam: The integer value to set 'n' to
Returns: None
*/
void Sieve::setN(int nParam) {
	n = nParam;
}

// TODO: finish this function
/*
Function: computePrimes()
Description: Computes the prime numbers up to 'n' using the Sieve of Eratosthenes algorithm and stores them in the primesQ DoublyLinkedQueue.
Input Parameters: None
Returns: None
*/
void Sieve::computePrimes() {
  DoublyLinkedQueue numsQ;
  DoublyLinkedQueue * primesQ = new DoublyLinkedQueue();
  
	for(int i=2; i<n; i++){
    numsQ.enqueue(i);
  }
  
  int prime;
  while(!numsQ.isEmpty()){
    prime = numsQ.dequeue();
    primesQ->enqueue(prime);
    numsQ.removeDivisibleBy(prime);
  }
  
  this->primesQ = primesQ;
}

/*
Function: reportResults()
Description: Reports the computed prime numbers and calculates the percentage of prime numbers in the range from 1 to 'n'.
Input Parameters:
- double& primePercent: A reference to a double variable that will store the calculated percentage of prime numbers
Returns: An integer value, representing the number of prime numbers found.
*/
int Sieve::reportResults(double& primePercent) {
	int numPrimes = 0;
	
	cout << "Primes up to " << n << " are as follows: " << endl;
	primesQ->displayQueue();
	
	numPrimes = primesQ->size();
	primePercent = static_cast<double>(numPrimes) / n * 100;
	
	return numPrimes;
}

/*
Function: run()
Description: Executes the main steps of the Sieve algorithm, including computing the prime numbers, reporting the results, and displaying the percentage of prime numbers.
Input Parameters: None
Returns: None
*/
void Sieve::run() {
	int numPrimes = 0;
	double primePercent = 0.0;
	
	computePrimes();
	numPrimes = reportResults(primePercent);
	cout << numPrimes << " / " << n << " = " << primePercent << "% primes" << endl;
}