/*
 * Create a simple class with an overloaded operator++.
 * try calling this operator in both pre- and postfix form and
 * wee what kind of compiler warning you get
 */

#include <string>
#include <iostream>

class A
{
	private:
		static const char pattern_ = 'a';
		std::string x_;

	public:
		A const& operator++()
		{
			std::cout << "prefix ++" << std::endl;
			x_.append(1, pattern_);

			return *this;
		}

		A const& operator++(int)
		{
			std::cout << "postfix ++" << std::endl;
			x_.append(1, pattern_);

			return *this;
		}

		void print() {
			std::cout << "x = " << x_ << std::endl;
		}
};

int main() 
{
	A a;
	++a;
	++a;
	a++;
	
	a.print();
	return 0;
}
