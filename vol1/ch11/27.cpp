/*
 * Start with FunctionTable.cpp from Chapter 3. Create a
 * class that contains a vector of pointers to functions, with
 * add() and remove() mbember functions to add and remove pointers to functions. Add a run() function that
 * moves through the vector and calls all of the functions
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class A
{
	private:
		typedef void (*FooPtr)();
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

			for(; it != endIt; it++) (*it)();
		}
};

#define DF(N) void N() { cout << #N << endl; }
DF(aFoo);
DF(bFoo);
DF(cFoo);

int main()
{
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
