/*
 * Add an operator++ and operator-- to Exercise2, both the prefix and the postfix versions, such that they return the
 * incremented or decreemented object. Make sure that the
 * postfix versions return the correct value
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

		A operator-(A const& a1) const
		{
			return A(x_ - a1.x_);
		}

        A const& operator++()
        {
            ++x_;
            return *this;
        }

        A operator++(int)
        {
            A  a(x_);
            x_++;
            return a;
        }

        A operator--()
        {
            A a(x_);
            --x_;
            return a;
        }

        A& operator--(int)
        {
            x_--;
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
	A b(5);
	A c(2);

    a.print(std::cout);
    b.print(std::cout);

    std::cout << "d = ++a + b++" << std::endl;
	A d = ++a + b++;

    a.print(std::cout);
    b.print(std::cout);
    d.print(std::cout);
	return 0;
}
