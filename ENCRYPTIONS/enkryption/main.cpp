#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "enkryption.h"

using namespace std;

string cipher_mirror(string input) {
	string output = "";
	for(int i=0; i<input.size(); i++) {
		char c = input[i];
		if(c <= 'M' ) {
			output += ( 'Z' - (c-'A') );
		} else {
			output += ( 'A' + ('Z'-c) );
		}
	}

	return output;
}


int main(int argc, char const *argv[]) {
	enkryption* enk = new enkryption();
	

	string original_string;
	while(getline(cin, original_string)) {
		// cerr << "====" << original_string << endl;
		string processed = enk->process(original_string);
		cout << cipher_mirror(processed);
	}

	// string test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// cerr << test << " --> " << cipher_mirror(test);
	cout << endl;

	

	delete enk;
	return 0;
}