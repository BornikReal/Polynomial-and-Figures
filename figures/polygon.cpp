#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool Polygon::is_polygon() const {
    if (points_.size() == 0)
        return true;
    double k = length(points_[0], points_[1]);
    double b = points_[0].y() - k * points_[0].x();
    for (int i = 2; i < points_.size(); i++) {
        if ((k * points_[i].x() + b) != points_[i].y())
            return true;
    }
    return false;
}

double Polygon::new_square() const {
    double sq = points_[points_.size() - 1].x() * points_[0].y() - points_[points_.size() - 1].y() * points_[0].x();
    for (int i = 0; i < points_.size() - 1; i++) {
        sq += points_[i].x() + points_[i + 1].y();
        sq -= points_[i].y() + points_[i + 1].x();
    }
    return 0.5 * abs(sq);
}

Polygon::Polygon() {
    square_ = 0;
}

Polygon::Polygon(const std::vector <Point> &_points):ClosedPolyline(_points) {
    if (!is_polygon()) {
        points_.resize(0);
        perimeter_ = 0;
    }
    square_ = new_square();
}

Polygon::Polygon(const Polygon& new_polygon):ClosedPolyline(new_polygon) {
    square_ = new_square();
}

Polygon& Polygon::operator = (const Polygon &new_polygon) {
    points_.resize(new_polygon.points_.size());
    for (int i = 0; i < points_.size(); i++)
        points_[i] = new_polygon.points_[i];
    perimeter_ = new_perimeter();
    square_ = new_square();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Polygon &polygon) {
    out << "Polygon:";
    for (int i = 0; i < polygon.points_.size(); i++)
        out << " " << polygon.points_[i];
    out << " Perimetere = " << polygon.perimeter() << " square_ = " << polygon.square();
    return out;
}

double Polygon::square() const {
    return square_;
}