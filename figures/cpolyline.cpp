#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double CPolyline::new_perimeter() const {
    double len = length(points[0], points[points.size() - 1]);
    for (int i = 1; i < points.size(); i++)
        len += length(points[i], points[i - 1]);
    return len;
}

CPolyline::CPolyline(const std::vector <Point> &_points):Polyline(_points) {
    if (_points.size() <= 2)
        points.resize(0);
    perimeter = new_perimeter();
}

CPolyline::CPolyline(const CPolyline& cpolyline):Polyline(cpolyline) {
    perimeter = new_perimeter();
}

CPolyline& CPolyline::operator = (const CPolyline &new_cpolyline) {
    points.resize(new_cpolyline.points.size());
    for (int i = 0; i < points.size(); i++)
        points[i] = new_cpolyline.points[i];
    perimeter = new_perimeter();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const CPolyline &cpoly) {
    out << "Closed polyline:";
    for (int i = 0; i < cpoly.points.size(); i++)
        out << " " << cpoly.points[i];
    out << " Perimetere = " << cpoly.get_perimeter();
    return out;
}