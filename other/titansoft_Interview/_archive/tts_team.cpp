#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "tts_team.h"

using namespace std;

string week[] =  {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

TTS_team::TTS_team(){}
TTS_team::~TTS_team(){}

void TTS_team::
addWorker(string line) {
	worker* newWorker = new worker;
	newWorker->name = line.substr(0, line.find("\t"));

	// set available days
	for(int i=0; i<7; i++) {
		if(line.find(week[i]) == string::npos) {
			newWorker->availability[i] = true;	// temporary value
		} else {
			newWorker->availability[i] = false;	// temporary value
		}
	}
	p_team.push_back(newWorker);
}

vector<int> TTS_team::
get_strength() {
	vector<int> strength({0,0,0,0,0,0,0});
	for(auto W : p_team) {
		for(int day=0; day<7; day++) {
			if(W->availability[day]) {
				strength[day]++;
			}
		}
	}
	return strength;
}


void TTS_team::
trim() {
	
}