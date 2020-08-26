#ifndef _POLYGON_H_
#define _POLYGON_H_

#include<vector>
#include<iostream>

#include"Coord2D.h"

class Polygon
{
public:
    virtual ~Polygon() {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    Coord2D& operator[](size_t i);

    friend std::ostream& operator<<(std::ostream& os, const Polygon& p);

protected:
    std::vector<Coord2D> vlist_;
};

#endif