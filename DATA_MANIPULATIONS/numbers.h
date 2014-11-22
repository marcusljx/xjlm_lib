#ifndef NUMBERS_H
#define NUMBERS_H

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

enum BASE_DIGITS{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
};

class Number{
	private:
		double	m_value;
		string	m_representation;
		int			m_base;
	
	public:
		Number(unsigned int Base, string Representation);
		~Number();
	
		void	set_base();
		void	set_value(double value);
		void	set_representation();
	
		void		get_base();
		double 	get_value();
		string 	get_representation();
};

#endif