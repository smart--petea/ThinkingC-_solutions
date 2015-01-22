#include <iostream>
#include <string>

using namespace std;

void reverse(string& x)
{
	int size = x.size();
	if(size == 0 || size == 1) return;

	int middle = size/2;
	char tmp;

	for(int i = 0; i < middle; i++) tmp = x[i], x[i] = x[size - i - 1], x[size - i - 1] = tmp;
}

void showReverse(char const* x)
{
	string s = x;

	cout << "reverse of \"" << s << "\" - ";
	reverse(s);
	cout << "\"" << s << "\"" << endl;
}
