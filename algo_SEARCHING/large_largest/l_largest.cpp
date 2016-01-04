#include <cstdlib>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int topSize;

class comparator {
public:
	bool operator()(int& lhs, int& rhs) {
		return (lhs > rhs);
	}
};


void print(priority_queue<int, vector<int>, comparator> input) {
	int temp;
	while(!input.empty()) {
		temp = input.top();
		cout << temp << endl;
		input.pop();
	}
}

int main(int argc, char const *argv[])
{
	topSize = atoi(argv[1]);
	// cout << "INT_MAX = " << INT_MAX << endl;

	int input;
	priority_queue<int, vector<int>, comparator> top;
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