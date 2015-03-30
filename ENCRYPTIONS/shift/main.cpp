#include <iostream>
#include <string>
#include <vector>
#include "shift_index.h"

using namespace std;

int main(int argc, char const *argv[]) {
	shift_index SI(NULL);

	string encryptedText = SI.encrypt("Hello World Aa Zz!", 1);
	cout << "The Encrypted String is:\n" << encryptedText << endl;

	cout << "unencrypted wrongkey:\n" << SI.decrypt(encryptedText, 4) << endl;

	return 0;
}