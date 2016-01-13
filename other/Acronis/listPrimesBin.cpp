#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int findBitLength(int input) {
	int result = 0;
	while(input > 0) {
		result++;
		input = input >> 1;
	}
	return result;
}


bool checkPrime(long long input) {
	if(input == 2) return true;
	
	long long divisor = input / 2;
	while(divisor > 1) {
		if(input % divisor == 0) {
			return false;
		}
		divisor -= 1;
	}

	return true;
}

void printPrime(int N) {
	bitset<8> B(N);

	cout << N << " \t" << B << endl;
}

int main(int argc, char const *argv[]) {
	int lowerbnd = atoi(argv[1]);
	int upperbnd = lowerbnd * 2;

	for(int i=lowerbnd; i<upperbnd; i++) {
		if(checkPrime(i)) {
			printPrime(i);
		}
	}

	return 0;
}