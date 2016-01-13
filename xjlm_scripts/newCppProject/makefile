all:test

input=testProj
flags=-std=c++11

test: newCppProject
	./newCppProject $(input)

newCppProject: main.cpp
	g++ main.cpp -o newCppProject $(flags)

clean:
	rm -rf $(input) *.bin newCppProject