/*
 * Write a program in which you try to
 * (1)Create a reference that in not initialized when it is created.
 * (2) Change a reference to refer to another object after it is initialized
 * (3) create a NULL reference
 */

#include <iostream>

int main()
{
	//1
	int x;
	int& y = x;

	std::cout << "y=&x, x not initialized" << std::endl;
	std::cout << "y= " << y << std::endl;

	//2
	int z = 10;
	int& m = z;
	int r = 100;
	m = r;

	std::cout << "change a reference to refer to another object after it is initialized" << std::endl;
	std::cout << "m = " << m << std::endl;

	//3
	//int const& k = NULL;

	return 0;
}
