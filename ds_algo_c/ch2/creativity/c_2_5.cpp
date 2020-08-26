/*  
Write a C++ class that is derived from the Progression class to produce a
progression where each value is the absolute value of the difference be-
tween the previous two values. You should include a default constructor
that starts with 2 and 200 as the first two values and a parametric construc-
tor that starts with a specified pair of numbers as the first two values.
*/
#include<iostream>
#include<cstdlib>

#include "Progression.cpp"

using namespace std;

class AbsDiff: public Progression
{
  public:
    AbsDiff();
    AbsDiff(long f, long s);

  protected:
    virtual long firstValue();
    virtual long nextValue();

  private:
    long second_;
    long prev_;
};

AbsDiff::AbsDiff(): AbsDiff(2, 200){}

AbsDiff::AbsDiff(long f, long s): Progression(f), second_(s), prev_(first_ + second_) {}

// reset
long AbsDiff::firstValue()
{
    cur_ = first_;
    prev_ = first_ + second_;
    return cur_;
}

// advance
long AbsDiff::nextValue()
{
    long temp = prev_;
    prev_ = cur_;
    cur_ = abs(cur_ - temp);
    return cur_;
}

int main()
{
    AbsDiff p1;
    AbsDiff p2(25, 50);

    cout << "First 10 values of p1:" << endl;
    p1.printProgression(10);

    cout << "First 10 values of p2(25, 50):" << endl;
    p2.printProgression(10);

    return EXIT_SUCCESS;
}