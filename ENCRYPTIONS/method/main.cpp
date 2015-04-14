#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int f1(int input) {
	return input << 2;
}

int f2(int input) {
	return input-1;
}

int runFunction(int (*ffff)(int), int x) {
	return ffff(x);
}

int fArray_runner(vector<int(*)(int)> fArray, int value) {
	int result=value;

	for(int i=0; i<fArray.size(); i++) {
		result = runFunction(fArray[i], result);
	}
	return result;
}


vector<int(*)(int)> generate_fArray(char* input) {
	vector<int(*)(int)> result;
	int temp;
	for(int i=0; i<strlen(input); i++) {
		temp = input[i] - '0';

		switch(temp) {
			case 1:
				result.push_back(&f1);
				break;

			case 2:
				result.push_back(&f2);
				break;
		}
	}
	return result;
}


int main(int argc, char *argv[]) {
	int test1 = 4;
	// string f_arg(argv[1]);

	vector<int(*)(int)> f_array = generate_fArray(argv[1]);
	int encrypted = fArray_runner(f_array, testv);

	cout << "encryption:\t" << testv << " >>> " << argv[1] << " >>> " << encrypted << endl;

	return 0;
}