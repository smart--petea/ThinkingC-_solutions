/*
 * Add the unary operator- to Exercise 2 and demonstrate 
 * that it works correctly
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

        A& operator-() 
        {
            x_ = -x_;
            return *this;
        }

		void print(std::ostream& ostr) 
		{
			ostr << "x = " << x_ << "\n";
		}
};

int main()
{
	A a(5);

    a = -a;
    a.print(std::cout);

	return 0;
}
