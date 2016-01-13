#include <cstdlib>
#include <unistd.h>
#include <iostream>

#define PATH_MAX 1024

using namespace std;

string projectName;
char buffer[PATH_MAX];


int main(int argc, char const *argv[]) {
	projectName = argv[1];

	string cwd = getcwd(buffer, PATH_MAX);
	string projDir = cwd + "/" + projectName;

	// create directory
	cout << "Creating new Project Directory: " + projectName << endl;
	string cmd = "mkdir " + projDir;
	system(cmd.c_str());
	
	// create main.cpp
	cmd = "cp " + "templates/t_main.cpp " + projDir + "/" + projectName + ".cpp";
	system(cmd.c_str());

	return 0;
}