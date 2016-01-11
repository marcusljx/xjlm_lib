#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int numOfEntries = stoi(argv[1]);

	for(int i=0; i<numOfEntries; i++) {
		cout << rand() << endl;
	}

	return 0;
}