#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool RegularPolygon::is_regular_polygon() {
    Point a = Point(0, 0) + (points[0] - points[1]);
    Point b = Point(0, 0) + (points[0] - points[points.size() - 1]);
    side = Polyline({points[0], points[1]});
    angle = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
    for (int i = 1; i < points.size() - 1; i++)
    {
        a = Point(0, 0) + (points[i] - points[i - 1]);
        b = Point(0, 0) + (points[i] - points[i + 1]);
        double new_angle = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
        if ((length(points[i], points[i - 1]) != side.get_perimeter()) || (length(points[i], points[i + 1]) != side.get_perimeter()) || (new_angle != angle))
            return false;
    }
    return true;
}

double RegularPolygon::new_square() const {
    return (points.size() * side.get_perimeter() * side.get_perimeter()) / (4 * tan(acos(-1) / side.get_perimeter()));
}

RegularPolygon::RegularPolygon(const std::vector <Point> &_points):Polygon(_points) {
    if (!is_regular_polygon()) {
        points.resize(0);
        perimeter = 0;
        square = 0;
        angle = 0;
        side = Polyline();
    }
}

RegularPolygon::RegularPolygon(const RegularPolygon& new_rpoly):Polygon(new_rpoly) {
    side = new_rpoly.side;
    angle = new_rpoly.angle;
}

RegularPolygon& RegularPolygon::operator = (const RegularPolygon &new_rpoly) {
    points.resize(new_rpoly.points.size());
    side = new_rpoly.side;
    angle = new_rpoly.angle;
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