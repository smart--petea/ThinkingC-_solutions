/*
 *Write a program named replace that takes three command-line arguments representing
 *an input text file, a string to replace (call it from, and a replacement string (call it to).
 *The program should write a new file to standard output with all occurrences of from replaced by to.
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

void myReplace(string&, string const&, string const&);

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

void myReplace(string& source, string const& from, string const& to)
{
	size_t pos;
	size_t old_pos = 0;
	size_t toLength = to.length();
	size_t fromLength = from.length();

	while((pos = source.find(from, old_pos)) != string::npos)
	{
		old_pos =  pos + toLength;
		source.replace(pos, fromLength, to);
	};
}
