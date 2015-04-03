all:runTest

CC= g++
OBJECTS= charset.o

runTest: test
	clear
	./test

test: main.cpp $(OBJECTS)
	$(CC) -o test main.cpp $(OBJECTS)

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm *.o test