/*
 * Create a class Counted that contains an int id and a static int count. the default constructor should begin:
 * Counted() : id(count++). It should also print its id and t
 * that it's being created. the destructor should print that 
 * it's being destroyed and its id. test your class
 */

#include <iostream>

class Counted
{
        static int count;
        int id;
    public:
        Counted() : id(++count) 
        {
            std::cout << "Counted(" << id << ")"<< std::endl;
        };

        ~Counted()
        {
            std::cout << "~Counted(" << id << ")"<< std::endl;
        };
};

int Counted::count = 0;

int main()
{
    Counted counted;
}
