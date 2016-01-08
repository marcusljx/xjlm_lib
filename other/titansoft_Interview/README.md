The data containing the worker's offdays should have the same format as the provided sample file, ie.:
	- The first 2 lines are disregarded (filler)
	- Every worker's name has no spaces before it, and is immediately followed by a TAB character.
	- Every line only corresponds to one worker.

To change the number of workers required for weekdays or weekends, change the values in the makefile as needed.

The program runs by first reading in the data file, and fills in a weekly schedule by putting every worker that is available on that day in the day slot. The next step then removes (or adds) workers until the correct number of workers for that day is reached. This means that the schedule will definitely have the correct number of workers rostered on every day, even if it means rostering a worker on his/her off day. This only comes into effect if there are not enough "on" workers for that day.

Some notes:
- The program has no limit on the number of workers provided. Feel free to add to the datafile.
- 