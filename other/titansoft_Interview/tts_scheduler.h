#ifndef TTS_SCHEDULER_H
#define TTS_SCHEDULER_H

#include <cstdlib>
#include <vector>

using namespace std;

struct worker {
	string name;
	bool dutyDays[7];
};

typedef vector< vector<struct worker*> > schedule; // top level is days of the week. Each day has a vector of workers.

class TTS_scheduler {
private:
	schedule p_schedule;
	int p_weekdaySlots;
	int p_weekendSlots;
	vector<struct worker*> p_workerPool;

public:
	TTS_scheduler(int weekdays, int weekends);
	~TTS_scheduler();

	void readConstraintsFile(string filepath);
	void arrange();

	void printWeek();
	void printWorker();

	bool findInVector(vector<struct worker*> vec, struct worker* item);


	void debug_printSchedule();
};

#endif