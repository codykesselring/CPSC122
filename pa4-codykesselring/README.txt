Write a program that reads information about the inventory of a package delivery truck from an input file that is provided to the program via command line arguments. For example, if truckload.txt is the name of the input file to process and is in the top level project directory, then the program is run as ./runPA4 ../truckload.txt. If the user does not provide the filename via command line arguments, print a message informing the user.

Here is an example truckload.txt input file (which is included in the starter code)
John "King of the Road" Stirrat

7529
7.8
10
4
5

1234
2.23
3
2
5

The first line of the file is the truck driver name (John "King of the Road" Stirrat in the example file above). The remainder of the file contains information about a variable number of packages. Use dynamic memory allocation, to allocate the package array. Be sure to properly free all of your dynamically allocated memory!!

Note: If truckload.txt is in a different directory than your executable (e.g. it is not in the build directory), then you will need to use a more specific path (e.g. "../truckload.txt").

Package information in the file consists of:
ID number (integer 7529 is the ID number of the first package in the example file above)
Weight (floating-point 7.8 is the weight of the first package in the example file above)
Width (integer 10 is the width of the first package in the example file above)
Length (integer 4 is the length of the first package in the example file above)
Height (integer 5 is the height of the first package in the example file above)

Define a structure called Package that contains data components for the 5 package information fields above. Read in the package information in truckload.txt into an array of Package structures. Display the package information in forward order and statistics about the packages:
ID of the heaviest package
Weight of the heaviest package
Average weight of all the packages
