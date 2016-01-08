#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

#include "tts_scheduler.h"

using namespace std;

string week[] =  {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

TTS_scheduler::TTS_scheduler(int weekdays, int weekends){
	p_weekdaySlots = weekdays;
	p_weekendSlots = weekends;
	for(int i=0; i<7; i++) {
		vector<struct worker*> day;
		p_schedule.push_back(day);
	}
}

TTS_scheduler::~TTS_scheduler(){}

//=========================================
void TTS_scheduler::
readConstraintsFile(string filepath){
	string constraintLine;

	ifstream fs;
	fs.open(filepath);
	getline(fs, constraintLine);	// first line is redundant
	getline(fs, constraintLine);	// second line is also redundant
	while(!fs.eof()) {
		getline(fs, constraintLine);

		// get name
		struct worker* newWorker = new worker;
		newWorker->name = constraintLine.substr(0, constraintLine.find("\t"));

		// get available days
		for(int i=0; i<7; i++) {
			if(constraintLine.find(week[i]) == string::npos) {
				p_schedule[i].push_back(newWorker);	// add worker to day-list
				newWorker->dutyDays[i] = true;	// temporary value
			} else {
				newWorker->dutyDays[i] = false;	// temporary value
			}
		}
		p_workerPool.push_back(newWorker);
	}
	// debug_printSchedule();
	fs.close();
}

bool TTS_scheduler::
findInVector(vector<struct worker*> vec, struct worker* item) {
	for(auto I : vec) {
		if(I == item) {
			return true;
		}
	}
	return false;
}

void TTS_scheduler::
arrange(){
	srand(time(NULL));
	for(int i=0; i<p_schedule.size(); i++) {
		int limit;
		if(i<5){ // weekday
			limit = p_weekdaySlots;
		} else { // weekend
			limit = p_weekendSlots;
		}
		// remove or add extra workers for each day
		while(p_schedule[i].size() != limit) {
			if(p_schedule[i].size() > limit) {	// remove excess workers
				p_schedule[i].erase(p_schedule[i].begin()+ (rand() % p_schedule[i].size()));	
			} else {	// add additional workers (Sorry for adding them, but no choice.)
				struct worker* temp;
				do {
					temp = p_workerPool[rand()%p_workerPool.size()];
				} while(findInVector(p_schedule[i], temp));	// check if worker is already rostered

				p_schedule[i].push_back(temp);	// add to schedule
				temp->dutyDays[i] = true;		// add to worker's schedule
			}
		}
	}
}

void TTS_scheduler::
printWeek(){
	cout << "Day \t\tWorkers\n========================" << endl;
	for(int i=0; i<p_schedule.size(); i++) {
		cout << week[i] << "  \t";
		vector<struct worker*> day = p_schedule[i];

		for(int j=0; j<day.size(); j++) {
			cout << day[j]->name;
			if(j!=day.size()-1) cout << ", ";	// formatting output
		}
		cout << endl;
	}
}

void TTS_scheduler::
printWorker(){
	cout << "Workers' Individual Schedules\n========================" << endl;
	for(auto W : p_workerPool) {
		cout << W->name << "\t\t";
		for(int i=0; i<7; i++) {
			if(W->dutyDays[i]) {
				cout << week[i] << ", ";
			}
		}
		cout << endl;
	}
}

void TTS_scheduler::
debug_printSchedule() {
	for(auto W : p_schedule) {
		for(auto S : W) {
			cout << S->name << ", ";
		}
		cout << endl;
	}
}