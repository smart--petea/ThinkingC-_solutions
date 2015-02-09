/*
 * Create a three-level hierarchy of classes with default
 * constructors, along with destructors, both of which
 * announce themselves to cout. verify that for an object of
 * the most derived type, all three constructor and
 * destructors are automatically called. Explain the order in which the calls
 * are made.
 */

#include <iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << "A()" << endl;
        }

        ~A()
        {
            cout << "~A()" << endl;
        }
};

class B : public A
{
    public:
        B()
        {
            cout << "B()" << endl;
        }

        ~B()
        {
            cout << "~B()" << endl;
        }
};

class C : public B
{
    public:
        C()
        {
            cout << "C()" << endl;
        }

        ~C()
        {
            cout << "~C()" << endl;
        }
};

int main()
{
    C c;

    return 0;
}
