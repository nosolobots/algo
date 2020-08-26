#include "Coord2D.h"

#include<iostream>
#include<stdexcept>
#include<cmath>

Coord2D &Coord2D::operator=(const Coord2D &c)
{
    x_ = c.x_;
    y_ = c.y_;
    return *this;
}

double& Coord2D::operator[](int i)
{
    if(i<0 || i>1)
        throw std::out_of_range("index: " + std::to_string(i));
    
    return (i==0? x_: y_);    
}

double Coord2D::dist(const Coord2D &c1, const Coord2D &c2)
{
    return std::sqrt(std::pow(c2.x_-c1.x_,2) + std::pow(c2.y_-c1.y_, 2));
}

std::ostream& operator<<(std::ostream &os, const Coord2D &c)
{
    std::cout << "[" << c.x_ << ", " << c.y_ << "]";

    return os;
}