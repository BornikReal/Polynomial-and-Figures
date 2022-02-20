#include "polynomial.h"
#include <vector>
#include <string>
#include <iostream>

void Polynimial::fix()
{
    int new_size;
    for (int i = coef.size() - 1; i >= 0; i--)
    {
        if (coef[i] != 0)
        {
            new_size = i + 1;
            break;
        }
    }
    coef.resize(new_size);
}

Polynimial::Polynimial() {}

Polynimial::Polynimial(unsigned size, double value)
{
    if ((!size) || (value != 0))
        coef.resize(size, value);
}

Polynimial::Polynimial(const std::vector<double> &_coef)
{
    coef.resize(_coef.size());
    for (int i = 0; i < _coef.size(); i++)
        coef[i] = _coef[i];
    fix();
}

Polynimial::Polynimial(const Polynimial &new_poly)
{
    coef.resize(new_poly.coef.size());
    for (int i = 0; i < new_poly.coef.size(); i++)
        coef[i] = new_poly.coef[i];
}

int Polynimial::size()
{
    return coef.size();
}

Polynimial &Polynimial::operator=(const Polynimial &new_poly)
{
    coef.resize(new_poly.coef.size());
    for (int i = 0; i < coef.size(); i++)
        coef[i] = new_poly.coef[i];
    return *this;
}

double &Polynimial::operator[](int i)
{
    return coef[i];
}

Polynimial Polynimial::operator+() const
{
    return Polynimial(*this);
}

Polynimial Polynimial::operator-() const
{
    Polynimial new_poly(*this);
    for (int i = 0; i < coef.size(); i++)
        new_poly.coef[i] = -new_poly.coef[i];
    return new_poly;
}

Polynimial &Polynimial::operator+=(const Polynimial &poly)
{
    int t = coef.size();
    for (int i = 0; i < t; i++)
        coef[i] += poly.coef[i];
    if (t < poly.coef.size())
        coef.resize(poly.coef.size());
    for (int i = t; i < coef.size(); i++)
        coef[i] = poly.coef[i];
    fix();
    return *this;
}

Polynimial &Polynimial::operator+=(double num)
{
    if (coef.size() == 0)
    {
        if (num == 0)
            return *this;
        coef.resize(1);
        coef[0] = num;
        return *this;
    }
    coef[0] += num;
    fix();
    return *this;
}

Polynimial &Polynimial::operator++()
{
    *this += 1;
    fix();
    return *this;
}

Polynimial &Polynimial::operator-=(const Polynimial &poly)
{
    int t = coef.size();
    for (int i = 0; i < t; i++)
        coef[i] -= poly.coef[i];
    if (t < poly.coef.size())
        coef.resize(poly.coef.size());
    for (int i = t; i < coef.size(); i++)
        coef[i] = -poly.coef[i];
    fix();
    return *this;
}

Polynimial &Polynimial::operator-=(double num)
{
    if (coef.size() == 0)
    {
        if (num == 0)
            return *this;
        coef.resize(1);
        coef[0] = -num;
        return *this;
    }
    coef[0] -= num;
    fix();
    return *this;
}

Polynimial &Polynimial::operator--()
{
    *this -= 1;
    fix();
    return *this;
}

Polynimial &Polynimial::operator*=(const Polynimial &poly)
{
    Polynimial new_poly(*this);
    for (int i = 0; i < coef.size(); i++)
        coef[i] = 0;
    coef.resize(coef.size() + poly.coef.size(), 0);
    for (int i = 0; i < new_poly.coef.size(); i++)
    {
        for (int j = 0; j < poly.coef.size(); j++)
            coef[i + j] += new_poly.coef[i] * poly.coef[j];
    }
    return *this;
}

Polynimial &Polynimial::operator*=(double num)
{
    for (int i = 0; i < coef.size(); i++)
        coef[i] *= num;
    fix();
    return *this;
}

Polynimial &Polynimial::operator/=(double num)
{
    for (int i = 0; i < coef.size(); i++)
        coef[i] /= num;
    return *this;
}

bool Polynimial::operator==(const Polynimial &poly) const
{
    if (coef.size() != poly.coef.size())
        return false;
    for (int i = 0; i < coef.size(); i++)
    {
        if (coef[i] != poly.coef[i])
            return false;
    }
    return true;
}

