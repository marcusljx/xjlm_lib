#ifndef ENTITY_H
#define ENTITY_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum DATATYPE {
	INT,
	DOUBLE,
	STRING
};

struct factor{
	string 			label;
	unsigned int 	type;
	unsigned int 	position;
};

class entity{
private:
	vector<struct factor> m_factors;		// container of factors

	vector<int>		m_data_int;				// container 1
	vector<double>	m_data_double;			// 2
	vector<string>	m_data_string;			// 3

public:
	entity();
	~entity();

	void 	add_factor(string label, DATATYPE type, (void*) data_ptr);
	void*	get_factor(string label);
};

#endif