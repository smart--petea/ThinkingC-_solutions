#include "1lib.hpp"
#include "2lib.hpp"
#include <string>

using namespace std;

bool isPalindrom(string x)
{
	string x_reverse = x;
	reverse(x_reverse);

	return x_reverse == x;
}
