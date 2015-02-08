#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>

using namespace std;
// GLOBALS =================================================
bitset<16> test_string_bin(0b0101101010010001);

// MECHANISMS =================================================
int form1_iterators[] = {12,13,8,14,9,4,15,10,5,0,11,6,1,7,2,3};
int form2_iterators[] = {12,8,13,4,9,14,0,5,10,15,1,6,11,2,7,3};
int form3_iterators[] = {12,13,14,15,11,7,3,2,1,0,4,8,9,10,6,5};
int form4_iterators[] = {12,8,4,0,1,2,3,7,11,15,14,13,9,5,6,10};

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
	
	// RESTRUCTURE
	bitset<16> output_bin_f1 = restructure(input_bin, form1_iterators);
	bitset<16> output_bin_f2 = restructure(input_bin, form2_iterators);
	bitset<16> output_bin_f3 = restructure(input_bin, form3_iterators);
	bitset<16> output_bin_f4 = restructure(input_bin, form4_iterators);
	
	
	// CONVERSION TO INT
	int output_int_f1 = (int)(output_bin_f1.to_ulong());
	int output_int_f2 = (int)(output_bin_f2.to_ulong());
	int output_int_f3 = (int)(output_bin_f3.to_ulong());
	int output_int_f4 = (int)(output_bin_f4.to_ulong());
	
	
	// PRINTOUT
	cout << "input NUMBER:\t" << input_int << endl;
	cout << "input BINARY:\t" << input_bin << endl;
	cout << "form1:\t" << output_bin_f1 << "\t(" << output_int_f1 << ")" << endl;
	cout << "form2:\t" << output_bin_f2 << "\t(" << output_int_f2 << ")" << endl;
	cout << "form3:\t" << output_bin_f3 << "\t(" << output_int_f3 << ")" << endl;
	cout << "form4:\t" << output_bin_f4 << "\t(" << output_int_f4 << ")" << endl; 
	cout << "================================================" << endl;
}

// MAIN RUNNING =================================================
int main(int argC, char* argV[]) {
	testCrypt16(2);
	
	return 0;
}