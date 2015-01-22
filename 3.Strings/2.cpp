#include "2lib.hpp"
#include <iostream>

using namespace std;

int main()
{
	string x = "xmadamx";
	string nu = isPalindrom(x) ? "" : "nu ";

	cout << nu << "este palindrom " << endl;
	return 0;
}
