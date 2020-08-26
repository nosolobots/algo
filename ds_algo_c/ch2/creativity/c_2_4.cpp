/*
Design a class Line that implements a line, which is represented by the for-
mula y = ax + b. Your class should store a and b as double member vari-
ables. Write a member function intersect(l) that returns the x coordinate
at which this line intersects line l. If the two lines are parallel, then your
function should throw an exception Parallel. Write a C++ program that
creates a number of Line objects and tests each pair for intersection. Your
program should print an appropriate error message for parallel lines.
*/

#include<iostream>
#include<exception>

using namespace std;

class Line
{
  public:
    Line(double a, double b): a_(a), b_(b) {};
    double intersec(const Line &l) const;

private:
    double a_;
    double b_;
};

class Parallel: public exception
{
  public:
    const char *what() const noexcept { return "The two lines are parallel!"; }
};

double Line::intersec(const Line &l) const
{
    if(a_ == l.a_)
        throw Parallel();

    return (l.b_ - b_)/(a_ - l.a_);
}

int main()
{
    Line l1(1, 0);
    Line l2(-1, 2);
    Line l3(1, 5);

    try
    {
        cout << "l1 instersects l2 in x = " << l1.intersec(l2) << endl;
        cout << "l1 instersects l3 in x = " << l1.intersec(l3) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << endl << e.what() << '\n';
    }
    
    return EXIT_SUCCESS;
}