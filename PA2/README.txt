Write a program in 3-file format that sorts one-dimensional vectors of integers. You will collect measurements for:
An already sorted vector
An already sorted vector in descending order
A vector containing random data

Generate each of the above vectors with the following number of nodes:
500
1000
5000
10000
(more values if you wish)
Make copies of the original vectors (as necessary) and pass the copies to each sorting routine so each routine is operating on the same data! This is important in order to compare the results of the different algorithms.

Implement the following vector sorting routines :
Selection sort
Early exit bubble sort (stops when the list is sorted)
Insertion sort

For each sorting routine above, collect performance metrics related to the algorithm's execution time using the now() function in the chrono library and counts for the following operations:
Number of data comparisons
Number of loop control comparisons
Number of assignment operations involving data
Number of assignment operations involving loop control
"Other" operations (operations that don't fall into one of the above categories)
Total number of operations (sum of the above)
