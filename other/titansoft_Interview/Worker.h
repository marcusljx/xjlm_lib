#ifndef WORKER_H
#define WORKER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern string week[7];

class Worker{
private:
	string p_name;
	vector<bool> p_availability;
	bool p_dutyDays[7];

public:
	Worker(string inputLine);
	~Worker();

	void setName(string inputName);
	void setAvailability(vector<bool> inputAvailability);
	void setDutyDay(int day, bool value);

	string getName();
	vector<bool> getAvailability();
	bool getDutyDay(int day);

	int calc_score(vector<Worker*> inputPool, int limits[7]);
	int get_Importance(vector<Worker*> pool, int limits[7]);

	void debug_stat();
};

#endif