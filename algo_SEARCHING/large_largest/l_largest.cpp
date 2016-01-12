#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int topSize;

void print(priority_queue<int, vector<int>, greater<int>> input) {
	int temp;
	while(!input.empty()) {
		temp = input.top();
		cout << temp << endl;
		input.pop();
	}
}

int main(int argc, char const *argv[])
{
	topSize = stoi(argv[1]);
	string inputFile = argv[2];

// original code
/*
	int input;
	priority_queue<int, vector<int>, greater<int>> top;
	while(cin >> input) {
		top.push(input);
		if(top.size() > topSize) {
			top.pop();
		}
	}
	cout << "TOP " << topSize << " UNIQUE ELEMENTS:" << endl;
	print(top);
*/


// method recommended by Alan
	streampos size;
	int* memblock;

	ifstream file(inputFile);
	if(file.is_open()) {
		size = file.tellg();
		cout << "Number of values = " << size / sizeof(int) << endl;
		// memblock = new int[size / sizeof(int)];
	}



	return 0;
}