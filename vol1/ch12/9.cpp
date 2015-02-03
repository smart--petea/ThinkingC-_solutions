/*
*Create a class that contains a single private char.
*Overload the iostream operators << and >> (as in
*IostreamOperatorOverloadin.cppp and test them. You
*can test the with fstream, stringstream, and cin and cout)
*/

#include <ostream>
#include <iostream>

class A
{
    private:
        char x_;

    public:
        A(char x = 'a') : x_(x) {};

        friend std::ostream& operator<<(std::ostream& os, A const& a)
        {
            os << a.x_;
            return os;
        }

        friend std::istream& operator>>(std::istream& os, A& a)
        {
            os >> a.x_; 
            return os;
        }
};

int main()
{
    A a;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << std::endl;

    std::cout << "a = " << a;
    std::cout << std::endl;

    return 0;
}
