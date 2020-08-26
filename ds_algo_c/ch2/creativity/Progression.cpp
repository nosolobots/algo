#include<iostream>

using namespace std;

class Progression
{
public:
    Progression(long f = 0)
        : first_(f), cur_(f) {}
    virtual ~Progression(){};
    void printProgression(int n);

protected:
    virtual long firstValue();
    virtual long nextValue();

protected:
    long first_;
    long cur_;
};

void Progression::printProgression(int n)
{
    cout << firstValue();
    for (int i = 2; i <= n; i++)
        cout << " " << nextValue();
    cout << endl;
}

long Progression::firstValue()
{
    cur_ = first_;
    return cur_;
}
long Progression::nextValue()
{
    return ++cur_;
}
