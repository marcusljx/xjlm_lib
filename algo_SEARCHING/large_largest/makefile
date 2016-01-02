all: run

num=10
inputfile=testfile.txt
testEntries=100

run: l_largest.bin
	./l_largest.bin $(num) < $(inputfile)

newTestFile: generateTestFile.bin
	./generateTestFile.bin $(testEntries) > $(inputfile)

generateTestFile.bin: generateTestFile.cpp
	g++ generateTestFile.cpp -o generateTestFile.bin

l_largest.bin: l_largest.cpp
	g++ l_largest.cpp -o l_largest.bin