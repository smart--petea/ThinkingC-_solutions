/*
 * Create two classes called Traveler and Pager without
 * default constructors, but with constructors that take an
 * argument of type string which they simply copy to an i
 * internal string variable. For each class, write the correct
 * copy-constructor and assignment operator. Now inherit a
 * class BusinessTraveler from Traveler and give it a
 * member object of type Pager. Write the correct default
 * constructor, a constructor that takes a string argument, a
 * copyt-constructor, and an assignment operator.
 */

#include <string>
using namespace std;

class Traveler
{
        string strX;
    public:
        Traveler(string  strX_) : strX(strX_) {};

        Traveler(Traveler const& tr) : strX(tr.strX) {};

        Traveler& operator=(Traveler const& tr) 
        {
            strX = tr.strX;

            return *this;
        }
};

class Pager
{
        string strX;
    public:
        Pager(string strX_) : strX(strX_) {};

        Pager(Pager const& pr) : strX(pr.strX) {};

        Pager& operator=(Pager const& tr)
        {
            strX = tr.strX;

            return *this;
        }
};

class BusinessTraveler : public Traveler
{
        Pager pager;
    public:
        BusinessTraveler(string sX) : pager(sX), Traveler(sX) {}
        BusinessTraveler& operator=(BusinessTraveler const& bt)
        {
            pager = bt.pager;

            return *this;
        }
};

int main()
{
    BusinessTraveler bt1(string("unu"));
    BusinessTraveler bt2(string("doi"));

    bt1 = bt2;

    return 0;
}
