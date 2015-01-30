/*
 * Create a very simple class, and a function that return an object of that class by value. Create a second function that takes a reference to an object of your class.
 * Call the first function as the argument of the second function, and
 * demonstrate that the second function must use a const reference as its argument
 */

#include <iostream>

class A
{
	public:
		A()
		{
			std::cout << "A constructor" << std::endl;
		}
};

A foo()
{ 
	std::cout << "function foo" << std::endl;
	A x;
	return x; 
};

void boo(A const& a)
{
	std::cout << "function boo" << std::endl;
}

int main()
{
	boo(foo());
}
