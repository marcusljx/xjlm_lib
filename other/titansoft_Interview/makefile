all:run

inputfile=sampleData.txt
weekdaySlots=3
weekendSlots=3
totalWorkers=5

flags=-std=c++0x
OBJ=Worker.o

debug: prog.bin
	cgdb prog.bin

run: prog.bin
	./prog.bin $(inputfile) $(weekdaySlots) $(weekendSlots) $(totalWorkers)

prog.bin: main.cpp $(OBJ)
	g++ main.cpp $(OBJ) -o prog.bin $(flags)

%.o: %.cpp %.h 
	g++ -c $< $(flags)

clean:
	rm *.bin *.o