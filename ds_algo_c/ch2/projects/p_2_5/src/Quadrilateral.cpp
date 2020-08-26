#include "Quadrilateral.h"

#include<cmath>

Quadrilateral::Quadrilateral(Coord2D &v1, Coord2D &v2, Coord2D &v3, Coord2D &v4)
{
    vlist_.clear();
    vlist_.push_back(v1);
    vlist_.push_back(v2);
    vlist_.push_back(v3);
    vlist_.push_back(v4);
}

Quadrilateral::Quadrilateral(std::vector<Coord2D> &vlist)
{
    if (vlist.size()!=4)
        throw std::invalid_argument("bad number of coords: " + std::to_string(vlist.size()));

    vlist_.clear();
    for(auto it=vlist.begin(); it!=vlist.end(); ++it)
        vlist_.push_back(*it);
}

double Quadrilateral::area() const
{
    double b = Coord2D::dist(vlist_[0], vlist_[1]);
    double h = Coord2D::dist(vlist_[1], vlist_[2]);

    return b*h;
}

double Quadrilateral::perimeter() const
{
    double b = Coord2D::dist(vlist_[0], vlist_[1]);
    double h = Coord2D::dist(vlist_[1], vlist_[2]);

    return 2*b + 2*h;
}