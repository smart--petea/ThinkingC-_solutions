/*
 * Fix TypeConversionFanout.cpp by creating an explicit
 * function to call to perform the type conversion, instead of
 * one of the automatic conversion operators
 */
#include <iostream>

class Orange {};
class Pear {};

class Apple
{
    public:
        operator Orange() const { std::cout << "Orange operator" << std::endl; return Orange(); };
        //operator Pear() const;

        Pear makePear() const
        {
            std::cout << "Pear operator" << std::endl;
            return Pear();
        }
};

//Overloaded eat()
void eat(Orange) {};
void eat(Pear) {};

int main()
{
    Apple c;
    eat(c); //orange
    eat(c.makePear()); //pear
}
