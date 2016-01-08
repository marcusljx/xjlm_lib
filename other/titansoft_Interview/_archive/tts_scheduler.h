#ifndef TTS_SCHEDULER_H
#define TTS_SCHEDULER_H

#include <cstdlib>
#include <vector>

#include "tts_team.h"

using namespace std;

typedef vector< vector<struct worker*> > schedule; // top level is days of the week. Each day has a vector of workers.

class TTS_scheduler {
private:
	schedule p_schedule;
	int p_weekdaySlots;
	int p_weekendSlots;
	int p_totalWorkers;

	TTS_team p_team;
	vector<struct worker*> p_workerPool;		// for containing all worker data
	vector<struct worker*> p_selectedWorkers;	// only those selected for the week

public:
	TTS_scheduler(int weekdays, int weekends, int totalWorkers);
	~TTS_scheduler();

	void readConstraintsFile(string filepath);
	void findWorkerSelection();
	void arrange();

	void printWeek();
	void printWorker();

	bool findInVector(vector<struct worker*> vec, struct worker* item);


	void debug_printSchedule();
	void debug_printWorkerStats();
	void debug_printVector(vector<int> input);
};

#endif