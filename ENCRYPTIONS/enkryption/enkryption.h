#ifndef ENKRYPTION_H
#define ENKRYPTION_H

#include <cstdlib>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

class enkryption {
private:
	vector<string> p_cipher;
	string ciph_char(char input);
	string ascii_char(char input);

public:
	enkryption();
	~enkryption();

	string process(string input);
};

#endif