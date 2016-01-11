#include <cstdlib>
#include <vector>
#include <iostream>
#include <climits>
#include <string>
#include <queue>

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
	// cout << "INT_MAX = " << INT_MAX << endl;

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

	return 0;
}