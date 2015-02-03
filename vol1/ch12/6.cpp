/*
 * change the print() function in Exercise 2 so taht it is the overloaded operator<< as in 
 * IostreamOperatorOverloading.cpp
 */


#include <ostream>
#include <iostream>

class A
{
	private:
		int x_;

	public:
		A(int x = 0) : x_(x) {};

		A operator+(A const& a1) const
		{
			return A(x_ + a1.x_);
		}

		void print(std::ostream& ostr) 
		{
			ostr << "x = " << x_ << "\n";
		}

        friend std::ostream& operator<<(std::ostream& os, const A& ia) {
            os << ia.x_;
        }

        friend std::istream& operator>>(std::istream& is, A& ia) {
            is >> ia.x_;
        }
};

int main()
{
	A a;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << std::endl << "a = " << a << std::endl;

	return 0;
}
