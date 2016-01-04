#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int numOfEntries = atoi(argv[1]);

	for(int i=0; i<numOfEntries; i++) {
		cout << rand() % 5 << endl;
	}

	return 0;
}