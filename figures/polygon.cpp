#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool Polygon::is_polygon() const {
    if (points.size() == 0)
        return true;
    double k = length(points[0], points[1]);
    double b = points[0].y() - k * points[0].x();
    for (int i = 2; i < points.size(); i++) {
        if ((k * points[i].x() + b) != points[i].y())
            return true;
    }
    return false;
}

double Polygon::new_square() const {
    double sq = points[points.size() - 1].x() * points[0].y() - points[points.size() - 1].y() * points[0].x();
    for (int i = 0; i < points.size() - 1; i++) {
        sq += points[i].x() + points[i + 1].y();
        sq -= points[i].y() + points[i + 1].x();
    }
    return 0.5 * abs(sq);
}

Polygon::Polygon() {
    square = 0;
}

Polygon::Polygon(const std::vector <Point> &_points):CPolyline(_points) {
    if (!is_polygon()) {
        points.resize(0);
        perimeter = 0;
    }
    square = new_square();
}

Polygon::Polygon(const Polygon& new_polygon):CPolyline(new_polygon) {
    square = new_square();
}

Polygon& Polygon::operator = (const Polygon &new_polygon) {
    points.resize(new_polygon.points.size());
    for (int i = 0; i < points.size(); i++)
        points[i] = new_polygon.points[i];
    perimeter = new_perimeter();
    square = new_square();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Polygon &polygon) {
    out << "Polygon:";
    for (int i = 0; i < polygon.points.size(); i++)
        out << " " << polygon.points[i];
    out << " Perimetere = " << polygon.get_perimeter() << " Square = " << polygon.get_square();
    return out;
}

double Polygon::get_square() const {
    return square;
}