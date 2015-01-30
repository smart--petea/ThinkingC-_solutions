/*create a simple class without a copy-constructor, and a
simple function that takes an object of that class by value.
Now change your class by adding a private declaration 
(only) for the copy-constructor. explain what happens
when your function is compiled
*/

#include <iostream>

class A
{
	public:
		A() 
		{
			std::cout << "A constructor" << std::endl;
		}

	private:
		/*
		 * if copy constructor is private
		 * we can't call the A instances by value
		 * from any function
		 */
		A(A&) 
		{
			std::cout << "A copy constructor" << std::endl;
		}
};

void foo(A a)
{
	//when foo is called copy constructor is called
	std::cout << "function foo" << std::endl;
}

int main()
{
	A b;

	foo(b);

	return 0;
}
