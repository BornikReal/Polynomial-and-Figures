#include "polynomial.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

void Polynimial::fix()
{
    int new_size = 0;
    for (int i = coef_.size() - 1; i >= 0; i--)
    {
        if (coef_[i] != 0)
        {
            new_size = i + 1;
            break;
        }
    }
    coef_.resize(new_size);
}

Polynimial::Polynimial() {}

Polynimial::Polynimial(unsigned size, double value = 0)
{
    coef_.resize(size, value);
    if (size && !value)
        coef_[coef_.size() - 1] = 1;
}

Polynimial::Polynimial(const std::vector<double> &coef)
{
    coef_.resize(coef.size());
    for (int i = 0; i < coef.size(); i++)
        coef_[i] = coef[i];
    fix();
}

Polynimial::Polynimial(const Polynimial &new_polynimial)
{
    coef_.resize(new_polynimial.coef_.size());
    for (int i = 0; i < new_polynimial.coef_.size(); i++)
        coef_[i] = new_polynimial.coef_[i];
}

int Polynimial::size() const
{
    return coef_.size();
}

Polynimial &Polynimial::operator=(const Polynimial &rhs)
{
    coef_.resize(rhs.coef_.size());
    for (int i = 0; i < coef_.size(); i++)
        coef_[i] = rhs.coef_[i];
    return *this;
}

double Polynimial::operator[](int rhs) const
{
    return coef_[rhs];
}

double &Polynimial::operator[](int rhs)
{
    return coef_[rhs];
}

double Polynimial::operator()(double rhs) const
{
    if (coef_.size() == 0)
        return 0;
    if (rhs == 0)
        return coef_[0];
    double result = coef_[0];
    double var = rhs;
    for (int i = 1; i < coef_.size(); i++)
    {
        result += var * coef_[i];
        var *= rhs;
    }
    return result;
}

Polynimial Polynimial::operator+() const
{
    return Polynimial(*this);
}

Polynimial Polynimial::operator-() const
{
    Polynimial new_polynimial(*this);
    for (int i = 0; i < coef_.size(); i++)
        new_polynimial.coef_[i] = -new_polynimial.coef_[i];
    return new_polynimial;
}

Polynimial &Polynimial::operator+=(const Polynimial &rhs)
{
    int t = coef_.size();
    for (int i = 0; i < t; i++)
        coef_[i] += rhs.coef_[i];
    if (t < rhs.coef_.size())
        coef_.resize(rhs.coef_.size());
    for (int i = t; i < coef_.size(); i++)
        coef_[i] = rhs.coef_[i];
    fix();
    return *this;
}

