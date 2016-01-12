#include <cstdlib>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bool checkPrime(long long input) {
	if(input == 2) return true;
	
	long long divisor = input / 2;
	while(divisor > 0) {
		if(input % divisor == 0) {
			return false;
		}
		divisor -= 2;
	}

	return true;
}


int main(int argc, char const *argv[]) {
	long long inputNumber = stoi(argv[1]);
	long long result = inputNumber;

	if(checkPrime(inputNumber)) {
		cout << "Prime!" << endl;
	} else {
		cout << "NOT Prime!" << endl;
	}

	// if(inputNumber <= 3) {
	// 	result = 2;
	// }

	// long long lowerBound = (inputNumber + 2) / 2;	//Bertrand's postulate
	// cout << "lowerBound=" << lowerBound << endl;

	// if(result % 2 == 0 ) {
	// 	result --;
	// }
	// while(result > lowerBound) {
	// 	// primality test


	// 	result -= 2;
	// }

	// cout << "result=" << result << endl;
	return 0;
}