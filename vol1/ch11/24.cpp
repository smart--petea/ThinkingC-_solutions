/*
 * Create a class containing a double and a print() function
 * that prints the double. In main() create pointers to members for both the data member and the function in your class. Create an object of your class and a pointer to that object, and manipuate
 * both class elements via your pointers to members, using
 * both the object and the
 * pointer to the object
 */

#include <iostream>

class A
{
	public:
		A(double x1) 
		{
			x = x1; 
			std::cout << "A constructor x = " << x << std::endl;
		};

		double x;
		void print()
		{
			std::cout << "X.print" << std::endl;
			std::cout << "x = " << x << std::endl;
		};
};

int main()
{

	A a(5.1);

	double A::* xOuter = &A::x;
	void (A::*printOuter)() = &A::print;

	std::cout << "aPtr->*printOuter()" << std::endl;
	(a.*printOuter)();

	std::cout << "aPtr->*xOuter = 7" << std::endl;
	a.*xOuter = 7.4;

	std::cout << "aPtr->*printOuter()" << std::endl;
	(a.*printOuter)();

	return 0;
}
