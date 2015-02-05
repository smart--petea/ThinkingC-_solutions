/*
 * Modify CopyingVsInitialization.cpp that all of the constructors print a message that tells you what's going on. Now
 * verify that the two forms of calls to the copy
 * constructor (the assignment form and the parenthesized
 * form) are equivalent
 */

#include <iostream>

class Fi 
{
    public:
        Fi() 
        {
            std::cout << "Fi constructor" << std::endl;
        }
};

class Fee
{
    public:
        Fee(int)
        {
            std::cout << "Fee(int)" << std::endl;
        }

        Fee(const Fi&) 
        {
            std::cout << "Fee(const Fi&)" << std::endl;
        }
};

int main()
{
    Fee fee = 1;
    Fi fi;
    Fee fum = fi;
}
