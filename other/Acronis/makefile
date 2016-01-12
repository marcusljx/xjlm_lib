all:run

inputNumber=1
flags=-std=c++11

run: prog.bin
	./prog.bin $(inputNumber)

prog.bin: main.cpp
	g++ main.cpp -o prog.bin $(flags)

clean: a.out
	rm a.out