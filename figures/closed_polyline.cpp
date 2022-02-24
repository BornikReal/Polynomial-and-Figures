#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

double ClosedPolyline::new_perimeter() const
{
    double len = length(points_[0], points_[points_.size() - 1]);
    for (int i = 1; i < points_.size(); i++)
        len += length(points_[i], points_[i - 1]);
    return len;
}

ClosedPolyline::ClosedPolyline(const std::vector<Point> &points) : Polyline(points)
{
    if ((points_.size() >= 2) && (points_[0] == points_[points_.size() - 1]))
        points_.pop_back();
    if (points_.size() <= 2)
        points_.resize(0);
    perimeter_ = new_perimeter();
}

ClosedPolyline::ClosedPolyline(const ClosedPolyline &new_closed_polyline) : Polyline(new_closed_polyline)
{
    perimeter_ = new_perimeter();
}

ClosedPolyline &ClosedPolyline::operator=(const ClosedPolyline &rhs)
{
    points_.resize(rhs.points_.size());
    for (int i = 0; i < points_.size(); i++)
        points_[i] = rhs.points_[i];
    perimeter_ = new_perimeter();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ClosedPolyline &rhs)
{
    out << "Closed polyline:";
    for (int i = 0; i < rhs.points_.size(); i++)
        out << " " << rhs.points_[i];
    out << " Perimeter = " << rhs.perimeter();
    return out;
}