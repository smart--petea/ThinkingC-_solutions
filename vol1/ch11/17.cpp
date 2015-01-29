/*create a class that contains a double*. The constructor
 * initializes the double* by calling new double and
 * assigning a value to the resulting storage from the
 * constructor argument. The destructor prints the value that's pointed to, assigns that value to -1, calls delete
 * for the storage, and then sets the pointer to zero. Now create a function that takes an object of your class by value, and
 * call this function in main(). what happens? fix the
 * problem by writing a copy-constructor.
 */

#include <iostream>

class A
{
	private:
		double* d_;
	public:
		A(double d) 
		{
			std::cout << "A constructor" << std::endl;
			d_ = new double;
			*d_ = d;
		}

		A(A const& cp) 
		{
			std::cout << "A copy constructor" << std::endl;
			d_ = new double;
			*d_ = *cp.d_;
		}

		~A() 
		{
			std::cout << "A destructor" << std::endl;
			std::cout << "d_ = " << *d_ << std::endl;

			*d_ = -1;

			delete d_;
			d_ = NULL;
		}
};

void foo(A a) {}

int main() 
{
	A a(5.5);

	foo(a);

	return 0;
}
