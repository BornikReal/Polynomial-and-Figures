#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool RegularPolygon::is_regular_polygon()
{
    
    if (points_.size() == 0)
        return true;
    Point a = Point(0, 0) + (points_[0] - points_[1]);
    Point b = Point(0, 0) + (points_[0] - points_[points_.size() - 1]);
    side_ = Polyline({points_[0], points_[1]});
    angle_ = abs((a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0))));
    for (int i = 1; i < points_.size() - 1; i++)
    {
        a = Point(0, 0) + (points_[i] - points_[i - 1]);
        b = Point(0, 0) + (points_[i] - points_[i + 1]);
        double new_angle = abs((a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0))));
        if ((length(points_[i], points_[i - 1]) != side_.perimeter()) || (length(points_[i], points_[i + 1]) != side_.perimeter()) || (new_angle != angle_))
            return false;
    }
    return true;
}

double RegularPolygon::new_square() const
{
    return (points_.size() * side_.perimeter() * side_.perimeter()) / (4 * tan(acos(-1) / side_.perimeter()));
}

RegularPolygon::RegularPolygon(const std::vector<Point> &points) : Polygon(points)
{
    if (!is_regular_polygon())
    {
        points_.resize(0);
        perimeter_ = 0;
        square_ = 0;
        angle_ = 0;
        side_ = Polyline();
    }
}

RegularPolygon::RegularPolygon(const RegularPolygon &new_rpoly) : Polygon(new_rpoly)
{
    side_ = new_rpoly.side_;
    angle_ = new_rpoly.angle_;
}

RegularPolygon &RegularPolygon::operator=(const RegularPolygon &rhs)
{
    points_.resize(rhs.points_.size());
    side_ = rhs.side_;
    angle_ = rhs.angle_;
    for (int i = 0; i < points_.size(); i++)
        points_[i] = rhs.points_[i];
    perimeter_ = new_perimeter();
    square_ = new_square();
    return *this;
}

bool RegularPolygon::operator==(const RegularPolygon &rhs) const
{
    if ((side_ == rhs.side_) && (angle_ == rhs.angle_))
        return true;
    return false;
}

bool RegularPolygon::operator!=(const RegularPolygon &rhs) const
{
    if ((side_ == rhs.side_) && (angle_ == rhs.angle_))
        return false;
    return true;
}

Polyline RegularPolygon::side() const
{
    return side_;
}

double RegularPolygon::angle() const
{
    return angle_;
}