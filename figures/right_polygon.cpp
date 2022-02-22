#include "figures.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

bool RegularPolygon::is_regular_polygon() {
    Point a = Point(0, 0) + (points_[0] - points_[1]);
    Point b = Point(0, 0) + (points_[0] - points_[points_.size() - 1]);
    side_ = Polyline({points_[0], points_[1]});
    angle_ = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
    for (int i = 1; i < points_.size() - 1; i++)
    {
        a = Point(0, 0) + (points_[i] - points_[i - 1]);
        b = Point(0, 0) + (points_[i] - points_[i + 1]);
        double new_angle = (a.x() * b.x() + a.y() + b.y()) / (length(a, Point(0, 0)) * length(b, Point(0, 0)));
        if ((length(points_[i], points_[i - 1]) != side_.perimeter()) || (length(points_[i], points_[i + 1]) != side_.perimeter()) || (new_angle != angle_))
            return false;
    }
    return true;
}

double RegularPolygon::new_square() const {
    return (points_.size() * side_.perimeter() * side_.perimeter()) / (4 * tan(acos(-1) / side_.perimeter()));
}

RegularPolygon::RegularPolygon(const std::vector <Point> &_points):Polygon(_points) {
    if (!is_regular_polygon()) {
        points_.resize(0);
        perimeter_ = 0;
        square_ = 0;
        angle_ = 0;
        side_ = Polyline();
    }
}

RegularPolygon::RegularPolygon(const RegularPolygon& new_rpoly):Polygon(new_rpoly) {
    side_ = new_rpoly.side_;
    angle_ = new_rpoly.angle_;
}

RegularPolygon& RegularPolygon::operator = (const RegularPolygon &new_rpoly) {
    points_.resize(new_rpoly.points_.size());
    side_ = new_rpoly.side_;
    angle_ = new_rpoly.angle_;
    for (int i = 0; i < points_.size(); i++)
        points_[i] = new_rpoly.points_[i];
    perimeter_ = new_perimeter();
    square_ = new_square();
    return *this;
}

bool RegularPolygon::operator == (const RegularPolygon& rpolygon) const {
    if ((side_ == rpolygon.side_) && (angle_ == rpolygon.angle_))
        return true;
    return false;
}

bool RegularPolygon::operator != (const RegularPolygon& rpolygon) const {
    if ((side_ == rpolygon.side_) && (angle_ == rpolygon.angle_))
        return false;
    return true;
}

std::ostream &operator<<(std::ostream &out, const RegularPolygon &rpolygon) {
    out << "Right polygon:";
    for (int i = 0; i < rpolygon.points_.size(); i++)
        out << " " << rpolygon.points_[i];
    out << " Perimetere = " << rpolygon.perimeter() << " square_ = " << rpolygon.square();
    return out;
}