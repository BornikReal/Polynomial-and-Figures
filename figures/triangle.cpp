#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double Triangle::new_square() const {
    if (points_.size() == 0)
        return 0;
    double a = length(points_[0], points_[1]);
    double b = length(points_[0], points_[2]);
    double c = length(points_[2], points_[1]);
    double p = perimeter_ / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle(const std::vector <Point> &_points):Polygon(_points) {
    if (points_.size() != 3) {
        points_.resize(0);
        perimeter_ = 0;
        square_ = 0;
    }
}

Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3):Polygon({point1, point2, point3}) {}

Triangle::Triangle(const Triangle& new_triangle):Polygon(new_triangle) {}

Triangle& Triangle::operator = (const Triangle &new_triangle) {
    points_.resize(new_triangle.points_.size());
    for (int i = 0; i < new_triangle.points_.size(); i++)
        points_[i] = new_triangle.points_[i];
    perimeter_ = new_triangle.perimeter_;
    square_ = new_triangle.square_;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Triangle &triangle) {
    out << "Triangle:";
    for (int i = 0; i < triangle.points_.size(); i++)
        out << " " << triangle.points_[i];
    out << " Perimetere = " << triangle.perimeter() << " square_ = " << triangle.square();
    return out;
}