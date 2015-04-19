#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include "enkryption.h"

using namespace std;

enkryption::enkryption() {
	p_cipher = {		"DPDL",			// A
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
									"WPFH",			// 0
									"DNJ",			// 1
									"XN",				// 2
									"TTMFL",		// 3
									"VH",				// 4
									"VKDL",			// 5
									"TLRTM",		// 6
									"TPQMS",		// 7
									"DPDLT",		// 8
									"SKDL",			// 9
										};
}
enkryption::~enkryption() {}

string enkryption::
ciph_char(char input) {
	// cerr << input << "-->";
	// letters
	string output = "";
	if( (input >= 'A')&&(input <= 'Z') ) {
		output += p_cipher[26];
		input +=32;
	} 
	if( (input >= 'a')&&(input <= 'z') ) {
		output += p_cipher[input-'a'];
	} else if( (input >= '0')&&(input <= '9') ) {
		output += p_cipher[input-'0'+27];
	} else {
		output += input;
	}

	// symbols
	switch(input) {
		case ' ':
			output = "TMVPDLTM";
			break;

		case '!':
			output = "DPRTMZMFOAODLTUSAKFZM";
			break;

		case '"':
			output = "ZNJXM";
			break;

		case '#':
			output = "GPTTM";
			break;

		case '(':
			output = "DHVPSQMFPZPT";
			break;

		case ')':
			output = "ZMFFHTMQMFPZPT";
			break;

		case '*':
			output = "AJXLVMFKDL";
			break;

		case '+':
			output = "VMFJTM";
			break;

		case ',':
			output = "ZJAJ";
			break;

		case '-':
			output = "DJSEJTM";
			break;

		case '.':
			output = "EKT";
			break;

		case '/':
			output = "ELQKDLEM";
			break;

		case ':':
			output = "ZHFFJS";
			break;

		case ';':
			output = "TPALZHFFJS";
			break;

		case '<':
			output = "FPTTJEPS";
			break;

		case '=':
			output = "DLZNJFTM";
			break;

		case '>':
			output = "RMFPDLXJEPS";
			break;

		case '[':
			output = "DHVPSTMZNPDJQMFPZPT";
			break;

		case ']':
			output = "ZMFFHTMTMZNPDJQMFPZPT";
			break;

		case '_':
			output = "DJSEJTMZJ";
			break;

		case '{':
			output = "DHVPSQMFKRQMFOTM";
			break;

		case '}':
			output = "ZMFFHTMQMFKRQMFOTM";
			break;

		case '\t':
			output = "XOQM";
			break;

		case '\n':
			output = "<enter>";
			break;
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
		// for(int j=0; j<pox.length(); j++) {
		// 	output += ascii_char(pox[j]);
		// }
		output += pox;
	}

	output += "DLDHDPF"; // EOL
	return output;
}
