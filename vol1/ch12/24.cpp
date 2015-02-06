/*
 * Create a class containing a string as a data member.
 * Initialize the string in the constructor, but do not create a 
 * copy-constructor or operator=. Make a second class that
 * has a mbember object of your first class; do not create a 
 * copy-constructor or operator= for this class either.
 * Demonstrate that the copy-constructor and operator= are
 * properly sinthesized by the compiler
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string to_string(int const& i) {
    ostringstream os;
    os << i;
    return os.str();
}

class A
{
        static int count;
        string x_;
    public:
        A() : x_(to_string(++count))
        {
            cout << "A(" << x_ << ")" << endl;
        }

        A(A const&) : x_(to_string(++count))
        {
            cout << "A(A const&)" << endl;
        }

        ~A()
        {
            cout << "~A(" << x_ << ")" << endl;
        }
};

int A::count = 0;

class AContainer
{
        A a_;
        string name_;
    public:
        AContainer(string name) : name_(name)
        {
            cout << "AContainer(" << name_ << ")" << endl;
        }

        ~AContainer()
        {
            cout << "~AContainer(" << name_ << ")" << endl;
        }
};

int main()
{
    cout << endl << "Create aContainer" << endl;
    AContainer aContainer("a");

    cout << endl << "Create bContainer" << endl;
    AContainer bContainer("b");

    cout << endl << "Create cContainer(bContainer)" << endl;
    AContainer cContainer(bContainer);

    cout << endl << "cContainer = aContainer" << endl;
    cContainer = aContainer;

    cout << endl << "Create dContainer" << endl;
    AContainer dContainer("d");
    return 0;
}
