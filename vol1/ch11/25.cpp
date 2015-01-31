/*
 * Create a class containing an array of int.
 * Can you index through this array using a pointer to member?
 */

#include <iostream>

class A
{
	public:
		int x[10];
		A() 
		{
			for(int i = 0; i < 10; i++) x[i] = 10 + i;	
		}
};

int main() 
{
	A a;
	int (A::*x)[10] = &A::x;

	std::cout << "walk through a.x" << std::endl;
	for(int i = 0; i < 10; i++)
		std::cout << "a.x[" << i << "] = " << (a.*x)[i] << std::endl;

	return 0;
}
