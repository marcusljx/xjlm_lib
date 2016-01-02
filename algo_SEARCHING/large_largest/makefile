all: run

num=5
inputfile=testfile.txt
testEntries=20

run: newTestFile l_largest.bin
	./l_largest.bin $(num) < $(inputfile)

newTestFile: generateTestFile.bin
	./generateTestFile.bin $(testEntries) > $(inputfile)

generateTestFile.bin: generateTestFile.cpp
	g++ generateTestFile.cpp -o generateTestFile.bin

l_largest.bin: l_largest.cpp
	g++ l_largest.cpp -o l_largest.bin