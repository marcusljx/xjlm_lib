all: run

num=1000
inputfile=testfile.txt
testEntries=1000000
flags=-std=c++11

run: $(inputfile) l_largest.bin
	./l_largest.bin $(num) $(inputfile)

$(inputfile): generateTestFile.bin
	./generateTestFile.bin $(testEntries) > $(inputfile)

generateTestFile.bin: generateTestFile.cpp
	g++ generateTestFile.cpp -o generateTestFile.bin $(flags)

l_largest.bin: l_largest.cpp
	g++ l_largest.cpp -o l_largest.bin $(flags)

clean:
	rm *.bin $(inputfile) *.o