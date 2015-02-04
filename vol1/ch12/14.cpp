/*
 * Write a class called Bird that contains a string member
 * and a static int. In the default constructor, use the int to
 * automatically generate an identifier that you build in the
 * string along with the name of the class (Bird #1, Bird #2,
 * etc.). Add an operator<<for ostream to print out the Bird orbject. Write an assignment operator= and
 * a copy constructor. In main() verify that everything works correctly
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

std::string to_string(int const& x)
{
    std::ostringstream os; 
    os << x;
    return os.str();
}

class Bird
{
    private:
        static int count;
        std::string label;
    public:
        Bird() 
        {
            label = std::string("Bird ") + to_string(count++);
        };

        Bird(Bird const&) {
            //there are nothing to copy
            //I can't change the label
            label = std::string("Bird ") + to_string(count++);
        }

        friend std::ostream& operator<<(std::ostream& os, Bird const& bird)
        {
            os << bird.label;
            return os;
        }

        Bird& operator=(Bird const&)
        {
            //there are nothing to copy
            //I can't change the label
            return *this;
        }
};

int Bird::count = 0;

int main()
{
    Bird b0;
    Bird b1;
    Bird b2(b0);
    Bird b3;

    b3 = b0;

    std::cout << "b0 = " << b0 << std::endl;
    std::cout << "b1 = " << b1 << std::endl;
    std::cout << "b2 = " << b2 << std::endl;
    std::cout << "b3 = " << b3 << std::endl;

    return 0;
}
