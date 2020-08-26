/*
Write a C++ class that is derived from the Progression class to produce
a progression where each value is the square root of the previous value.
(Note that you can no longer represent each value with an integer.) You
should include a default constructor that starts with 65, 536 as the first
value and a parametric constructor that starts with a specified (double)
number as the first value.
*/

#include<iostream>
#include<cmath>

#include"Progression.cpp"

using namespace std;

class SqrProg: public Progression
{
  public:
    SqrProg(): Progression(65536) {}
    SqrProg(long f): Progression(f) {}

  protected:
    virtual long nextValue();
};

long SqrProg::nextValue()
{
    cur_ = static_cast<long> (sqrt(cur_));
    
    return cur_;
}

int main()
{
    SqrProg p1;
    SqrProg p2(10000L);

    cout << "First 8 values of p1:" << endl;
    p1.printProgression(8);

    cout << "First 8 values of p2(10000):" << endl;
    p2.printProgression(8);

    return EXIT_SUCCESS;
}