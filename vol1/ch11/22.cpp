/*
 * This exercise creates an alternative to using the copy-constructor.
 * Create a class X and declare (but don't
 * define) a priate copyt-constructor; Make a public clone()
 * function as a const member function that returns a copy of the object that is created using new. Now write a
 * function that takes as an argument a const X& and clones
 * a local copy that can be modified. The drawback to this
 * approach is that you are responsible for explicitly
 * destroying the cloned object(using delete) when you're done with it.
 */

#include <iostream>

class X
{
	private:
		X(X&);
		int a_;
	public:
		X(int a): a_(a)
		{
			std::cout << "X constructor" << std::endl;
		}

		X* clone() const
		{
			std::cout << "X.clone" << std::endl;
			return new X(a_);
		}
};

void foo(X const& y)
{
	std::cout << "foo" << std::endl;
	X* z = y.clone();

	std::cout << "delete z" << std::endl;
	delete z;
}

int main()
{
	X x(5);
	foo(x);
}
