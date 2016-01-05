To run simply to see the operation of taking the largest 1000 values from a file of 1000000 numbers, run:
	make

To generate a file of random numbers (from 0 to INT_MAX), change the "testEntries" variable in the makefile to the number of random numbers you would like, then run:
	make newTestFile

To run the program, change the "num" variable in the makefile to the number of largest numbers you would like (e.g. 1000), then run:
	make

The program makes use of a priority queue in descending order (lowest pops first), to contain only up to 1000 variables at any one time. As the numbers are read in from the file, they are inserted into the priority queue. If the size of the priority queue goes >1000, the lowest number is removed from the container. The result will be the largest 1000 numbers from the datafile.

The complexity of the priority queue operations are O(lg e), where e is the maximum size of the container. In this case as the container's maximum size is constant, the full complexity of the program is O(N), which is from the linear-time operation of reading in the data. The general case complexity should be O(n lg e).

The program works on both unique and non-unique datafiles.