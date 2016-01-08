#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "Worker.h"

using namespace std;

string week[] =  {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

Worker::Worker(string inputLine) {
	setName(inputLine.substr(0, inputLine.find("\t")));
	for(int i=0; i<7; i++) {
		if(inputLine.find(week[i]) == string::npos) {
			p_availability.push_back(true);
		} else {
			p_availability.push_back(false);
		}
		p_dutyDays[i] = false;	// init false
	}
}

Worker::~Worker() {}


void Worker::setName(string inputName) {
	p_name = inputName;
}

void Worker::setAvailability(int day, bool value) {
	p_availability[day] = value;
}

void Worker::setDutyDay(int day, bool value) {
	p_dutyDays[day] = value;
}


string Worker::getName() {
	return p_name;
}

vector<bool> Worker::getAvailability() {
	return p_availability;
}

bool Worker::getAvailability(int day) {
	return p_availability[day];
}

bool Worker::getDutyDay(int day) {
	return p_dutyDays[day];
}

int Worker::calc_score(vector<Worker*> inputPool, int limits[7]) {
	int scores[7] = {0};
	int total = 0;
	for(int i=0; i<7; i++) {
		for(auto W : inputPool) {
			if(W->getAvailability(i) == true) {
				scores[i]++;	// sum of each day's manpower
			}
		}
		scores[i] -= limits[i];	// distance of each day's manpower from limit
		total += ( scores[i] * scores[i] );	// sum-squared-distance
	}
	// negative checking
	for(auto score : scores) {
		if(score < 0) {
			return -1;
		}
	}
	return total;
}

int Worker::get_Importance(vector<Worker*> pool, int limits[7]) {
	// error checking
	vector<Worker*>::iterator pos = find(pool.begin(), pool.end(), this);
	if(pos == pool.end()) {
		return -99;
	}
	int position = distance( pool.begin(), pos );

	// find current score
	int oldTotal = calc_score(pool, limits);			// calculate combined score

	// find score if ownself is removed
	vector<Worker*> futurePool = pool;
	futurePool.erase(futurePool.begin() + position);
	int newTotal = calc_score(futurePool, limits);		// calculate combined score

	// check for negative scores;
	if(newTotal < 0) {
		return -1;
	}

	// if everything is ok (no negatives), return difference between new scores and limits
	return (oldTotal - newTotal);
}

void Worker::debug_stat() {
	cout << p_name << "\t\t";
	for(auto a : p_availability) {
		cout << a << " ";
	} cout << endl;
}