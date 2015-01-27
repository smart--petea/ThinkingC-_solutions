/*
 *Write a program named replace that takes three command-line arguments representing
 *an input text file, a string to replace (call it from, and a replacement string (call it to).
 *The program should write a new file to standard output with all occurrences of from replaced by to.
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "myReplace.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 4) {
		cerr << "usage: ./a.out input_file from to";
		exit(1);
	}

	string from = argv[2];
	string to = argv[3];
	string line;

	ifstream fromFile(argv[1]);
	if(!fromFile) {
		cerr << "error opening file: " << argv[1] << endl;
		exit(1);
	}


	while(getline(fromFile, line)) myReplace(line, from, to), cout << line << endl;

	return 0;
}
