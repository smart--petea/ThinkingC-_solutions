/*
 * Prove to yourself that new and delete always call the
 * constructors and destructors by creating an aobject of
 * class Counted (from Exercise 1) with new and
 * destroying it with delete. Also create and destroy and array of these objects on the heap
 * 
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
    Counted* countedPtr = new Counted();
    delete countedPtr;

    Counted* countedAr = new Counted[5];
    delete []countedAr;
}
