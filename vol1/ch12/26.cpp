/*
 * Modify PointerToMemberOperator.cpp by adding two
 * new member functions to Dog that take no arguments
 * and return void. Create and test an overloaded
 * operator->* that works with your two new functions.
 */

#include <iostream>
using namespace std;

class Dog
{
    public:
        int run(int i) const
        {
            cout << "run\n";
            return i;
        }

        int eat(int i) const
        {
            cout << "eat\n";
            return i;
        }

        int sleep(int i) const
        {
            cout << "ZZZ\n";
            return i;
        }


        void fly() const
        {
            cout << "fly" << endl;
        }

        void land() const
        {
            cout << "land" << endl;
        }

        typedef void (Dog::*PMV)() const;
        typedef int (Dog::*PMF)(int) const;

        class FunctionObject 
        {
                Dog* ptr;
                PMF pmem;
                PMV pvev;
            public:
                FunctionObject(Dog* wp, PMV pmv)
                    : ptr(wp), pmem(NULL), pvev(pmv)
                {
                    cout << "FunctionObject constructor with void\n";
                }

                FunctionObject(Dog* wp, PMF pmf)
                    : ptr(wp), pmem(pmf), pvev(NULL)
                {
                    cout << "FunctionObject constructor with int\n";
                }

                //Make the call using the object pointer
                //and member pointer
                int operator()(int i) const
                {
                    cout << "FunctionObject::operator(int)\n";
                    return (ptr->*pmem)(i); //Make the call
                }

                int operator()() const
                {
                    cout << "FunctionObject::operator()\n";
                    (ptr->*pvev)(); //Make the call
                }
        };

        FunctionObject operator->*(PMF pmf)
        {
            cout << "operator->* pmf" << endl;
            return FunctionObject(this, pmf);
        }

        FunctionObject operator->*(PMV pmv)
        {
            cout << "operator->* pmv" << endl;
            return FunctionObject(this, pmv);
        }
};

int main()
{
    Dog w;

    Dog::PMF pmf = &Dog::run;
    cout << (w->*pmf)(1) << endl;

    pmf = &Dog::sleep;
    cout << (w->*pmf)(2) << endl;

    pmf = &Dog::eat;
    cout << (w->*pmf)(3) << endl;

    Dog::PMV pvv = &Dog::fly;
    (w->*pvv)();

    pvv = &Dog::land;
    (w->*pvv)();
}
