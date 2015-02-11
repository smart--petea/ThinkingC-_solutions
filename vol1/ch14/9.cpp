/*
 * Inherit a class StringVector from vector<void*> and
 * redefine the push_back() and operator[] member
 * functions to accept and produce string*. What happens if
 * you try to push_back() a void*
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class StringVector : public vector<void*>
{
    public:
        void push_back(string* st)
        {
            cout << "push_back" << endl;
            vector<void*>::push_back(st);
        }

        string* operator[](const int& index) const
        {
            cout << "operator[]" << endl;
            return (string *)vector<void*>::operator[](index);
        }
};

int main()
{
    StringVector strVector;
    string a("primul");
    string b("doilea");

    strVector.push_back(&a);
    strVector.push_back(&b);

    cout << "strVector[0] = " << *strVector[0] << endl;
    cout << "strVector[1] = " << *strVector[1] << endl;
}
