#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double ClosedPolyline::new_perimeter() const {
    double len = length(points_[0], points_[points_.size() - 1]);
    for (int i = 1; i < points_.size(); i++)
        len += length(points_[i], points_[i - 1]);
    return len;
}

ClosedPolyline::ClosedPolyline(const std::vector <Point> &_points):Polyline(_points) {
    if (_points.size() <= 2)
        points_.resize(0);
    perimeter_ = new_perimeter();
}

ClosedPolyline::ClosedPolyline(const ClosedPolyline& cpolyline):Polyline(cpolyline) {
    perimeter_ = new_perimeter();
}

ClosedPolyline& ClosedPolyline::operator = (const ClosedPolyline &new_cpolyline) {
    points_.resize(new_cpolyline.points_.size());
    for (int i = 0; i < points_.size(); i++)
        points_[i] = new_cpolyline.points_[i];
    perimeter_ = new_perimeter();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ClosedPolyline &cpoly) {
    out << "Closed polyline:";
    for (int i = 0; i < cpoly.points_.size(); i++)
        out << " " << cpoly.points_[i];
    out << " Perimetere = " << cpoly.perimeter();
    return out;
}