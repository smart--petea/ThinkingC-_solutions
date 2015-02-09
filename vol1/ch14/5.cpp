/*
 * In Combined.cpp create a class D that inherits fro B
 * and has a member object of class C. Add code to whow 
 * when the constructors and destructors are being call
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


class D : public B
{
        C c;
    public:
        D(int ii) : B(ii), c(ii) { cout << "D()" << endl; }
        ~D() { cout << "~D()" << endl; } 
};

int main()
{
    D d(47);
}
