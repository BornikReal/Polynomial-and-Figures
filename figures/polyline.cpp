#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

void Polyline::fix()
{
    int i = 1;
    while (i < points_.size())
    {
        if (points_[i] == points_[i - 1])
            points_.erase(points_.begin() + i);
        else
            i++;
    }
}

double Polyline::new_perimeter() const
{
    double len = 0;
    for (int i = 1; i < points_.size(); i++)
        len += length(points_[i], points_[i - 1]);
    return len;
}

Polyline::Polyline()
{
    perimeter_ = 0;
}

Polyline::Polyline(const std::vector<Point> &points)
{
    for (int i = 0; i < points.size(); i++)
        points_.push_back(points[i]);
    fix();
    if (points.size() <= 1)
        points_.resize(0);
}

Polyline::Polyline(const Polyline &new_polyline)
{
    for (int i = 0; i < new_polyline.points_.size(); i++)
        points_.push_back(new_polyline.points_[i]);
}

Polyline &Polyline::operator=(const Polyline &new_polyline)
{
    points_.resize(new_polyline.points_.size());
    for (int i = 0; i < points_.size(); i++)
        points_[i] = new_polyline.points_[i];
    return *this;
}

bool Polyline::operator==(const Polyline &rhs) const
{
    if (points_.size() != rhs.points_.size())
        return false;
    for (int i = 0; i < points_.size(); i++)
        if (points_[i] != rhs.points_[i])
            return false;
    return true;
}

bool Polyline::operator!=(const Polyline &rhs) const
{
    if (points_.size() != rhs.points_.size())
        return true;
    for (int i = 0; i < points_.size(); i++)
        if (points_[i] != rhs.points_[i])
            return true;
    return false;
}

bool Polyline::operator>(const Polyline &rhs) const
{
    if (perimeter_ > rhs.perimeter_)
        return true;
    return false;
}

bool Polyline::operator>=(const Polyline &rhs) const
{
    if (perimeter_ >= rhs.perimeter_)
        return true;
    return false;
}

bool Polyline::operator<(const Polyline &rhs) const
{
    if (perimeter_ < rhs.perimeter_)
        return true;
    return false;
}

bool Polyline::operator<=(const Polyline &rhs) const
{
    if (perimeter_ <= rhs.perimeter_)
        return true;
    return false;
}

Point &Polyline::operator[](int rhs)
{
    return points_[rhs];
}

Point Polyline::operator[](int rhs) const
{
    return points_[rhs];
}

std::ostream &operator<<(std::ostream &out, const Polyline &rhs)
{
    out << "Polyline:";
    for (int i = 0; i < rhs.points_.size(); i++)
        out << " " << rhs.points_[i];
    return out;
}

int Polyline::size() const
{
    return points_.size();
}

bool Polyline::collinear(const Polyline &rhs) const
{
    for (int i = 1; i < points_.size(); i++)
    {
        if ((points_[i].x_ / points_[i - 1].x_) != (points_[i].y_ / points_[i - 1].y_))
            return false;
    }
    return true;
}

double Polyline::perimeter() const
{
    return perimeter_;
}

Polyline operator-(const Point &point1, const Point &point2)
{
    if (point2 == point1)
        return Polyline({point1});
    Polyline new_poly({point2, point1});
    return new_poly;
}