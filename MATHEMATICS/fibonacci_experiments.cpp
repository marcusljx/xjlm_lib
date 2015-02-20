#include <cstdlib>
#include <iostream>

#include <algorithm>
#include <vector>
#include <string>
#include <bitset>

using namespace std;
// OUTPUT FUNCTIONS
void print_vect_uint(vector<unsigned int> input) {
	for(int i=0; i<input.size(); i++) {
		cout << input[i] ;
		if(i != (input.size()-1)) {
			cout << endl;
		}
	}
}

void print_bin_vect_uint(vector<unsigned int> input) {
	for(int i=0; i<input.size(); i++) {
		bitset<16> temp(input[i]);
		cout << temp << endl;
	}
}

// CALC FUNCTIONS
vector<unsigned int> fibonacci(unsigned int n) {
	vector<unsigned int> result;
	result.push_back(0);
	if(n == 0) {
		return result;
	}

	result.push_back(1);
	if(n == 1) {
		return result;
	}

	while(result.size() <= n) {
		unsigned int fib1 = result[result.size() - 2];
		unsigned int fib2 = result[result.size() - 1];
		result.push_back(fib1 + fib2);
	}

	return result;
}

//==========================================================================
int main(int argc, char const *argv[]) {
	int n = 30;
	vector<unsigned int> test = fibonacci(n);
	cout << "fib(" << n << "):" << endl;
	print_bin_vect_uint(test);
	cout << endl;
	return 0;
}