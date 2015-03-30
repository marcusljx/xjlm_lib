#ifndef SHIFT_INDEX_H
#define SHIFT_INDEX_H

#include <string>
#include <vector>

using namespace std;

class shift_index {
private:
	int shift;
	char* character_set;
	int char_set_size;

	string process(string message, int shift);

public:
	shift_index(char* char_set);
	~shift_index();

	string encrypt(string message, int key);
	string decrypt(string message, int key);
};

#endif