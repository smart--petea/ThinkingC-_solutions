/*
 * Modify Car.cpp so that it also inherits from a class called 
 * Vehicle placing appropriate member functions in
 * Vehicle (that is, make up some member funcitons). Add
 * a nondefault constructor to Vehicle, which you must call
 * inside Car's constructor.
 */

#include <iostream>

class Engine
{
    public:
        void start() const {}
        void rev() const {}
        void stop() const {}
};

class Wheel
{
    public:
        void inflate(int psi) const {}
};

class Window
{
    public:
        void rollup() const {}
        void rolldown() const {}
};

class Door
{
    public:
        Window window;
        void open() const {};
        void close() const {};
};

class Vehicle
{
    private: 
        int registerNumber;

    public:
        Vehicle() : registerNumber(0) {};
        Vehicle(int r) : registerNumber(r) {};

        int getRegisterNumber() const { return registerNumber; }
};

class Car : public Vehicle
{
    public: 
        Car(int regNumber) : Vehicle(regNumber) {};

        Engine engine;
        Wheel wheel[4];

        Door left, right; //2 - door
};

int main()
{
    Car car(20);
    car.left.window.rollup();
    car.wheel[0].inflate(72);

    std::cout << "register number = " << car.getRegisterNumber() << std::endl;
}
