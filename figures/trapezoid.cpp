#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double Trapezoid::new_square() const {
    if (points.size() == 0)
        return 0;
    double a = sm_par.get_perimeter();
    double b = big_par.get_perimeter();
    double c = sm_side.get_perimeter();
    double d = big_side.get_perimeter();
    double p = (b - a) * (b - a) + c * c - d * d;
    p /= (2 * (b - a));
    p *= p;
    p = c * c - p;
    return ((a + b) / 2) * sqrt(p);
}

Trapezoid::Trapezoid(const std::vector <Point> &_points):Polygon(_points) {
    Polyline a({points[0], points[1]});
    Polyline b({points[2], points[3]});
    Polyline c({points[1], points[2]});
    Polyline d({points[3], points[0]});
    if (a.collinear(b) && !c.collinear(d)) {
        if (a < b) {
            sm_par = a;
            big_par = b;
        }
        else {
            sm_par = b;
            big_par = a;
        }
        if (c < d) {
            sm_side = c;
            big_side = d;
        }
        else {
            sm_side = d;
            big_side = c;
        }
    }
    else if (c.collinear(d) && !a.collinear(b)) {
        if (c < d) {
            sm_par = c;
            big_par = d;
        }
        else {
            sm_par = d;
            big_par = c;
        }
        if (a < b) {
            sm_side = a;
            big_side = b;
        }
        else {
            sm_side = b;
            big_side = a;
        }
    }
    else {
        points.resize(0);
        perimeter = 0;
        square = 0;
    }
}

Trapezoid::Trapezoid(const Point& point1, const Point& point2, const Point& point3, const Point& point4):Polygon({point1, point2, point3, point4}) {
    Trapezoid(points);
}

Trapezoid::Trapezoid(const Trapezoid& new_trapezoid):Polygon(new_trapezoid) {
    sm_par = new_trapezoid.sm_par;
    big_par = new_trapezoid.big_par;
    sm_side = new_trapezoid.sm_side;
    big_side = new_trapezoid.big_side;
}

Trapezoid& Trapezoid::operator = (const Trapezoid &new_trapezoid) {
    points.resize(new_trapezoid.points.size());
    for (int i = 0; i < new_trapezoid.points.size(); i++)
        points[i] = new_trapezoid.points[i];
    perimeter = new_trapezoid.perimeter;
    square = new_trapezoid.square;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Trapezoid &trapezoid) {
    out << "Trapezoid:";
    for (int i = 0; i < trapezoid.points.size(); i++)
        out << " " << trapezoid.points[i];
    out << " Perimetere = " << trapezoid.get_perimeter() << " Square = " << trapezoid.get_square();
    return out;
}