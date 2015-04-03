#ifndef CHARSET_H
#define	CHARSET_H

#include <vector>
#include <string>

using namespace std;

class charset {
private:
	vector<char> p_set;

public:
	charset();
	~charsset();

	void create_set(string input_chars);
	void create_set(charset* set_to_copy);
	void get(int pos);
};

#endif