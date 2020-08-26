#include"Polygon.h"

#include<stdexcept>

Coord2D& Polygon::operator[](size_t i)
{
    if (i<0 || i>=vlist_.size())
        throw std::out_of_range("index: " + std::to_string(i));

    return vlist_[i];
}

std::ostream &operator<<(std::ostream &os, const Polygon &p)
{
    std::cout << "{";

    for(auto it=p.vlist_.begin(); it!=p.vlist_.end(); ++it)
    {
        std::cout << *it << ", ";
    }

    std::cout << "\b\b}";

    return os;
}
