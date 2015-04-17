#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string compress(string input)  {
	string output="";
	for(int i=0; i<input.length()-1; i++) {
		cerr << (int)input[i] << " - " << (int)input[i+1] << " = ";
		char x = input[i] - input[i+1];
		cerr << (int)x << endl;
		output += x;
	}

	return output;
}



int main(int argc, char const *argv[]) {
	string original(argv[1]);

	string compressed = compress(original);

	cout << "compress--> \t" << compressed << endl;
	
	return 0;
}