/*
 * Determine the dummy constant value that your compiler passes for
 * postfix operator ++ and operator--
 */

#include <iostream>

class A
{
    public:
        A operator++(int x)
        {
            std::cout << "operator++" << std::endl;
            std::cout << "x = " << x << std::endl;;

            A a;
            return a;
        }

        A operator--(int x)
        {
            std::cout << "operator--" << std::endl;
            std::cout << "x = " << x << std::endl;

            A a;
            return a;
        }
};

int main()
{
    A a;

    a--;
    a++;

    return 0;
}
