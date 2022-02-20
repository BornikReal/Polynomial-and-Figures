#include <vector>
#include <ostream>

#pragma once

class Polynimial
{
private:
    std::vector<double> coef;
    void fix();

public:
    Polynimial();
    Polynimial(unsigned size, double value);
    Polynimial(const std::vector<double> &_coef);
    Polynimial(const Polynimial &new_poly);
    ~Polynimial() {}
    int size();
    Polynimial &operator=(const Polynimial &new_poly);
    double &operator[](int i);
    Polynimial operator+() const;
    Polynimial operator-() const;
    Polynimial &operator+=(const Polynimial &poly);
    Polynimial &operator+=(double);
    Polynimial &operator++();
    Polynimial &operator-=(const Polynimial &);
    Polynimial &operator-=(double num);
    Polynimial &operator--();
    Polynimial &operator*=(const Polynimial &poly);
    Polynimial &operator*=(double num);
    Polynimial &operator/=(double num);
    bool operator==(const Polynimial &poly) const;
    bool operator!=(const Polynimial &poly) const;
    Polynimial operator+(const Polynimial &poly) const;
    Polynimial operator+(double num) const;
    Polynimial operator++(int);
    Polynimial operator-(const Polynimial &poly) const;
    Polynimial operator-(double num) const;
    Polynimial operator--(int);
    Polynimial operator*(const Polynimial &poly) const;
    Polynimial operator*(double num) const;
    Polynimial operator/(double num) const;
    friend std::ostream &operator<<(std::ostream &out, const Polynimial &poly);
    friend std::istream &operator>>(std::istream &in, Polynimial &poly);
    Polynimial &operator>>(int num);
    Polynimial &operator<<(int num);
};