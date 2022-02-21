#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

void Polyline::fix() {
    int i = 1;
    while (i < points.size()) {
        if (points[i] == points[i - 1])
            points.erase(points.begin() + i);
        else
            i++;
    }
}

double Polyline::new_perimeter() const {
    double len = 0;
    for (int i = 1; i < points.size(); i++)
        len += length(points[i], points[i - 1]);
    return len;
}

Polyline::Polyline() {
    perimeter = 0;
}

Polyline::Polyline(const std::vector <Point> &_points) {
    for (int i = 0; i < _points.size(); i++)
        points.push_back(_points[i]);
    fix();
    if (_points.size() <= 1)
        points.resize(0);
}

Polyline::Polyline(const Polyline &new_polyline) {
    for (int i = 0; i < new_polyline.points.size(); i++)
        points.push_back(new_polyline.points[i]);
}

Polyline& Polyline::operator = (const Polyline &new_polyline) {
    points.resize(new_polyline.points.size());
    for (int i = 0; i < points.size(); i++)
        points[i] = new_polyline.points[i];
    return *this;
}

bool Polyline::operator == (const Polyline& poly) const {
    if (points.size() != poly.points.size())
        return false;
    for (int i = 0; i < points.size(); i++)
        if (points[i] != poly.points[i])
            return false;
    return true;
}

bool Polyline::operator != (const Polyline& poly) const {
    if (points.size() != poly.points.size())
        return true;
    for (int i = 0; i < points.size(); i++)
        if (points[i] != poly.points[i])
            return true;
    return false;
}

bool Polyline::operator > (const Polyline &poly) const {
    if (perimeter > poly.perimeter)
        return true;
    return false;
}

bool Polyline::operator >= (const Polyline &poly) const {
    if (perimeter >= poly.perimeter)
        return true;
    return false;
}

bool Polyline::operator < (const Polyline &poly) const {
    if (perimeter < poly.perimeter)
        return true;
    return false;
}

bool Polyline::operator <= (const Polyline &poly) const {
    if (perimeter <= poly.perimeter)
        return true;
    return false;
}

Point& Polyline::operator [] (int pos) {
    return points[pos];
}

std::ostream &operator<<(std::ostream &out, const Polyline &poly) {
    out << "Polyline:";
    for (int i = 0; i < poly.points.size(); i++)
        out << " " << poly.points[i];
    return out;
}

int Polyline::size() const {
    return points.size();
}

bool Polyline::collinear(const Polyline& poly) const {
    for (int i = 1; i < points.size(); i++) {
        if ((points[i]._x / points[i - 1]._x) != (points[i]._y / points[i - 1]._y))
            return false;
    }
    return true;
}

double Polyline::get_perimeter() const {
    return perimeter;
}

Polyline operator - (const Point &point1, const Point &point2) {
    if (point2 == point1)
        return Polyline({point1});
    Polyline new_poly({point2, point1});
    return new_poly;
}