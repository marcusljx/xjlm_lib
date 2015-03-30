#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "shift_index.h"

using namespace std;

char ENGLISH_UPPERCASE[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int ASCII_A = (int)'A';
int ASCII_Z = (int)'Z';
int ASCII_a = (int)'a';
int ASCII_z = (int)'z';
int ASCII_space = (int)' ';

string ignored = " !@#$%^&*()-_=+,./<>?;'\":";

shift_index::
shift_index(char char_set[]) {
	if(char_set == NULL) {
		character_set = ENGLISH_UPPERCASE;
		char_set_size = 26;
	} else {
		character_set = char_set;
		char_set_size = sizeof(character_set) / sizeof(char);
	}

}

shift_index::
~shift_index() {}

string shift_index::
process(string message, int shift) {
	string result = message;

	for(int i=0; i<message.length(); i++) {		// loop through all characters
		int temp = (int)message[i];
		int changed;

		if( ignored.find(temp) == string::npos ) {		// encrypt all unignored
			changed = temp + (shift % char_set_size);
			// cout << "changed=" << changed << endl;

			if( (temp >=ASCII_A) && (temp <= ASCII_Z) ) {
				if(changed < ASCII_A) {
					changed += char_set_size;
				} else if (changed > ASCII_Z) {
					changed -= char_set_size;
				}
			}

			if( (temp >=ASCII_a) && (temp <= ASCII_z) ) {
				if(changed < ASCII_a) {
					changed += char_set_size;
				} else if (changed > ASCII_z) {
					changed -= char_set_size;
				}
			}		

		} else {
			changed = temp;
		}
		result[i] = changed;
	}

	return result;
}


string shift_index::
encrypt(string message, int key) {
	return process(message, key);
}

string shift_index::
decrypt(string message, int key) {
	return process(message, -key);
}
