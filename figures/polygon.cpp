#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool Polygon::is_polygon() const
{
    if (points_.size() != 0) {
        // double k = length(points_[0], points_[1]);
        double k = (points_[1].y() - points_[0].y()) / (points_[1].x() - points_[0].x());
        double b = points_[0].y() - k * points_[0].x();
        for (int i = 2; i < points_.size(); i++)
            if ((k * points_[i].x() + b) == points_[i].y())
                return false;
    }
    for (int i = 0; i < points_.size() - 1; i++)
        for (int j = i + 2; j < points_.size() - 1; j++)
            if (is_crossing(points_[i], points_[i + 1], points_[j], points_[j + 1]))
                return false;
    return true;
}

double Polygon::new_square() const
{
    if (points_.size() == 0)
        return 0;
    double sq = points_[points_.size() - 1].x() * points_[0].y() - points_[points_.size() - 1].y() * points_[0].x();
    for (int i = 0; i < points_.size() - 1; i++)
    {
        sq += points_[i].x() * points_[i + 1].y();
        sq -= points_[i].y() * points_[i + 1].x();
    }
    return 0.5 * abs(sq);
}

Polygon::Polygon()
{
    square_ = 0;
}

Polygon::Polygon(const std::vector<Point> &points) : ClosedPolyline(points)
{
    if (!is_polygon())
    {
        points_.resize(0);
        perimeter_ = 0;
    }
    square_ = new_square();
}

Polygon::Polygon(const Polygon &rhs) : ClosedPolyline(rhs)
{
    square_ = new_square();
}

Polygon &Polygon::operator=(const Polygon &rhs)
{
    points_.resize(rhs.points_.size());
    for (int i = 0; i < points_.size(); i++)
        points_[i] = rhs.points_[i];
    perimeter_ = new_perimeter();
    square_ = new_square();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Polygon &rhs)
{
    out << "{";
    for (int i = 0; i < rhs.points_.size(); i++)
        out << rhs.points_[i] << ", ";
    out << "Perimeter = " << rhs.perimeter() << ", square = " << rhs.square() << "}";
    return out;
}

double Polygon::square() const
{
    return square_;
}