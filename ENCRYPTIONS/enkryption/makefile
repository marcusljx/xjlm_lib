all:runTest

CC= g++
OBJECTS= enkryption.o
COMPILE_ARGS= -std=c++11
TEST_ARGS= < test.txt >output.txt

runTest: test
	clear
	./test $(TEST_ARGS)

test: main.cpp $(OBJECTS)
	$(CC) -o test main.cpp $(OBJECTS) $(COMPILE_ARGS)

%.o: %.cpp %.h
	$(CC) -c $< $(COMPILE_ARGS)

clean:
	rm *.o test