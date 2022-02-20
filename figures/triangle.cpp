#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double Triangle::new_square() const {
    if (points.size() == 0)
        return 0;
    double a = length(points[0], points[1]);
    double b = length(points[0], points[2]);
    double c = length(points[2], points[1]);
    double p = perimeter / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle(const std::vector <Point> &_points):Polygon(_points) {
    if (points.size() != 3) {
        points.resize(0);
        perimeter = 0;
        square = 0;
    }
}

Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3):Polygon({point1, point2, point3}) {}

Triangle::Triangle(const Triangle& new_triangle):Polygon(new_triangle) {}

Triangle& Triangle::operator = (const Triangle &new_triangle) {
    points.resize(new_triangle.points.size());
    for (int i = 0; i < new_triangle.points.size(); i++)
        points[i] = new_triangle.points[i];
    perimeter = new_triangle.perimeter;
    square = new_triangle.square;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Triangle &triangle) {
    out << "Triangle:";
    for (int i = 0; i < triangle.points.size(); i++)
        out << " " << triangle.points[i];
    out << " Perimetere = " << triangle.get_perimeter() << " Square = " << triangle.get_square();
    return out;
}