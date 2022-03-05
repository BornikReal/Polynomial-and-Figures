#include <vector>
#include <iostream>

#pragma once

class Polyline;

class Point
{
    friend class Polyline;

private:
    /**
     * @brief Координата x точки
     *
     */
    double x_;
    /**
     * @brief Координата y точки
     *
     */
    double y_;
    static double area(const Point &point1, const Point &point2, const Point &point3);

public:
    /**
     * @brief Создаёт точку с нулевыми координатами
     *
     */
    Point();
    explicit Point(double x, double y);
    Point(const Point &new_point);
    ~Point() {}
    Point &operator=(const Point &rhs);
    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    /**
     * @brief Возвращает ссылку на точку, являющейся последней точкой ломанной, отложенной от текущей точки
     *
     * @param rhs
     * @return Point&
     */
    Point &operator+=(const Polyline &rhs);
    /**
     * @brief Возвращает ссылку на точку, являющейся последней точкой ломанной, отложенной от текущей точки и имеющей обратный порядок вершин
     *
     * @param rhs
     * @return Point&
     */
    Point &operator-=(const Polyline &rhs);
    /**
     * @brief Возвращает точку, являющейся последней точкой ломанной, отложенной от текущей точки
     *
     * @param rhs
     * @return Point&
     */
    Point operator+(const Polyline &rhs) const;
    /**
     * @brief Возвращает ссылку на точку, являющейся последней точкой ломанной, отложенной от текущей точки и имеющей обратный порядок вершин
     *
     * @param rhs
     * @return Point&
     */
    Point operator-(const Polyline &rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const Point &rhs);
    double x() const;
    double y() const;
    /**
     * @brief Выводит расстояние между двумя точками
     *
     * @param point1
     * @param point2
     * @return double
     */
    friend double length(const Point &point1, const Point &point2);
    /**
     * @brief Проверяет пересекаются ли отрезки с концами point1, point2 и point3, point4
     * 
     * @param point1 
     * @param point2 
     * @param point3 
     * @param point4 
     * @return true 
     * @return false 
     */
    friend bool is_crossing(const Point &point1, const Point &point2, const Point &point3, const Point &point4);
};

class Polyline
{
    friend class Point;

protected:
    /**
     * @brief Массив вершин ломанной
     *
     */
    std::vector<Point> points_;
    /**
     * @brief Длина ломанной
     *
     */
    double perimeter_;
    /**
     * @brief Удаляет из ломанной повторяющиеся подряд вершины
     *
     */
    void fix();
    /**
     * @brief Расчитывает новую длину ломанной
     *
     * @return double
     */
    virtual double new_perimeter() const;

public:
    /**
     * @brief Создаёт ломанную из 0 точек
     *
     */
    explicit Polyline();
    explicit Polyline(const std::vector<Point> &points);
    Polyline(const Polyline &new_polyline);
    ~Polyline() {}
    Polyline &operator=(const Polyline &rhs);
    /**
     * @brief Сравнение всех вершин ломанных
     *
     */
    bool operator==(const Polyline &rhs) const;
    bool operator!=(const Polyline &rhs) const;
    /**
     * @brief Сравнение длин ломанных
     *
     */
    bool operator>(const Polyline &rhs) const;
    bool operator>=(const Polyline &rhs) const;
    bool operator<(const Polyline &rhs) const;
    bool operator<=(const Polyline &rhs) const;
    Point operator[](int rhs) const;
    Point &operator[](int rhs);
    friend std::ostream &operator<<(std::ostream &out, const Polyline &rhs);
    /**
     * @brief Возвращает количество вершин ломанной
     *
     * @return int
     */
    int size() const;
    /**
     * @brief Проверка на параллельность каждых отрезков ломанных
     *
     * @param polyline
     * @return true
     * @return false
     */
    bool collinear(const Polyline &polyline) const;
    double perimeter() const;
};

/**
 * @brief Возвращет ломанную из двух вершин
 *
 * @param point1 Начала ломанной
 * @param point2 Конец ломанной
 * @return Polyline
 */
Polyline operator-(const Point &point1, const Point &point2);

class ClosedPolyline : public Polyline
{
protected:
    /**
     * @brief Расчитывает новую длину ломанной
     *
     * @return double
     */
    double new_perimeter() const override;

public:
    /**
     * @brief Возвращает замкнутую ломанную из 0 вершин
     *
     */
    explicit ClosedPolyline(){};
    explicit ClosedPolyline(const std::vector<Point> &points);
    ClosedPolyline(const ClosedPolyline &new_closed_polyline);
    ~ClosedPolyline() {}
    ClosedPolyline &operator=(const ClosedPolyline &rhs);
};

class Polygon : public ClosedPolyline
{
protected:
    /**
     * @brief Площадь многоугольника
     *
     */
    double square_;
    /**
     * @brief Проверка на то - является ли данный набор точек многоугольником
     *
     * @return true
     * @return false
     */
    bool is_polygon() const;
    /**
     * @brief Расчитывает новую площадь многоугольника
     *
     * @return double
     */
    virtual double new_square() const;

public:
    explicit Polygon();
    explicit Polygon(const std::vector<Point> &points);
    Polygon(const Polygon &new_polygon);
    ~Polygon() {}
    Polygon &operator=(const Polygon &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Polygon &rhs);
    double square() const;
};

class Triangle final : public Polygon
{
private:
    /**
     * @brief Расчитывает новую площадь треугольника
     *
     * @return double
     */
    double new_square() const override;

public:
    explicit Triangle(){};
    explicit Triangle(const std::vector<Point> &points);
    explicit Triangle(const Point &point1, const Point &point2, const Point &point3);
    Triangle(const Triangle &new_triangle);
    ~Triangle() {}
    Triangle &operator=(const Triangle &rhs);
};

class Trapezoid final : public Polygon
{
private:
    /**
     * @brief Меньшая и большая параллельные стороны, меньшая и большая боковые стороны
     *
     */
    Polyline sm_par_, big_par_, sm_side_, big_side_;
    /**
     * @brief Расчитывает новую площадь трапеции
     *
     * @return double
     */
    double new_square() const override;

public:
    explicit Trapezoid(){};
    explicit Trapezoid(const std::vector<Point> &points);
    explicit Trapezoid(const Point &point1, const Point &point2, const Point &point3, const Point &point4);
    Trapezoid(const Trapezoid &new_trapezoid);
    ~Trapezoid() {}
    Trapezoid &operator=(const Trapezoid &rhs);
    Polyline sm_par() const;
    Polyline big_par() const;
    Polyline sm_side() const;
    Polyline big_side() const;
};

class RegularPolygon final : public Polygon
{
private:
    /**
     * @brief Сторона правильного многоугольника
     *
     */
    Polyline side_;
    /**
     * @brief Угол правильного многоугольника
     *
     */
    double angle_;
    /**
     * @brief Проверка на то - является ли данный набор точек правильным многоугольником
     *
     * @return true
     * @return false
     */
    bool is_regular_polygon();
    /**
     * @brief Расчитывает новую площадь правильного многоугольника
     *
     * @return double
     */
    double new_square() const override;

public:
    explicit RegularPolygon(){};
    explicit RegularPolygon(const std::vector<Point> &points);
    RegularPolygon(const RegularPolygon &new_regular_poly);
    ~RegularPolygon() {}
    RegularPolygon &operator=(const RegularPolygon &rhs);
    bool operator==(const RegularPolygon &rhs) const;
    bool operator!=(const RegularPolygon &rhs) const;
    Polyline side() const;
    double angle() const;
};