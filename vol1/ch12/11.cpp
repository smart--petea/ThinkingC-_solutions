/*
 * Write a Number class that holds a double, and add overloaded
 * operators for +, -, *, / and assignment.
 * Choose the return values for these functions so that expressions can be chained together, and for efficiency.
 * Write an automatic type conversion operator int()
 */

#include <iostream>
#include <ostream>

class Number
{
    private:
        double x_;

    public:
        Number(double x = 0) : x_(x) {};

        Number operator+(Number const& a) const
        {
            return Number(a.x_ + x_);
        }

        Number operator*(Number const& a) const
        {
            return Number(a.x_ * x_);
        }

        Number operator/(Number const& a) const
        {
            if(a == 0) throw "Divide to zero";

            return Number(x_ / a.x_);
        }

        Number operator-(Number const& a) const
        {
            return Number(x_ - a.x_);
        }

        bool operator==(int const& aInt) const
        {
            return (int)x_ == aInt;
        }

        bool operator==(double const& aDouble) const
        {
            return x_ == aDouble;
        }

        operator int() const
        {
            return (int)x_;
        }

        friend std::ostream& operator<<(std::ostream& os, Number const& a)
        {
            os << a.x_;
            return os;
        }
};

int main()
{
    Number a(5);
    Number b(6);
    Number c;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
///    std::cout << "(int)b = " << (int)b << std::endl;

    try {
        std::cout << "a / c = " << a / c << std::endl;
    } catch (char const* err) {
        std::cout << "error: " << err << std::endl;

        return 1;
    }

    return 0;
}
