all:run

inputfile=sampleData.txt
weekdaySlots=2
weekendSlots=3

flags=-std=c++0x

debug: prog.bin
	cgdb prog.bin

run: prog.bin
	./prog.bin $(inputfile) $(weekdaySlots) $(weekendSlots)

prog.bin: main.cpp tts_scheduler.o
	g++ main.cpp tts_scheduler.o -o prog.bin $(flags)

tts_scheduler.o: tts_scheduler.h tts_scheduler.cpp
	g++ -c tts_scheduler.cpp $(flags)

clean: *.bin *.o
	rm *.bin *.o