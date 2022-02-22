#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

Point::Point()
{
    x_ = 0;
    y_ = 0;
}

Point::Point(double x, double y)
{
    x_ = x;
    y_ = y;
}

Point::Point(const Point &new_point)
{
    x_ = new_point.x_;
    y_ = new_point.y_;
}

Point &Point::operator=(const Point &new_point)
{
    x_ = new_point.x_;
    y_ = new_point.y_;
    return *this;
}

bool Point::operator==(const Point &rhs) const
{
    if ((x_ == rhs.x_) && (y_ == rhs.y_))
        return true;
    return false;
}

bool Point::operator!=(const Point &rhs) const
{
    if ((x_ == rhs.x_) && (y_ == rhs.y_))
        return false;
    return true;
}

Point &Point::operator+=(const Polyline &rhs)
{
    Point point1 = rhs.points_[0], point2 = rhs.points_[rhs.points_.size() - 1];
    x_ += point2.x_ - point1.x_;
    y_ += point2.y_ - point1.y_;
    return *this;
}

Point &Point::operator-=(const Polyline &rhs)
{
    Point point1 = rhs.points_[0], point2 = rhs.points_[rhs.points_.size() - 1];
    x_ = point2.x_ + point1.x_ - x_;
    y_ = point2.y_ + point1.y_ - y_;
    return *this;
}

Point Point::operator+(const Polyline &rhs) const
{
    Point point1 = rhs.points_[0], point2 = rhs.points_[rhs.points_.size() - 1];
    return Point(point2.x_ - point1.x_ + x_, point2.y_ - point1.y_ + y_);
}

Point Point::operator-(const Polyline &rhs) const
{
    Point point1 = rhs.points_[0], point2 = rhs.points_[rhs.points_.size() - 1];
    return Point(point2.x_ + point1.x_ - x_, point2.y_ + point1.y_ - y_);
}

std::ostream &operator<<(std::ostream &out, const Point &rhs)
{
    out << "Point {" << rhs.x_ << ", " << rhs.y_ << "}";
    return out;
}

double Point::x() const
{
    return x_;
}

double Point::y() const
{
    return y_;
}

double length(const Point &point1, const Point &point2)
{
    return sqrt((point1.x_ - point2.x_) * (point1.x_ - point2.x_) + (point1.y_ - point2.y_) * (point1.y_ - point2.y_));
}