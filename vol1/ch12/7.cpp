/*
 * Modify Exercise 3 so that the operator+ and operator- are
 * non-member functions. Demonstrate that the still work correctly
 */

#include <ostream>
#include <iostream>

class A
{
	private:
		int x_;

	public:
		A(int x):x_(x) {};

		friend A operator+(A const& a1, A const& a2)
		{
			return A(a1.x_ + a2.x_);
		}

		friend A operator-(A const& a1, A const& a2)
		{
			return A(a1.x_ - a2.x_);
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
	A c(2);

	A d = a - b - c - c ;

	a.print(std::cout);
	b.print(std::cout);
	c.print(std::cout);
	d.print(std::cout);

	return 0;
}
