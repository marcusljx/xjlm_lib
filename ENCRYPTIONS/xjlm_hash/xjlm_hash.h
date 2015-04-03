#ifndef XJLM_HASH_H
#define XJLM_HASH_H

#include <string>
#include <vector>

using namespace std;

class XJLM_HASH {
private:
	vector<char> p_line;

public:
	XJLM_HASH();
	~XJLM_HASH();

	string encrypt(string message, int key);
	string decrypt(string message, int key);

};

#endif