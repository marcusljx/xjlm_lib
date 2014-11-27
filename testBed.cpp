#include <cstdlib>
#include <iostream>
//#include "DATA_MANIPULATIONS/numbers.h"

using namespace std;

int g_lowerB;
int g_upperB;
int g_answer;
int g_guess;

unsigned int ticker=0;

int Guess_Number_halfway(int A, int B){
	cout << "#-- finding halfway point between " << A << " and " << B << endl;
	int difference;
	int result;
	if(A==B) {
		return A;
	}
	
	if(A<B) {
		result = A + ((B-A)/2);	
	} else if(B<A) {
		result = B + ((A-B)/2);	
	}
	
	cout << result << " ";
	return result;
}

int main(int argC, char* argV[]) {
	cout << "Input Answer: ";
	cin >> g_answer;
	
	cout << "Input Lower Bound: ";
	cin >> g_lowerB;
	
	cout << "Input Upper Bound: ";
	cin >> g_upperB;
	
	cout << "guesses: ";
	g_guess = Guess_Number_halfway(g_lowerB, g_upperB);
	while(g_guess != g_answer) {
		if(g_guess < g_answer) {
			g_lowerB = g_guess;				// set new lower bound;
		} else {
			g_upperB = g_guess;				// set new upper bound;
		}
		
		// TODO: SET CONDITIONAL FOR HIGHER OR LOWER GUESSING METHOD
		g_guess = Guess_Number_halfway(g_lowerB, g_upperB);
		ticker++;
	}
	cout << endl;
	
	cout << "Obtained answer:\t" << g_guess << "\tin " << ticker << " tries." << endl;
	
	return 0;
}