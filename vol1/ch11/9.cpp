/*
 * Write a class that has a const member function and a non-const member function. Write three functions that
 * take an object of that class as an argument; the first takes
 * it by value, the second by reference, and the third by const reference. Inside the functions, try to call both
 * member function of your class and explain the results
 */

#include <iostream>

class A
{
	public:
		void xConst() const
		{
			std::cout << "xConst function" << std::endl;
		}

		void xNonConst() 
		{
			std::cout << "xNonConst function" << std::endl;
		}
};

void byValue(A a) 
{
	std::cout << std::endl << "byValue function" << std::endl;
	a.xConst();
	a.xNonConst();
}

void byRef(A& a)
{
	std::cout << std::endl << "byRef function"  << std::endl;
	a.xConst();
	a.xNonConst();
}

void byRefConst(A const& a)
{
	std::cout<< std::endl << "byRef function" << std::endl;
	a.xConst();
	//a.xNonConst();
}

int main()
{
	A x;

	byValue(x);
	byRef(x);
	byRefConst(x);

	return 0;
}
