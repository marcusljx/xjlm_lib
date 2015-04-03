#ifndef METHOD_H
#define METHOD_H

#include <cstdlib>
#include <vector>

class method {
private:
	vector<void*>		p_input_set;
	vector<void*>		p_output_set;
public:
	method();
	~method();

	void restructure();
};

#endif