all:runTest

CC= g++
OBJECTS=
RUN_ARGS= 1212221
CMP_ARGS= -std=c++11

runTest: test
	clear
	./test $(RUN_ARGS)

test: main.cpp $(OBJECTS)
	$(CC) -o test main.cpp $(OBJECTS) $(CMP_ARGS)

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm *.o test