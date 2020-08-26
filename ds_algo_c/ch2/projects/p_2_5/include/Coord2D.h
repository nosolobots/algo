#ifndef _COORD_2D_
#define _COORD_2D_

#include<iostream>

class Coord2D
{
public:
    Coord2D():x_(0), y_(0) {}
    Coord2D(const double& x, const double& y): x_(x), y_(y) {}
    Coord2D(const Coord2D &c) : x_(c.x_), y_(c.y_){}
    Coord2D& operator=(const Coord2D& c);
    double& operator[](int i);

    double x() const { return x_; }
    double y() const { return y_; }

    static double dist(const Coord2D& c1, const Coord2D& c2);

    friend std::ostream &operator<<(std::ostream &os, const Coord2D &c);

private : 
    double x_;
    double y_;
};

#endif