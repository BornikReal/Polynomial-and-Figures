#include <vector>
#include <iostream>

#pragma once

class Polynimial
{
private:
    /**
     * @brief Массив с коэффициентами полинома, где i-элемент массива - коэффициент при x^i
     *
     */
    std::vector<double> coef_;
    /**
     * @brief Исправляет полином так, чтобы старший одночлен имеел ненулевой коэффициент
     *
     */
    void fix();

public:
    /**
     * @brief Создаёт пустой полином (из 0 одночленов)
     *
     */
    Polynimial();
    /**
     * @brief Создаёт полином из заданного числа одночленов, где каждый коэффициент равен заданному числу
     *
     * @param size Размер полинома
     * @param value Значение каждого коэффициента
     */
    Polynimial(unsigned size, double value);
    /**
     * @brief Создаём полином, где коэффициенты являются членами заданного вектора
     *
     * @param _coef
     */
    Polynimial(const std::vector<double> &_coef);
    Polynimial(const Polynimial &polynimial);
    ~Polynimial() {}
    /**
     * @brief Возвращает степень полинома
     *
     * @return int
     */
    int size() const;
    Polynimial &operator=(const Polynimial &rhs);
    double operator[](int rhs) const;
    double &operator[](int rhs);
    /**
     * @brief Возращает текущий полином
     *
     * @return Polynimial
     */
    Polynimial operator+() const;
    /**
     * @brief Возращает текущий полином с отрицательным коэффициентами
     *
     * @return Polynimial
     */
    Polynimial operator-() const;
    Polynimial &operator+=(const Polynimial &rhs);
    Polynimial &operator+=(double rhs);
    /**
     * @brief Прибавляет к текущему полиному 1
     *
     * @return Polynimial&
     */
    Polynimial &operator++();
    Polynimial &operator-=(const Polynimial &rhs);
    Polynimial &operator-=(double rhs);
    Polynimial &operator--();
    Polynimial &operator*=(const Polynimial &rhs);
    Polynimial &operator*=(double rhs);
    Polynimial &operator/=(const Polynimial &rhs);
    Polynimial &operator/=(double rhs);
    bool operator==(const Polynimial &rhs) const;
    bool operator!=(const Polynimial &rhs) const;
    Polynimial operator+(const Polynimial &rhs) const;
    Polynimial operator+(double rhs) const;
    /**
     * @brief Прибавляет к текущему полиному 1
     *
     * @return Polynimial
     */
    Polynimial operator++(int);
    Polynimial operator-(const Polynimial &rhs) const;
    Polynimial operator-(double num) const;
    /**
     * @brief Отнимает от текущего полинома 1
     *
     * @return Polynimial
     */
    Polynimial operator--(int);
    Polynimial operator*(const Polynimial &rhs) const;
    Polynimial operator*(double rhs) const;
    Polynimial operator/(const Polynimial &rhs) const;
    Polynimial operator/(double rhs) const;
    /**
     * @brief Выводит полином в виде a1 * x^n + a2 * x^(n - 1) + ... + a(n-1) * x + an
     *
     * @param out
     * @param rhs
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &out, const Polynimial &rhs);
    /**
     * @brief Ввод полинома в формате n a1 a2 a3 ... an, где n - количество коэффициентов, а ai - коэффициент при x в степени i
     *
     * @param in
     * @param rhs
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &in, Polynimial &rhs);
    /**
     * @brief Увеличивает степень полинома на заданное число
     *
     * @param rhs
     * @return Polynimial
     */
    Polynimial operator<<(int rhs) const;
    /**
     * @brief Уменьшает степень полинома на заданное число
     *
     * @param rhs
     * @return Polynimial
     */
    Polynimial operator>>(int rhs) const;
    /**
     * @brief Возвращает производную полинома
     *
     * @return Polynimial
     */
    Polynimial derivative() const;
    /**
     * @brief Возвращает первообразную полинома
     *
     * @return Polynimial
     */
    Polynimial primitive(double con) const;
};