#include <vector>
#include <ostream>

#pragma once

class Polyline;

class Point {
    friend class Polyline;
    private:
        double _x;
        double _y;
    public:
        Point();
        Point(double x, double y);
        Point(const Point &new_point);
        ~Point() {}
        Point& operator = (const Point &new_point);
        bool operator == (const Point& point) const;
        bool operator != (const Point& point) const;
        Point& operator += (const Polyline &poly);
        Point& operator -= (const Polyline &poly);
        Point operator + (const Polyline &poly) const;
        Point operator - (const Polyline &poly) const;
        friend std::ostream &operator<<(std::ostream &out, const Point &point);
        double x() const;
        double y() const;
        friend double length(const Point& point1, const Point& point2);
};

class Polyline {
    friend class Point;
    protected:
        std::vector <Point> points;
        double perimeter;
        void fix();
        double new_perimeter() const;
    public:
        Polyline();
        Polyline(const std::vector <Point> &_points);
        Polyline(const Polyline &new_polyline);
        ~Polyline() {}
        Polyline& operator = (const Polyline &new_polyline);
        bool operator == (const Polyline& poly) const;
        bool operator != (const Polyline& poly) const;
        bool operator > (const Polyline &poly) const;
        bool operator >= (const Polyline &poly) const;
        bool operator < (const Polyline &poly) const;
        bool operator <= (const Polyline &poly) const;
        Point& operator [] (int pos);
        friend std::ostream &operator<<(std::ostream &out, const Polyline &poly);
        int size() const;
        bool collinear(const Polyline& poly) const;
        double get_perimeter() const;
};

Polyline operator - (const Point &point1, const Point &point2);

class CPolyline: public Polyline {
    protected:
        double new_perimeter() const;
    public:
        CPolyline() {};
        CPolyline(const std::vector <Point> &_points);
        CPolyline(const CPolyline& new_cpolyline);
        ~CPolyline() {}
        CPolyline& operator = (const CPolyline &new_cpolyline);
        friend std::ostream &operator<<(std::ostream &out, const CPolyline &cpoly);
};

class Polygon: public CPolyline {
    protected:
        double square;
        bool is_polygon() const;
        double new_square() const;
    public:
        Polygon();
        Polygon(const std::vector <Point> &_points);
        Polygon(const Polygon& new_polygon);
        Polygon& operator = (const Polygon &new_polygon);
        ~Polygon() {}
        friend std::ostream &operator<<(std::ostream &out, const Polygon &polygon);
        double get_square() const;
};

class Triangle final: public Polygon {
    private:
        double new_square() const;
    public:
        Triangle() {};
        Triangle(const std::vector <Point> &_points);
        Triangle(const Point& point1, const Point& point2, const Point& point3);
        Triangle(const Triangle& new_triangle);
        ~Triangle() {}
        Triangle& operator = (const Triangle &new_triangle);
        friend std::ostream &operator<<(std::ostream &out, const Triangle &triangle);
};

class Trapezoid final: public Polygon {
    private:
        Polyline sm_par, big_par, sm_side, big_side;
        double new_square() const;
    public:
        Trapezoid() {};
        Trapezoid(const std::vector <Point> &_points);
        Trapezoid(const Point& point1, const Point& point2, const Point& point3, const Point& point4);
        Trapezoid(const Trapezoid& new_trapezoid);
        ~Trapezoid() {}
        Trapezoid& operator = (const Trapezoid &new_trapezoid);
        friend std::ostream &operator<<(std::ostream &out, const Trapezoid &trapezoid);
};

class RegularPolygon final: public Polygon {
    private:
        Polyline side;
        double angle;
        bool is_regular_polygon();
        double new_square() const;
    public:
        RegularPolygon() {};
        RegularPolygon(const std::vector <Point> &_points);
        RegularPolygon(const RegularPolygon& new_rpoly);
        ~RegularPolygon() {}
        RegularPolygon& operator = (const RegularPolygon &new_rpoly);
        bool operator == (const RegularPolygon& rpolygon) const;
        bool operator != (const RegularPolygon& rpolygon) const;
        friend std::ostream &operator<<(std::ostream &out, const RegularPolygon &rpolygon);
};