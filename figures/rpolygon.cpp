#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool RegularPolygon::is_regular_polygon() const {
    Point a = Point(0, 0) + (points[0] - points[1]);
    Point b = Point(0, 0) + (points[0] - points[points.size()]);
    double len = length(points[0], points[1]);
    double angle = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
    for (int i = 1; i < points.size() - 1; i++)
    {
        a = Point(0, 0) + (points[i] - points[i - 1]);
        b = Point(0, 0) + (points[i] - points[i + 1]);
        double new_angle = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
        if ((length(points[i], points[i - 1]) != len) || (length(points[i], points[i + 1]) != len) || (new_angle != angle))
            return false;
    }
    return true;
}

RegularPolygon::RegularPolygon(const std::vector <Point> &_points):Polygon(_points) {
    if (!is_regular_polygon()) {
        points.resize(0);
        perimeter = 0;
        square = 0;
    }
}

RegularPolygon::RegularPolygon(const RegularPolygon& new_rpoly):Polygon(new_rpoly) {}

RegularPolygon& RegularPolygon::operator = (const RegularPolygon &new_rpoly) {
    points.resize(new_rpoly.points.size());
    for (int i = 0; i < points.size(); i++)
        points[i] = new_rpoly.points[i];
    perimeter = new_perimeter();
    square = new_square();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const RegularPolygon &rpolygon) {
    out << "Right polygon:";
    for (int i = 0; i < rpolygon.points.size(); i++)
        out << " " << rpolygon.points[i];
    out << " Perimetere = " << rpolygon.get_perimeter() << " Square = " << rpolygon.get_square();
    return out;
}