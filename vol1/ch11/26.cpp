/*
 * Modify PmemFunDefinition.cpp by adding an overloaded member function f() (you can determine the argument list that causes the oveload). Now make
 * a second pointer to member, assign it ot the overloaded
 * second pointer to member, assign it ot the overloaded
 * version of f(), and call the function through that pointer.
 * How does the overload resolution happen in this case?
 */

#include <iostream>

class Simple2
{
	public:
		int f(float) const { std::cout << "f(float)" << std::endl; return 1; }
		int f(int) const { std::cout << "f(int)" << std::endl; return 1; }
};


int main()
{
	int (Simple2::*fFloat)(float) const = &Simple2::f;
	int (Simple2::*fInt)(int) const = &Simple2::f;

	Simple2 s;

	(s.*fFloat)(1.1);
	(s.*fInt)(1);

	return 0;
}
