#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	int topSize = atoi(argv[1]);
	int top[topSize];	cerr << "topSize = " << topSize << endl;
	vector<int> idx;

	int input; int i=0;
	while(cin >> input) {
		// cout << input << endl;
		// filter here
		if( (i==0) || ( (idx.size() !=0)&&(input > top[idx[0]]) ) ) {
			top[i] = input;		// append number to top array;
			idx.push_front(i);	// append position of number to front of idx;
			i++;
			if(i>topSize) {
				break;
			}
		}
	}
	cout << "Exiting." << endl;
	return 0;
}