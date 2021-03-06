#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Worker.h"

using namespace std;

vector<Worker*> g_workerPool;
int weekday;
int weekend;
int min_Workers;
int max_Workers;
int g_limits[7] = {0};

void debug_printWorkerPool() {
	for(auto W : g_workerPool) {
		int impt = W->get_Importance(g_workerPool, g_limits);
		cout << "\t[" << impt << "] \t";
		W->debug_stat();
	}
}

void readInput(string filepath) {
	string constraintLine;
	ifstream fs;
	fs.open(filepath);
	getline(fs, constraintLine);
	getline(fs, constraintLine);
	while(!fs.eof()) {
		getline(fs, constraintLine);
		Worker* W = new Worker(constraintLine);
		g_workerPool.push_back(W);
	}
}

//================= PHASE 1 ===============
bool importanceComparator(Worker* A, Worker* B) {
	int impt_A = A->get_Importance(g_workerPool, g_limits);
	int impt_B = B->get_Importance(g_workerPool, g_limits);
	return (impt_A < impt_B);
}

void preprocess() {		// chooses people to take slots where nobody is available
	int manpower[7] = {0};
	int total = 0;
	for(int i=0; i<7; i++) {
		for(auto W : g_workerPool) {
			if(W->getAvailability(i) == true) {
				manpower[i]++;	// sum of each day's manpower
			}
		}
		manpower[i] -= g_limits[i];	// distance of each day's manpower from limit

		while(manpower[i] < 0) {	// ensures that the minimum number of workers are rostered
			Worker* chosenOne;
			do {
				chosenOne = g_workerPool[rand() % g_workerPool.size()];
			} while(chosenOne->getAvailability(i) == true);
			chosenOne->setAvailability(i, true);
			manpower[i]++;
		}
	}
}

void phase1() {		// trims worker pool
	sort(g_workerPool.begin(), g_workerPool.end(), importanceComparator);
	// debug_printWorkerPool();

	// trim "most un-needed" worker based on availability
	while( (g_workerPool.size() > max_Workers) || (g_workerPool.back()->get_Importance(g_workerPool, g_limits) > 0)) {
		g_workerPool.pop_back();
		// cerr << "================================================" << endl;
		sort(g_workerPool.begin(), g_workerPool.end(), importanceComparator);
		// debug_printWorkerPool();
	}
}

//================== PHASE 2 ===============
void phase2() {		// assigns workers on days that have more than needed
	cout << "Week Schedule\n================================================" << endl;

	vector< vector<Worker*> > schedule;
	for(int i=0; i<7; i++) {	// decrease limit and fill days
		vector<Worker*> day;

		int daySlots = (i<5) ? weekday : weekend;
		Worker* selected;
		vector<bool> w_availability;
		while (day.size() < daySlots) {
			do {
				selected = g_workerPool[ rand() % g_workerPool.size() ];
				w_availability = selected->getAvailability();
			} while( (find(day.begin(), day.end(), selected) != day.end()) || (w_availability[i] == false) );

			// set in day schedule
			day.push_back(selected);

			// set in worker schedule
			selected->setDutyDay(i, true);
		}
		schedule.push_back(day);

		// output week schedule
		cout << week[i] << "  \t";
		for(auto d_worker : day) {
			cout << d_worker->getName() << ", ";
		} cout << endl;
	}
	cout << endl;
	
	// print individual worker timetables
	cout << "Workers Schedule\n================================================" << endl;
	for(auto d_worker : g_workerPool) {
		cout << d_worker->getName() << "\t\t";
		for(int d=0; d<7; d++) {
			if(d_worker->getDutyDay(d) == true) {
				cout <<	week[d] << ", ";
			}
		} cout << endl;
	}
}

//================== MAIN =============
int main(int argc, char const *argv[]) {
	srand(time(NULL));
	weekday = stoi(argv[2]);
	weekend = stoi(argv[3]);

	for(int i=0; i<7; i++) {
		g_limits[i] = (i<5) ? weekday : weekend;	// set 0-4 to weekday, 5-6 to weekend
	}

	max_Workers = stoi(argv[4]);
	min_Workers = (weekend > weekday) ? weekend : weekday;

	readInput(argv[1]);
	// debug_printWorkerPool();
	// cerr << "================================================" << endl;
	preprocess();
	phase1();
	phase2();

	return 0;
}