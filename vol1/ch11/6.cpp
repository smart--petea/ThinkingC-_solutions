/*
 * Take the code fragments at the beginning of the section
 * titled "Pointer references" and to\urn then into a program
 */

#include <iostream>
using namespace std;

void increment(int*& i) { i++; }

int main() {
	int* i = 0;

	cout << "i = " << i << endl;

	increment(i);
	cout << "i = " << i << endl;

	increment(i);
	cout << "i = " << i << endl;
}
