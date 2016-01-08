#ifndef TTS_TEAM_H
#define TTS_TEAM_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

extern string week[7];

using namespace std;

struct worker {
	string name;
	bool availability[7];
	bool dutyDays[7];
};

class TTS_team {
private:
	vector<worker*> p_team;

public:
	TTS_team();
	~TTS_team();

	void addWorker(string line);
	vector<int> get_strength();
	void trim();
};

#endif