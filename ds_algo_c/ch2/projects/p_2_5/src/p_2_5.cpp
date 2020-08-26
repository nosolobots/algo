/*
Write a C++ program that has a Polygon interface that has abstract func-
tions, area(), and perimeter(). Implement classes for Triangle, Quadri-
lateral, Pentagon, Hexagon, and Octagon, which implement this inter-
face, with the obvious meanings for the area() and perimeter() functions.
Also implement classes, IsoscelesTriangle, EquilateralTriangle, Rectan-
gle, and Square, which have the appropriate inheritance relationships. Fi-
nally, write a simple user interface that allows users to create polygons of
the various types, input their geometric dimensions, and then output their
area and perimeter. For extra effort, allow users to input polygons by spec-
ifying their vertex coordinates and be able to test if two such polygons are
similar.
*/

#include<iostream>

#include "Coord2D.h"
#include "Polygon.h"
#include "Quadrilateral.h"

#include<vector>

using namespace std;

int main()
{
    Coord2D c1{0,0};
    Coord2D c2{2, 0};
    Coord2D c3{2, 2};
    Coord2D c4{0, 2};

    vector<Coord2D> v1{c1, c2, c3, c4};

    cout << c1 << endl;

    Quadrilateral q1(v1);
    cout << "q1: " << q1 << endl;

    Quadrilateral q2{c1, c2, c3, c4};
    cout << "q2: " << q2 << endl;
    q2[0][0] = 99;
    q2[0][1] = 99;
    cout << "q2: " << q2 << endl;

    cout << "q1 area: " << q1.area() << endl;
    cout << "q1 perimeter: " << q1.perimeter() << endl;
}
