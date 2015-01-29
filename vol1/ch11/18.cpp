/*
 * Create a class with a constructor that looks like a copy-constructor, but that has an extra argument with a 
 * default value. Show that this is still used as the copy-constructor
 */

#include <iostream>

class A
{
	public:
		A() 
		{
			std::cout << "A constructor" << std::endl;
		}

		A(A& x, int def = 0)
		{
			std::cout << "A copy constructor with def = " << def << std::endl;
		}
};

void foo(A b){};

int main()
{
	A a;

	foo(a);
}
