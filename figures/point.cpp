#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

Point::Point() {
    _x = 0;
    _y = 0;
}

Point::Point(double x, double y) {
    _x = x;
    _y = y;
}

Point::Point(const Point &new_point) {
    _x = new_point._x;
    _y = new_point._y;
}

Point& Point::operator = (const Point &new_point) {
    _x = new_point._x;
    _y = new_point._y;
    return *this;
}

bool Point::operator == (const Point& point) const {
    if ((_x == point._x) && (_y == point._y))
        return true;
    return false;
}

bool Point::operator != (const Point& point) const {
    if ((_x == point._x) && (_y == point._y))
        return false;
    return true;
}

Point& Point::operator += (const Polyline &poly) {
    Point point1 = poly.points[0], point2 = poly.points[poly.points.size() - 1];
    _x += point2._x - point1._x; _y += point2._y - point1._y;
    return *this;
}

Point& Point::operator -= (const Polyline &poly) {
    Point point1 = poly.points[0], point2 = poly.points[poly.points.size() - 1];
    _x = point2._x + point1._x - _x; _y = point2._y + point1._y - _y;
    return *this;
}

Point Point::operator + (const Polyline &poly) const {
    Point point1 = poly.points[0], point2 = poly.points[poly.points.size() - 1];
    return Point(point2._x - point1._x + _x, point2._y - point1._y + _y);
}

Point Point::operator - (const Polyline &poly) const {
    Point point1 = poly.points[0], point2 = poly.points[poly.points.size() - 1];
    return Point(point2._x + point1._x - _x, point2._y + point1._y - _y);
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "Point {" << point._x << ", " << point._y << "}";
    return out;
}

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}

double length(const Point& point1, const Point& point2) {
    return sqrt((point1._x - point2._x) * (point1._x - point2._x) + (point1._y - point2._y) * (point1._y - point2._y));
}