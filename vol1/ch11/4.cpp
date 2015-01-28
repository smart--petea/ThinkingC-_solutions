/*
 * write a function that takes a pointer argument, 
 * modifies what the pointer points to, and then returns 
 * the destination of the pointer as a reference
 */

#include <iostream>

template <typename T>
T& myFoo(T* x)
{
	//do something with *x
	return *x;
}

int main()
{
	int x = 10;
	int& y = myFoo(&x);


	if(x == y) {
		std::cout << "x == y" << std::endl;
	} else {
		std::cout << "x != y" << std::endl;
	}

	if(&x == &y) {
		std::cout << "&x == &y" << std::endl;
	} else {
		std::cout << "&x != &y" << std::endl;
	}

	y = 5;

	std::cout << "y = " << y << std::endl;
	std::cout << "x = " << x << std::endl;

	return 0;
}
