all:testListPrimes

inputNumber=32
flags=-std=c++11



run: prog.bin
	./prog.bin $(inputNumber)

testListPrimes: listPrimesBin.cpp
	g++ -o listPrimesBin listPrimesBin.cpp
	./listPrimesBin $(inputNumber)



prog.bin: main.cpp
	g++ main.cpp -o prog.bin $(flags)

clean: a.out
	rm a.out