bool Polynimial::operator!=(const Polynimial &poly) const
{
    if (coef.size() != poly.coef.size())
        return false;
    for (int i = 0; i < coef.size(); i++)
    {
        if (coef[i] != poly.coef[i])
            return true;
    }
    return false;
}

Polynimial Polynimial::operator+(const Polynimial &poly) const
{
    Polynimial new_poly(*this);
    if (new_poly.coef.size() > poly.coef.size())
    {
        for (int i = 0; i < poly.coef.size(); i++)
            new_poly.coef[i] += poly.coef[i];
        new_poly.fix();
        return new_poly;
    }
    else
    {
        for (int i = 0; i < new_poly.coef.size(); i++)
            new_poly.coef[i] += poly.coef[i];
        int t = new_poly.coef.size();
        new_poly.coef.resize(poly.coef.size());
        for (int i = t; i < new_poly.coef.size(); i++)
            new_poly.coef[i] = poly.coef[i];
        new_poly.fix();
        return new_poly;
    }
}

Polynimial Polynimial::operator+(double num) const
{
    if (coef.size() == 0)
        return Polynimial(1, num);
    Polynimial new_poly(*this);
    new_poly.coef[0] += num;
    new_poly.fix();
    return new_poly;
}

Polynimial Polynimial::operator++(int)
{
    Polynimial new_poly(*this);
    ++*this;
    return new_poly;
}

Polynimial Polynimial::operator-(const Polynimial &poly) const
{
    return *this + (-poly);
}

Polynimial Polynimial::operator-(double num) const
{
    return -(*this);
}

Polynimial Polynimial::operator--(int)
{
    Polynimial new_poly(*this);
    --*this;
    return new_poly;
}

Polynimial Polynimial::operator*(const Polynimial &poly) const
{
    Polynimial new_poly(poly.coef.size() + coef.size());
    for (int i = 0; i < coef.size(); i++)
    {
        for (int j = 0; j < poly.coef.size(); j++)
            new_poly[i + j] += coef[i] * poly.coef[j];
    }
    return new_poly;
}

Polynimial Polynimial::operator*(double num) const
{
    if (!num)
    {
        Polynimial new_poly;
        return new_poly;
    }
    Polynimial new_poly(*this);
    for (int i = 0; i < coef.size(); i++)
        new_poly.coef[i] *= num;
    return new_poly;
}

Polynimial Polynimial::operator/(double num) const
{
    Polynimial new_poly(*this);
    for (int i = 0; i < coef.size(); i++)
        new_poly.coef[i] /= num;
    return new_poly;
}

std::ostream &operator<<(std::ostream &out, const Polynimial &poly)
{
    if (poly.coef.size() == 0)
        return out;
    if ((poly.coef.size() >= 1) && (poly.coef[0] != 0))
        out << poly.coef[0];
    double t;
    bool d = false;
    if (poly.coef[0] != 0)
        d = true;
    for (int i = 1; i < poly.coef.size(); i++)
    {
        if (poly.coef[i] == 0)
            continue;
        else if (d)
        {
            if (poly.coef[i] > 0)
                out << " + ";
            else
                out << " - ";
        }
        t = abs(poly.coef[i]);
        if (t != 1)
            out << abs(poly.coef[i]) << "x";
        else
            out << "x";
        if (i != 1)
            out << "^" << i;
        d = true;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynimial &poly)
{
    int size;
    in >> size;
    poly.coef.resize(size);
    for (int i = 0; i < size; i++)
        in >> poly.coef[i];
    return in;
}

Polynimial &Polynimial::operator<<(int num)
{
    if (num <= 0)
        return *this;
    coef.resize(coef.size() + num);
    for (int i = (coef.size() - 1); i >= num; i--)
        coef[i] = coef[i - num];
    for (int i = 0; i < num; i++)
        coef[i] = 0;
    return *this;
}

Polynimial &Polynimial::operator>>(int num)
{
    if (num <= 0)
        return *this;
    for (int i = 0; i <= (coef.size() - num); i++)
        coef[i] = coef[i + num];
    coef.resize(coef.size() - num);
    return *this;
}