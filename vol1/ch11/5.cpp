/*
 * Create a class with some member functions, and make
 * that the object that is pointed to by the argument of Exercise 4. Make the pointer a const and make some of
 * the member functions const and prove that you can only call the const member functions inside your function.
 * Make the argument to your function a reference instead
 * of a pointer
 */
#include <iostream>

class A
{
	public:
		void constFoo() const 
		{
			std::cout << "constFoo" << std::endl;
		};

		void nonConstFoo()
		{
			std::cout << "nonConstFoo" << std::endl;
		};
};

template <typename T>
T const & foo(T const& x)
{
	x.constFoo();
	return x;
}

int main()
{
	A a;

	foo(a);

	return 0;
}
