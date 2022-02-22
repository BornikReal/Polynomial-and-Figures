#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}

Point::Point(const Point &new_point) {
    x_ = new_point.x_;
    y_ = new_point.y_;
}

Point& Point::operator = (const Point &new_point) {
    x_ = new_point.x_;
    y_ = new_point.y_;
    return *this;
}

bool Point::operator == (const Point& point) const {
    if ((x_ == point.x_) && (y_ == point.y_))
        return true;
    return false;
}

bool Point::operator != (const Point& point) const {
    if ((x_ == point.x_) && (y_ == point.y_))
        return false;
    return true;
}

Point& Point::operator += (const Polyline &poly) {
    Point point1 = poly.points_[0], point2 = poly.points_[poly.points_.size() - 1];
    x_ += point2.x_ - point1.x_; y_ += point2.y_ - point1.y_;
    return *this;
}

Point& Point::operator -= (const Polyline &poly) {
    Point point1 = poly.points_[0], point2 = poly.points_[poly.points_.size() - 1];
    x_ = point2.x_ + point1.x_ - x_; y_ = point2.y_ + point1.y_ - y_;
    return *this;
}

Point Point::operator + (const Polyline &poly) const {
    Point point1 = poly.points_[0], point2 = poly.points_[poly.points_.size() - 1];
    return Point(point2.x_ - point1.x_ + x_, point2.y_ - point1.y_ + y_);
}

Point Point::operator - (const Polyline &poly) const {
    Point point1 = poly.points_[0], point2 = poly.points_[poly.points_.size() - 1];
    return Point(point2.x_ + point1.x_ - x_, point2.y_ + point1.y_ - y_);
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "Point {" << point.x_ << ", " << point.y_ << "}";
    return out;
}

double Point::x() const {
    return x_;
}

double Point::y() const {
    return y_;
}

double length(const Point& point1, const Point& point2) {
    return sqrt((point1.x_ - point2.x_) * (point1.x_ - point2.x_) + (point1.y_ - point2.y_) * (point1.y_ - point2.y_));
}