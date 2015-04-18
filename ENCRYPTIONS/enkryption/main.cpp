#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "enkryption.h"

using namespace std;

int main(int argc, char const *argv[]) {
	enkryption* enk = new enkryption();
	

	string original_string;
	while(getline(cin, original_string)) {
		cerr << "====" << original_string << endl;
		string processed = enk->process(original_string);
		cout << processed << endl;
	}



	

	delete enk;
	return 0;
}