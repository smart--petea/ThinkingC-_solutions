/*
 * In CopyConstructor.cpp inherit a new class from Child
 * and give it a Memberm. write a proper constructor
 * copy-constructor, operator=, and operator<< for
 * ostreams, and test the class in main()
 */

#include <iostream>
using namespace std;

class Parent
{
        int i;
    public:
        Parent(int ii) : i(ii)
        {
            cout << "Parent(int ii)\n";
        }

        Parent(const Parent& b) : i(b.i)
        {
            cout << "Parent(const Parent&)\n";
        }

        Parent() : i(0) { cout <<"Parent()\n"; }

        friend ostream& operator<<(ostream& os, const Parent& b)
        {
            return os << "Parent: " << b.i << endl;
        }
};

class Member
{
        int i;
    public:
        Member(int ii) : i(ii)
        {
            cout << "Member(int ii)\n";
        }

        Member(const Member& m) : i(m.i)
        {
            cout << "Member(const Member&)\n";
        }

        friend ostream& operator<<(ostream& os, const Member& m)
        {
            return os << "Member: " << m.i << endl;
        }
};

class Child : public Parent 
{
        int i;
        Member m;
    public:
        Child(int ii) : Parent(ii), i(ii), m(ii)
        {
            cout << "Child(int ii)\n";
        }

        friend ostream& operator<<(ostream& os, const Child& c)
        {
            return os << (Parent&)c << c.m << "Child: " << c.i << endl;
        }
};

class Memberm : public Child
{
    public:
        Memberm() : Child(0) 
        {
            cout << "Memberm::Memberm()" << endl;
        }

        Memberm(Memberm const& mb) : Child(mb)
        {
            cout << "Memberm::Memberm(Memberm const& mb)" << endl;
        }

        Memberm& operator=(Memberm const& mb)
        {
            cout << "Memberm::operator="<< endl;
            Child::operator=((Child&)mb);

            return *this;
        }

        friend ostream& operator<<(ostream& os, Memberm const& mb)
        {
            cout << "Memberm::operator<<" << endl;
            return os << (Child&) mb;
        }
};

int main()
{
    /*
    Child c(2);
    cout << "calling copy-constructor: " << endl;
    Child c2 = c; //Calls copy-constructor
    cout << "values in c2: \n" << c2;
    */

    Memberm mb; //constructor
    Memberm mb1 = mb; //copyconstructor

    cout << mb1 << endl; //operator<<
    
    mb = mb1; //operator= 
}
