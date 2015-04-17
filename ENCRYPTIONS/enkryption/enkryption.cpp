#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include "enkryption.h"

using namespace std;

enkryption::enkryption() {
	p_cipher = {		"DP",				// A
									"QL",				// B
									"TL",				// C
									"EL",				// D
									"DL",				// E
									"DOVM",			// F
									"WL",				// G
									"DP",				// H
									"DKDL",			// I
									"WODL",			// J
									"ZODL",			// K
									"DPF",			// L
									"DPA",			// M
									"DPS",			// N
									"DH",				// O
									"VL",				// P
									"ZLDN",			// Q
									"DKFM",			// R
									"DPTM",			// S
									"XL",				// T
									"DB",				// U
									"NL",				// V
									"ESJQMFDB",	// W
									"DPRTM",		// X
									"DHKDL",		// Y
									"WPE",			// Z
									"ZMS",			// keun
										};
}
enkryption::~enkryption() {}

string enkryption::
ciph_char(char input) {
	// cerr << input << "-->";
	string output = "";
	if( (input >= 'A')&&(input <= 'Z') ) {
		output += p_cipher[26];
		input +=32;
	} 
	if( (input >= 'a')&&(input <= 'z') ) {
		output += p_cipher[input-'a'];
	} else {
		output += input;
	}

	// cerr << output << endl;
	return output;
}

string enkryption::
ascii_char(char input) {
	bitset<7> bits((int)input);
	string output = bits.to_string();
	reverse(output.begin(), output.end());
	return output;
}

string enkryption::
process(string input) {
	string output = "";
	string pox;

	for(int i=0; i<input.length(); i++) {
		pox = ciph_char(input[i]);
		for(int j=0; j<pox.length(); j++) {
			output += ascii_char(pox[j]);
		}
	}


	return output;
}
