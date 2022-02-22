#include <vector>
#include <ostream>

#pragma once

class Polyline;

class Point
{
    friend class Polyline;

private:
    double x_;
    double y_;

public:
    Point();
    Point(double x, double y);
    Point(const Point &new_point);
    ~Point() {}
    Point &operator=(const Point &rhs);
    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    Point &operator+=(const Polyline &rhs);
    Point &operator-=(const Polyline &rhs);
    Point operator+(const Polyline &rhs) const;
    Point operator-(const Polyline &rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const Point &rhs);
    double x() const;
    double y() const;
    friend double length(const Point &point1, const Point &point2);
};

class Polyline
{
    friend class Point;

protected:
    std::vector<Point> points_;
    double perimeter_;
    void fix();
    double new_perimeter() const;

public:
    Polyline();
    Polyline(const std::vector<Point> &points);
    Polyline(const Polyline &new_polyline);
    ~Polyline() {}
    Polyline &operator=(const Polyline &rhs);
    bool operator==(const Polyline &rhs) const;
    bool operator!=(const Polyline &rhs) const;
    bool operator>(const Polyline &rhs) const;
    bool operator>=(const Polyline &rhs) const;
    bool operator<(const Polyline &rhs) const;
    bool operator<=(const Polyline &rhs) const;
    Point &operator[](int pos);
    friend std::ostream &operator<<(std::ostream &out, const Polyline &rhs);
    int size() const;
    bool collinear(const Polyline &polyline) const;
    double perimeter() const;
};

Polyline operator-(const Point &point1, const Point &point2);

class ClosedPolyline : public Polyline
{
protected:
    double new_perimeter() const;

public:
    ClosedPolyline(){};
    ClosedPolyline(const std::vector<Point> &points);
    ClosedPolyline(const ClosedPolyline &new_closed_polyline);
    ~ClosedPolyline() {}
    ClosedPolyline &operator=(const ClosedPolyline &rhs);
    friend std::ostream &operator<<(std::ostream &out, const ClosedPolyline &rhs);
};

class Polygon : public ClosedPolyline
{
protected:
    double square_;
    bool is_polygon() const;
    double new_square() const;

public:
    Polygon();
    Polygon(const std::vector<Point> &points);
    Polygon(const Polygon &new_polygon);
    ~Polygon() {}
    Polygon &operator=(const Polygon &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Polygon &rhs);
    double square() const;
};

class Triangle final : public Polygon
{
private:
    double new_square() const;

public:
    Triangle(){};
    Triangle(const std::vector<Point> &points);
    Triangle(const Point &point1, const Point &point2, const Point &point3);
    Triangle(const Triangle &new_triangle);
    ~Triangle() {}
    Triangle &operator=(const Triangle &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Triangle &rhs);
};

class Trapezoid final : public Polygon
{
private:
    Polyline sm_par_, big_par_, sm_side_, big_side_;
    double new_square() const;

public:
    Trapezoid(){};
    Trapezoid(const std::vector<Point> &points);
    Trapezoid(const Point &point1, const Point &point2, const Point &point3, const Point &point4);
    Trapezoid(const Trapezoid &new_trapezoid);
    ~Trapezoid() {}
    Trapezoid &operator=(const Trapezoid &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Trapezoid &rhs);
};

class RegularPolygon final : public Polygon
{
private:
    Polyline side_;
    double angle_;
    bool is_regular_polygon();
    double new_square() const;

public:
    RegularPolygon(){};
    RegularPolygon(const std::vector<Point> &points);
    RegularPolygon(const RegularPolygon &new_regular_poly);
    ~RegularPolygon() {}
    RegularPolygon &operator=(const RegularPolygon &rhs);
    bool operator==(const RegularPolygon &rhs) const;
    bool operator!=(const RegularPolygon &rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const RegularPolygon &rhs);
};