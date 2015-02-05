#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
// GLOBALS =================================================
bitset<16> test_string_bin(0b0101101010010001);

// MECHANISMS =================================================
int form1_iterators[] = {12,13,8,14,9,4,15,10,5,0,11,6,1,7,2,3};

bitset<16> restructure(bitset<16> input, int* form) {
	bitset<16> result;
	for(int i=0; i<16; i++) {
		result[i] = input[form[i]];
	}
	return result;
}

// TEST OUTPUTS =================================================
void testCrypt16(int input_int) {
	bitset<16> input_bin(input_int);		// binary form
	bitset<16> output_bin = restructure(input_bin, form1_iterators);
	int output_int = (int)(output_bin.to_ulong());
	
	cout << "input NUMBER:\t" << input_int << endl;
	cout << "input BINARY:\t" << input_bin << endl;
	cout << "output BINARY:\t" << output_bin << endl;
	cout << "output NUMBER:\t" << output_int << endl;
	cout << "================================================" << endl;
}

// MAIN RUNNING =================================================
int main(int argC, char* argV[]) {
	testCrypt16(2);
	testCrypt16(4096);
	testCrypt16(1);
	testCrypt16(512);
	
	return 0;
}