Polynimial &Polynimial::operator+=(double rhs)
{
    if (coef_.size() == 0)
    {
        if (rhs == 0)
            return *this;
        coef_.resize(1);
        coef_[0] = rhs;
        return *this;
    }
    coef_[0] += rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator++()
{
    *this += 1;
    fix();
    return *this;
}

Polynimial &Polynimial::operator-=(const Polynimial &rhs)
{
    int t = coef_.size();
    for (int i = 0; i < t; i++)
        coef_[i] -= rhs.coef_[i];
    if (t < rhs.coef_.size())
        coef_.resize(rhs.coef_.size());
    for (int i = t; i < coef_.size(); i++)
        coef_[i] = -rhs.coef_[i];
    fix();
    return *this;
}

Polynimial &Polynimial::operator-=(double rhs)
{
    if (coef_.size() == 0)
    {
        if (rhs == 0)
            return *this;
        coef_.resize(1);
        coef_[0] = -rhs;
        return *this;
    }
    coef_[0] -= rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator--()
{
    *this -= 1;
    fix();
    return *this;
}

Polynimial &Polynimial::operator*=(const Polynimial &rhs)
{
    Polynimial new_polynimial(*this);
    for (int i = 0; i < coef_.size(); i++)
        coef_[i] = 0;
    coef_.resize(coef_.size() + rhs.coef_.size(), 0);
    for (int i = 0; i < new_polynimial.coef_.size(); i++)
    {
        for (int j = 0; j < rhs.coef_.size(); j++)
            coef_[i + j] += new_polynimial.coef_[i] * rhs.coef_[j];
    }
    return *this;
}

Polynimial &Polynimial::operator*=(double rhs)
{
    for (int i = 0; i < coef_.size(); i++)
        coef_[i] *= rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator/=(const Polynimial &rhs)
{
    if (coef_.size() < rhs.coef_.size())
    {
        *this = Polynimial();
        return *this;
    }
    Polynimial temp(*this);
    coef_.resize(temp.size() - rhs.coef_.size() + 1);
    for (int i = 0; i < coef_.size() - 2; i++)
        coef_[i] = 0;
    double new_coef;
    while (temp.size() >= rhs.coef_.size())
    {
        new_coef = temp.coef_[temp.size() - 1] / rhs.coef_[rhs.coef_.size() - 1];
        coef_[temp.size() - rhs.coef_.size()] = new_coef;
        temp -= (rhs << (temp.size() - rhs.coef_.size())) * new_coef;
    }
    return *this;
}

Polynimial &Polynimial::operator/=(double rhs)
{
    for (int i = 0; i < coef_.size(); i++)
        coef_[i] /= rhs;
    return *this;
}

bool Polynimial::operator==(const Polynimial &rhs) const
{
    if (coef_.size() != rhs.coef_.size())
        return false;
    for (int i = 0; i < coef_.size(); i++)
    {
        if (coef_[i] != rhs.coef_[i])
            return false;
    }
    return true;
}

bool Polynimial::operator!=(const Polynimial &rhs) const
{
    if (coef_.size() != rhs.coef_.size())
        return false;
    for (int i = 0; i < coef_.size(); i++)
    {
        if (coef_[i] != rhs.coef_[i])
            return true;
    }
    return false;
}

Polynimial Polynimial::operator+(const Polynimial &rhs) const
{
    Polynimial new_polynimial(*this);
    if (new_polynimial.coef_.size() > rhs.coef_.size())
    {
        for (int i = 0; i < rhs.coef_.size(); i++)
            new_polynimial.coef_[i] += rhs.coef_[i];
        new_polynimial.fix();
        return new_polynimial;
    }
    else
    {
        for (int i = 0; i < new_polynimial.coef_.size(); i++)
            new_polynimial.coef_[i] += rhs.coef_[i];
        int t = new_polynimial.coef_.size();
        new_polynimial.coef_.resize(rhs.coef_.size());
        for (int i = t; i < new_polynimial.coef_.size(); i++)
            new_polynimial.coef_[i] = rhs.coef_[i];
        new_polynimial.fix();
        return new_polynimial;
    }
}

Polynimial Polynimial::operator+(double rhs) const
{
    if (coef_.size() == 0)
        return Polynimial(1, rhs);
    Polynimial new_polynimial(*this);
    new_polynimial.coef_[0] += rhs;
    new_polynimial.fix();
    return new_polynimial;
}

Polynimial Polynimial::operator++(int)
{
    Polynimial new_polynimial(*this);
    ++*this;
    return new_polynimial;
}

Polynimial Polynimial::operator-(const Polynimial &rhs) const
{
    return *this + (-rhs);
}

Polynimial Polynimial::operator-(double rhs) const
{
    return -(*this);
}

Polynimial Polynimial::operator--(int)
{
    Polynimial new_polynimial(*this);
    --*this;
    return new_polynimial;
}

Polynimial Polynimial::operator*(const Polynimial &rhs) const
{
    Polynimial new_polynimial(rhs.coef_.size() + coef_.size(), 0);
    for (int i = 0; i < coef_.size(); i++)
    {
        for (int j = 0; j < rhs.coef_.size(); j++)
            new_polynimial[i + j] += coef_[i] * rhs.coef_[j];
    }
    return new_polynimial;
}

Polynimial Polynimial::operator*(double rhs) const
{
    if (!rhs)
        return Polynimial(0, 0);
    Polynimial new_polynimial(*this);
    for (int i = 0; i < coef_.size(); i++)
        new_polynimial.coef_[i] *= rhs;
    return new_polynimial;
}

Polynimial Polynimial::operator/(const Polynimial &rhs) const
{
    if (coef_.size() < rhs.coef_.size())
        return Polynimial();
    Polynimial new_polynimial(coef_.size() - rhs.coef_.size() + 1);
    Polynimial temp(*this);
    double new_coef;
    while (temp.size() >= rhs.coef_.size())
    {
        new_coef = temp.coef_[temp.size() - 1] / rhs.coef_[rhs.coef_.size() - 1];
        new_polynimial.coef_[temp.size() - rhs.coef_.size()] = new_coef;
        temp -= (rhs << (temp.size() - rhs.coef_.size())) * new_coef;
    }
    return new_polynimial;
}

Polynimial Polynimial::operator/(double rhs) const
{
    Polynimial new_polynimial(*this);
    for (int i = 0; i < coef_.size(); i++)
        new_polynimial.coef_[i] /= rhs;
    return new_polynimial;
}

std::ostream &operator<<(std::ostream &out, const Polynimial &rhs)
{
    if (rhs.coef_.size() == 0)
    {
        out << 0;
        return out;
    }
    double t;
    if (rhs.coef_[rhs.coef_.size() - 1] < 0)
        out << "-";
    for (int i = rhs.coef_.size() - 1; i >= 1; i--)
    {
        if (rhs.coef_[i] == 0)
            continue;
        else if (i != (rhs.coef_.size() - 1))
        {
            if (rhs.coef_[i] > 0)
                out << " + ";
            else
                out << " - ";
        }
        t = abs(rhs.coef_[i]);
        if (t != 1)
            out << t << "x";
        else
            out << "x";
        if (i != 1)
            out << "^" << i;
    }
    if (rhs.coef_[0] > 0)
        out << " + " << rhs.coef_[0];
    else if (rhs.coef_[0] != 0)
        out << " - " << rhs.coef_[0];
    return out;
}

std::istream &operator>>(std::istream &in, Polynimial &rhs)
{
    int size;
    in >> size;
    rhs.coef_.resize(size);
    for (int i = 0; i < size; i++)
        in >> rhs.coef_[i];
    return in;
}

Polynimial Polynimial::operator<<(int rhs) const
{
    if (rhs <= 0)
        return *this;
    Polynimial new_polynimial(*this);
    new_polynimial.coef_.resize(coef_.size() + rhs);
    for (int i = (new_polynimial.coef_.size() - 1); i >= rhs; i--)
        new_polynimial.coef_[i] = new_polynimial.coef_[i - rhs];
    for (int i = 0; i < rhs; i++)
        new_polynimial.coef_[i] = 0;
    return new_polynimial;
}

Polynimial Polynimial::operator>>(int rhs) const
{
    if (rhs <= 0)
        return *this;
    Polynimial new_polynimial(*this);
    for (int i = 0; i <= (new_polynimial.coef_.size() - rhs); i++)
        new_polynimial.coef_[i] = new_polynimial.coef_[i + rhs];
    new_polynimial.coef_.resize(coef_.size() - rhs);
    return new_polynimial;
}

Polynimial Polynimial::derivative() const
{
    Polynimial new_polynimial(*this >> 1);
    for (int i = 0; i < new_polynimial.coef_.size(); i++)
        new_polynimial.coef_[i] *= (i + 1);
    return new_polynimial;
}

Polynimial Polynimial::primitive(double con = 0) const
{
    Polynimial new_polynimial(*this << 1);
    for (int i = 1; i < new_polynimial.coef_.size(); i++)
        new_polynimial.coef_[i] /= i;
    return (new_polynimial + con);
}

double Polynimial::root(double start, double end, double accuracy) const
{
    Polynimial temp(*this);
    if (temp(start) == 0)
        return start;
    if (temp(end) == 0)
        return end;
    end += 0.000000000000001;
    while (abs(end - start) > accuracy)
    {
        start = end - (end - start) * temp(end) / (temp(end) - temp(start));
        end = start - (start - end) * temp(start) / (temp(start) - temp(end));
    }
    return end;
}