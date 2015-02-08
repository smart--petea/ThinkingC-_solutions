/*
 * Create a class with an overloaded operator new and
 * delete, both the single-object versions and the array
 * versions. Demonstrate that both versions work.
 */

#include <iostream>
#include <cstdlib>

class A
{
        static int count;
        int x;
    public:
        A() : x(++count) 
        {
            std::cout << "A(" << x << ")" << std::endl;
        }

        ~A()
        {
            std::cout << "~A(" << x << ")" << std::endl;
        }

        void operator delete(void *m)
        {
            std::cout << "delete operator" << std::endl;
            free(m);
        }

        void operator delete[](void *m) 
        {
            std::cout << "delete operator[]" << std::endl;
            free(m);
        }

        void* operator new(std::size_t sz)
        {
            std::cout << "allocate memory" << std::endl;
            return malloc(sz);
        }

        void* operator new[](std::size_t sz)
        {
            std::cout << "allocate memory[]" << std::endl;
            return malloc(sz);
        }

        void print() const
        {
            std::cout << "x = " << x << std::endl;
        }
};

int A::count = 0;

int main()
{
    A* aPtr = new A;

    aPtr->print();
    delete aPtr;

    aPtr = new A[20];
    aPtr[5].print();
    delete[] aPtr;

    return 0;
}
