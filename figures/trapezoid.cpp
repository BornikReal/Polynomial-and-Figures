#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double Trapezoid::new_square() const {
    if (points_.size() == 0)
        return 0;
    double a = sm_par_.perimeter();
    double b = big_par_.perimeter();
    double c = sm_side_.perimeter();
    double d = big_side_.perimeter();
    double p = (b - a) * (b - a) + c * c - d * d;
    p /= (2 * (b - a));
    p *= p;
    p = c * c - p;
    return ((a + b) / 2) * sqrt(p);
}

Trapezoid::Trapezoid(const std::vector <Point> &_points):Polygon(_points) {
    Polyline a({points_[0], points_[1]});
    Polyline b({points_[2], points_[3]});
    Polyline c({points_[1], points_[2]});
    Polyline d({points_[3], points_[0]});
    if (a.collinear(b) && !c.collinear(d)) {
        if (a < b) {
            sm_par_ = a;
            big_par_ = b;
        }
        else {
            sm_par_ = b;
            big_par_ = a;
        }
        if (c < d) {
            sm_side_ = c;
            big_side_ = d;
        }
        else {
            sm_side_ = d;
            big_side_ = c;
        }
    }
    else if (c.collinear(d) && !a.collinear(b)) {
        if (c < d) {
            sm_par_ = c;
            big_par_ = d;
        }
        else {
            sm_par_ = d;
            big_par_ = c;
        }
        if (a < b) {
            sm_side_ = a;
            big_side_ = b;
        }
        else {
            sm_side_ = b;
            big_side_ = a;
        }
    }
    else {
        points_.resize(0);
        perimeter_ = 0;
        square_ = 0;
    }
}

Trapezoid::Trapezoid(const Point& point1, const Point& point2, const Point& point3, const Point& point4):Polygon({point1, point2, point3, point4}) {
    Trapezoid(points_);
}

Trapezoid::Trapezoid(const Trapezoid& new_trapezoid):Polygon(new_trapezoid) {
    sm_par_ = new_trapezoid.sm_par_;
    big_par_ = new_trapezoid.big_par_;
    sm_side_ = new_trapezoid.sm_side_;
    big_side_ = new_trapezoid.big_side_;
}

Trapezoid& Trapezoid::operator = (const Trapezoid &new_trapezoid) {
    points_.resize(new_trapezoid.points_.size());
    for (int i = 0; i < new_trapezoid.points_.size(); i++)
        points_[i] = new_trapezoid.points_[i];
    perimeter_ = new_trapezoid.perimeter_;
    square_ = new_trapezoid.square_;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Trapezoid &trapezoid) {
    out << "Trapezoid:";
    for (int i = 0; i < trapezoid.points_.size(); i++)
        out << " " << trapezoid.points_[i];
    out << " Perimetere = " << trapezoid.perimeter() << " square_ = " << trapezoid.square();
    return out;
}