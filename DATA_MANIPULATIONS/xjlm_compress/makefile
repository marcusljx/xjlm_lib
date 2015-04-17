all:runTest

CC= g++
OBJECTS= 
COMPILE_ARGS= -std=c++11
TEST_ARGS= hello

runTest: test
	clear
	./test $(TEST_ARGS)

test: main.cpp $(OBJECTS)
	$(CC) -o test main.cpp $(OBJECTS) $(COMPILE_ARGS)

%.o: %.cpp %.h
	$(CC) -c $< $(COMPILE_ARGS)

clean:
	rm *.o test