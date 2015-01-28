/*
 * Create a function that takes an argument of a reference to a pointer to a pointer and modifies that argument. 
 * In main() call the function
 */

#include <iostream>

void foo(int**& x) { ++x; }

int main()
{
	int x = 5;
	int* px = &x;
	int** ppx = &px;

	std::cout << "ppx = " << ppx << std::endl;

	foo(ppx);
	std::cout << "ppx = " << ppx << std::endl;

	foo(ppx);
	std::cout << "ppx = " << ppx << std::endl;
}
