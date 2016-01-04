#include <cstdlib>
#include <vector>
#include <iostream>
#include <climits>
#include <set>

using namespace std;

int topSize;

void printSet(set<int> S) {
	set<int>::iterator i;
	for(i=S.begin(); i!=S.end(); i++) {
		cout << *i << endl;
	}
}

int main(int argc, char const *argv[])
{
	topSize = atoi(argv[1]);
	// cout << "INT_MAX = " << INT_MAX << endl;

	int input;
	set<int> top;
	while(cin >> input) {
		top.insert(input);
		if(top.size() > topSize) {
			top.erase(top.begin());
		}
	}
	cout << "TOP " << topSize << " UNIQUE ELEMENTS:" << endl;
	printSet(top);

	return 0;
}