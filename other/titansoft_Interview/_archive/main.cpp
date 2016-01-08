#include <cstdlib>
#include <iostream>
#include <string>

#include "tts_scheduler.h"
#include "tts_team.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int weekdaySlots = stoi(argv[2]);
	int weekendSlots = stoi(argv[3]);
	int totalWorkers = stoi(argv[4]);

	TTS_scheduler ttss(weekdaySlots, weekendSlots, totalWorkers);
	ttss.readConstraintsFile(argv[1]);	// read input file

	// ttss.debug_printWorkerStats();
	// ttss.debug_printWorkforce();

	// ttss.arrange();

	// cout << endl;
	// ttss.printWeek();

	// cout << endl;
	// ttss.printWorker();

	return 0;
}