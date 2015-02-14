/*
 * Create a class called SpaceShip with a fly() method.
 * Inherit Shuttle from SpaceShip and add a land()
 * method. create a new Shuttle upcast by pointer or reference to a
 * SpaceShip and try to call the land()
 * method. explain the results.
 */

#include <iostream>

class SpaceShip
{
    public:
        void fly()
        {
            std::cout << "SpaceShipe::fly()" << std::endl;
        }
};

class Shuttle : public SpaceShip
{
    public:
        void land()
        {
            std::cout << "Shuttle::land()" << std::endl;
        }
};


int main()
{
    SpaceShip* ss = (SpaceShip*) new Shuttle();
    //! ss->land(); //not member

    return 0;
}
