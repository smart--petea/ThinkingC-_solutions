/*
 * Create a class that contains a pointer, and demonstrate
 * that if you allow the compiler to synthesize the operator=
 * the result of using that operator will be pointers that are
 * alizsed to the same storage.
 * Now fix the problem by defining your own operator= and demonstrate that it corrects the aliasing.
 * Make sure you check for self-assignement and handle that case properly
 */

#include <iostream>
#include <ostream>

class A
{
    private:
        int* x_;
    public:
        A(int x = 0)  
        {
            x_ = new int;
            *x_ = x;
        };

        A(A const& a) {
            x_ = new int;
            *x_ = *(a.x_);
        }

        ~A()
        {
            delete x_;
        }

        A& operator=(A const& a) 
        {
            std::cout << "operator =";
            *x_ = *(a.x_);

            return *this;
        }

        bool operator==(A const& a)
        {
            return a.x_ == x_;
        }

        friend std::ostream& operator<<(std::ostream& os, A const& a)
        {
            os << *(a.x_);
            return os;
        }

};

int main()
{
    A a(5);
    A b = a; //copy constructor
    A c;

    c = a; //operator=
    std::cout << "*(a.x_) = " << a << std::endl;
    std::cout << "*(b.x_) = " << b << std::endl;
    std::cout << "*(c.x_) = " << c << std::endl;
    std::cout << "(a == a) = " << (a == a) << std::endl;
    std::cout << "(a == b) = " << (a == b) << std::endl;
    std::cout << "(a == c) = " << (a == c) << std::endl;

    return 0;
}
