#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int topSize = atoi(argv[1]);
	vector<int> top;	cerr << "topSize = " << topSize << endl;

	cout << "INT_MAX = " << INT_MAX << endl;

	int input; int i=0;
	while(cin >> input) {
		// cout << input << endl;
		// filter here
		if(top.size() == 0) {
			top.push_back(input);
		}
	}
	cout << "Exiting." << endl;
	return 0;
}