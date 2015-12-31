all: run

num=10
inputfile=testfile.txt
testEntries=100

run: l_largest.bin
	./l_largest $num < $testfile

newTestFile: generateTestFile.bin
	g++ generateTestFile.cpp -o generateTestFile.bin
	./generateTestFile $testEntries > $inputfile

l_largest.bin: l_largest.cpp
	g++ l_largest.cpp -o l_largest.bin