#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "enkryption.h"

using namespace std;



int main(int argc, char const *argv[]) {
	enkryption* enk = new enkryption();
	
	string original_string(argv[1]);
	string processed = enk->process(original_string);

	cout << "================ PROCESSED STRING ================\n" << processed << endl;

	delete enk;
	return 0;
}