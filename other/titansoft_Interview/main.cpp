#include <cstdlib>
#include <iostream>
#include <string>

#include "tts_scheduler.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int weekdaySlots = stoi(argv[2]);
	int weekendSlots = stoi(argv[3]);

	TTS_scheduler ttss(weekdaySlots, weekendSlots);
	ttss.readConstraintsFile(argv[1]);	// read input file

	ttss.arrange();

	cout << endl;
	ttss.printWeek();

	cout << endl;
	ttss.printWorker();
	return 0;
}