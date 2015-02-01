/*
 * Modify the above Exercise 27 so that it works with pointers to member functions instea
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define DF(N) void N() { cout << #N << endl; }

class A
{
	private:
		typedef void (A::*FooPtr)();
		typedef vector<FooPtr> FooVector;
		FooVector fooTlb;

	public:
		void add(FooPtr fooPtr) 
		{ 
			cout << "A.add()" << endl;
			fooTlb.push_back(fooPtr); 
		}

		void remove(FooPtr fooPtr)
		{
			cout << "A.remove()" << endl;

			FooVector::iterator it = find(fooTlb.begin(), fooTlb.end(), fooPtr);

			if(it == fooTlb.end()) 
			{
				cout << "Not found for remove" << endl;
			} else {
				fooTlb.erase(it);
				cout << "Removed" << endl;
			}
		}

		void run()
		{
			cout << "A.run" << endl;

			FooVector::iterator it = fooTlb.begin();
			FooVector::iterator endIt = fooTlb.end();

			for(; it != endIt; it++) (this->*(*it))();
		}

		DF(aFoo);
		DF(bFoo);
		DF(cFoo);
};


int main()
{
	void (A::*aFoo)(void) = &A::aFoo;
	void (A::*bFoo)(void) = &A::bFoo;
	void (A::*cFoo)(void) = &A::cFoo;

	A a;

	a.run();

	a.add(aFoo);
	a.add(bFoo);
	a.add(cFoo);

	a.run();

	a.remove(bFoo);

	a.run();

	return 0;
}
