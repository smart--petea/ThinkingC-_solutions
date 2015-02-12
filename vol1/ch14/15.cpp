/*
 * Create a class with two static member functions. Inherit
 * from this class and redefine one of the member functions.
 * Show that the other is hidden in the derived class.
 */

#include <iostream>
using namespace std;

class A
{
    public:
        static void foo1()
        {
            cout << "A::foo1" << endl;
        }

        static void foo2()
        {
            cout << "A::foo2" << endl;
        }
};

class ADerived : public A
{
    public:
        static void foo1()
        {
            cout << "ADerived::foo1" << endl;
        }

};

int main()
{
    A::foo1();
    A::foo2();
    ADerived::foo1();
    ADerived::foo2();
    return 0;
}
