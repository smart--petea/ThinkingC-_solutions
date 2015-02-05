/*
 * Attempt to create a non-member operator= for a class
 * and see what kind of compiler message you get
 */

class A
{
    public:
        /*
         //error message: ‘A& operator=(A&, const A&)’ must be a nonstatic member function
        friend A& operator=(A& a, A const& b)
        {
            return a;
        }
        */

        A& operator=(A const& b)
        {
            return *this;
        }
};

int main()
{
    A a;
    A b;

    a = b;

    return 0;
}
