/*
 * create a class with a copy-constructor that announces
 * itself. Make a second class containing a mebmer object of the first class, but do not create a copyt-constructor.
 * Make a second class containing a member object of
 * the first class, but do not create a copy-constructor. Shwo
 * that the synthesized copy-constructor in the second class autmoatically calls the copy-constructor
 * of the first class
 */

#include <iostream>

class A
{
	public:
		A(){};
		A(A const& )
		{
			std::cout << "A copy constructor" << std::endl;
		}
};

class B
{
	private:
		A a_;
	public:
		B(){};
};

void foo(B ){};

int main()
{
	B b;

	foo(b);
	return 0;
}
