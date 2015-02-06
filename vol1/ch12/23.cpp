/*
 * In ReferenceCounting.cpp add a static int and an
 * ordinary int as data members to both Dog and
 * DogHouse. In all constructors for both classes, increment
 *the static int and assign the result to the ordinary int to
 keep track of the number of objects that have been
 created. Make the necessary modifications so that all the
 prining statements will say the int identifiers of the
 objects involved.
 */

#include <string>
#include <iostream>
using namespace std;

class Dog 
{
        static int staticCount;
        string nm;
        int refcount;
        int number;

        Dog(const string& name) : nm(name), refcount(1), number(++staticCount)
        {
            cout << "Creating Dog: " << *this << endl;
        }

        //Prevent assignment:
        Dog& operator=(const Dog& rv);
    public:
        //Dogs can only be created on the heap:
        static Dog* make(const string& name)
        {
            return new Dog(name);
        }

        Dog(const Dog& d) : nm(d.nm + " copy"), refcount(1), number(++staticCount)
        {
            cout << "Dog copy-constructor: " << *this << endl;
        }

        ~Dog()
        {
            cout << "Deleting Dog: " << *this << endl;
        }

        void attach()
        {
            ++refcount;
        }

        void detach() 
        {
            cout << "Detaching Dog: "  << *this << endl;
            if(--refcount == 0) delete this;
        }

        //Conditionally copy this Dog.
        //Call before modifying the Dog, assign
        //resulting pointer to your Dog*
        Dog* unalias()
        {
            cout << "Unalizsing Dog: " << *this << endl;
            //Don't duplicate if not aliased;

            if(refcount == 1) return this;
            --refcount;

            //Use copy-constructor to duplicate
            return new Dog(*this);
        }

        void rename(const string& newName)
        {
            nm = newName;
            cout << "Dog renamed to: " << *this << endl;
        }

        friend ostream& operator<<(ostream& os, const Dog& d)
        {
            return os << "[" << d.nm << "], rc = " << d.refcount << " order = " << d.number;
        }
};

int Dog::staticCount = 0;

class DogHouse 
{
        Dog* p;
        string houseName;
    public:
        DogHouse(Dog* dog, const string& house) : p(dog), houseName(house)
        {
            cout << "Created DogHouse: "  << *this << endl;
        }

        DogHouse(const DogHouse& dh) 
            : p(dh.p) ,
                houseName("copy-constructed " + dh.houseName)
        {
            p->attach(); 
            cout << "DogHouse copy-constructor: " << *this << endl;
        }

        DogHouse& operator=(const DogHouse& dh)
        {
            //check for self-assignment:
            if(&dh != this) 
            {
                houseName = dh.houseName + " assigned";
                //clean up what you're using first
                p->detach();
                p = dh.p; //Like copy-constructor
                p->attach();
            }

            cout << "DogHouse operator= : " << *this << endl;

            return *this;
        }

        //Decrement refcount, conditionally destroy
        ~DogHouse()
        {
            cout << "DogHouse desctructor: " << *this << endl;
            p->detach();
        }

        void renameHouse(const string& newName)
        {
            houseName = newName;
        }

        void unalias() { p = p->unalias(); }

        //Copy-on-write. Anytime you modify the
        //contents of the pointer you must
        //first unalias it

        void renameDog(const string& newName)
        {
            unalias();
            p->rename(newName);
        }

        Dog* getDog()
        {
            unalias();
            return p;
        }

        friend ostream& operator<<(ostream& os, const DogHouse& dh)
        {
            return os << "[" << dh.houseName << "] contains " << *dh.p;
        }
};

int main()
{
    DogHouse fidos(Dog::make("Fido"), "FidoHouse"),
             spots(Dog::make("Spot"), "SpotHouse");

    cout << "Entering copy-construction" << endl;
    DogHouse bobs(fidos);

    cout << "After copy-constructing bobs" << endl;
    cout << "fidos: " << fidos << endl;
    cout << "spots: " << spots << endl;
    cout << "bobs: " << bobs << endl;
    cout << "Entering spots = fidos" << endl;
    spots = fidos;
    cout << "After spots = fidos" << endl;
    cout << "spots: " << spots << endl;
    cout << "Entering self-assignment" << endl;
    bobs = bobs;
    cout << "After self-assignment" << endl;
    cout << "bobs: " << bobs << endl;
    //Comment out the following lines:
    cout << "Entering rename(\"Bob\")" << endl;
    bobs.getDog()->rename("Bob");
    cout << "After rename(\"Bob\")" << endl;
}
