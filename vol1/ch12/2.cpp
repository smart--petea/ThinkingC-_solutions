/*
 * Create a simple class containing an int and overload the
 * operator+ as a membmer function. Also provide a print()
 * member function that takes an ostream& as an argument 
 * an prints to that ostream&. test your class to show that 
 * it works correctly.
 */

#include <ostream>
#include <iostream>

class A
{
	private:
		int x_;

	public:
		A(int x):x_(x) {};

		A operator+(A const& a1) const
		{
			return A(x_ + a1.x_);
		}

		void print(std::ostream& ostr) 
		{
			ostr << "x = " << x_ << "\n";
		}
};

int main()
{
	A a(5);
	A b(4);
	A c = a + b;

	a.print(std::cout);
	b.print(std::cout);
	c.print(std::cout);

	return 0;
}
