#ifndef LEFTBRAIN_H
#define LEFTBRAIN_H

#include "../libs_std.h"

using namespace std;

class leftBrain {
	private:
		int holding number;
		vector<int> m_int_storage;
	
	public:
		leftBrain();
		~leftBrain();
		
		int int_do();
};

#endif