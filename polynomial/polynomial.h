#include <vector>
#include <iostream>

#pragma once

class Polynimial
{
private:
    std::vector<double> coef_;
    void fix();

public:
    Polynimial();
    Polynimial(unsigned size, double value);
    Polynimial(const std::vector<double> &_coef);
    Polynimial(const Polynimial &polynimial);
    ~Polynimial() {}
    int size();
    Polynimial &operator=(const Polynimial &rhs);
    double &operator[](int rhs);
    Polynimial operator+() const;
    Polynimial operator-() const;
    Polynimial &operator+=(const Polynimial &rhs);
    Polynimial &operator+=(double rhs);
    Polynimial &operator++();
    Polynimial &operator-=(const Polynimial &rhs);
    Polynimial &operator-=(double rhs);
    Polynimial &operator--();
    Polynimial &operator*=(const Polynimial &rhs);
    Polynimial &operator*=(double rhs);
    Polynimial &operator/=(double rhs);
    bool operator==(const Polynimial &rhs) const;
    bool operator!=(const Polynimial &rhs) const;
    Polynimial operator+(const Polynimial &rhs) const;
    Polynimial operator+(double rhs) const;
    Polynimial operator++(int);
    Polynimial operator-(const Polynimial &rhs) const;
    Polynimial operator-(double num) const;
    Polynimial operator--(int);
    Polynimial operator*(const Polynimial &rhs) const;
    Polynimial operator*(double rhs) const;
    Polynimial operator/(double rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const Polynimial &rhs);
    friend std::istream &operator>>(std::istream &in, Polynimial &rhs);
    Polynimial &operator>>(int rhs);
    Polynimial &operator<<(int rhs);
};