/*
 * Modify Combined.cpp to add another level of
 * inheritance and a new member object. Add code to show
 * when the constructors and destructors are being called.
 */

#include <iostream>
using namespace std;

class A
{
        int i;
    public:
        A(int ii) : i(ii) 
        {
            cout << "A()" << endl;
        }
        ~A() 
        {
            cout << "~A()" << endl;
        };

        void f() const { cout << "A::f" << endl; }
};

class B
{
        int i;
    public:
        B(int ii) : i(ii) { cout << "B()" << endl; }
        ~B() { cout << "~B()" << endl; }
        void f() const { cout << "B::f" << endl; }
};

class C : public B
{
        A a;
    public:
        C(int ii) : B(ii), a(ii) { cout << "C()" << endl; }
        ~C() { cout << "~C()" << endl; } //Calls ~A() and ~B()
        void f() const
        {
            a.f();
            B::f();
            cout << "C::f" << endl;
        }
};

int main()
{
    C c(47);

    c.f();
}
