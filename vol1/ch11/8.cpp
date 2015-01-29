/*
 * Create a function that takes a char& argument and
 * modifies that argument. In main() print out a char variable, call your function for that variable, and print it
 * out again to prove to yourself that it has been changed.
 * How does this affect program readability?
 */

#include <iostream>

void charM(char& x)
{
	x += 1;
}

int main()
{
	char x = 'a';

	std::cout << "x = " << x << std::endl;

	std::cout << "charM(x)" << std::endl;
	charM(x);

	std::cout << "x = " << x << std::endl;

	return 0;
}
