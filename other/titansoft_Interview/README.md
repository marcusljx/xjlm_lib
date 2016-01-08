The data containing the worker's offdays should have the same format as the provided sample file, ie.:
	- The first 2 lines are disregarded (filler)
	- Every worker's name has no spaces before it, and is immediately followed by a TAB character.
	- Every line only corresponds to one worker.

Some flexible features of this program are:
	- You can add as many workers as you like, but the program will only pick up to the maximum number ("totalWorkers") specified in the makefile (originally 4, in requirement 7).
	- You can specify any number of offdays for any worker.


The default filename can be modified under the "inputfile" variable in the makefile.

To change the number of workers required for weekdays or weekends, change the variables in the makefile as needed (requirement 3). You can also change the maximum number of workers that can be hired (requirement 7).

IMPORTANT NOTE: The variables should follow the invariant
	(weekdaySlots * 5) + (weekendSlots * 2) <= (Sum of all available days of all workers)

If the values are modified so that the above invariant is false, it will be impossible to satisfy all the requirements. This is because each worker can only fill one slot on any given day, if there isn't enough manpower, the slots cannot be filled completely. This scenario will result in an infinite loop of the program (at phase2() in the code).


=== HOW TO USE (tested on Linux only) ===
run:
	make