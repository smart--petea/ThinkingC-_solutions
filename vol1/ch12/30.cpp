/*
 * Create two classes and reate an operator+ and the
 * conversion functions such that addition is reflexive for
 * the two classes
 */

class A {};

class B 
{
    public:
        B(){}
        B(A const&) {}

        friend B operator+(B const&, B const& );
};

B operator+(B const&, B const& )
{
    return B();
}

int main()
{
    A a;
    B b;

    a + b;
    b + a;

    return 0;
}
