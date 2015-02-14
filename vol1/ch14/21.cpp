/*
 * Modify Instrument.cpp to add a prepare() method to
 * Instrument. Call prepare() inside tune().
 */

#include <iostream>

enum note { middleC, Csharp, Cflat };

class Instrument
{
    public:
        void play(note) const { std::cout << "Instrument::play" << std::endl; }
        void prepare() const { std::cout << "Instrument::prepare" << std::endl; }
};

//Wind objects are Instruments
//because they have the same interface
class Wind : public Instrument {};

void tune(Instrument& i)
{
    i.play(middleC);
    i.prepare();
}

int main()
{
    Wind flute;
    tune(flute);
}
