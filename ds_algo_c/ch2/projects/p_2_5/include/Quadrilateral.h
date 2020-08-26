#ifndef _QUADRILATERAL_H_
#define _QUADRILATERAL_H_

#include<vector>
#include<stdexcept>
#include "Polygon.h"

class Quadrilateral: public Polygon
{
public:
    Quadrilateral(Coord2D &v1, Coord2D &v2, Coord2D &v3, Coord2D &v4);
    Quadrilateral(std::vector<Coord2D> &vlist);
    ~Quadrilateral() = default;
    virtual double area() const;
    virtual double perimeter() const;
};

#endif