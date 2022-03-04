#include "polynomial.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <math.h>

void Polynimial::fix()
{
    degree_ = 0;
    std::map<int, double>::iterator it = coef_.begin();
    while (it != coef_.end())
    {
        if (it->second == 0)
        {
            std::map<int, double>::iterator temp = it;
            ++it;
            coef_.erase(temp);
        }
        else if (it->first > degree_)
        {
            degree_ = it->first;
            ++it;
        }
        else
            ++it;
    }
    std::map<int, double> new_map;
    for (int i = 0; i <= degree_; ++i)
        if (coef_.count(i))
            new_map[i] = coef_[i];
    coef_ = new_map;
}

Polynimial::Polynimial() {}

Polynimial::Polynimial(unsigned size, double value = 0)
{
    for (int i = 0; i < size; i++)
        coef_[i] = value;
    if (size && !value)
        coef_[size - 1] = 1;
    degree_ = size;
}

Polynimial::Polynimial(const std::vector<double> &coef)
{
    for (int i = 0; i < coef.size(); i++)
        coef_[i] = coef[i];
    degree_ = coef_.size() - 1;
    fix();
}

Polynimial::Polynimial(const std::map<int, double> &coef)
{
    coef_ = coef;
    fix();
}

Polynimial::Polynimial(const Polynimial &new_polynimial) : coef_(new_polynimial.coef_), degree_(new_polynimial.degree_) {}

int Polynimial::degree() const
{
    return degree_;
}

Polynimial &Polynimial::operator=(const Polynimial &rhs)
{
    coef_ = rhs.coef_;
    degree_ = rhs.degree_;
    return *this;
}

double Polynimial::operator[](int rhs) const
{
    return coef_.at(rhs);
}

double &Polynimial::operator[](int rhs)
{
    return coef_[rhs];
}

double Polynimial::operator()(double rhs) const
{
    if (degree_ == 0)
        return 0;
    if (rhs == 0)
        return coef_.at(0);
    double result = 0;
    for (auto it : coef_)
        result += it.second * pow(rhs, it.first);
    return result;
}

Polynimial Polynimial::operator+() const
{
    return Polynimial(*this);
}

Polynimial Polynimial::operator-() const
{
    Polynimial new_polynimial(*this);
    for (auto &it : new_polynimial.coef_)
        it.second = -it.second;
    return new_polynimial;
}

Polynimial &Polynimial::operator+=(const Polynimial &rhs)
{
    for (auto it : rhs.coef_)
        coef_[it.first] += it.second;
    fix();
    return *this;
}

Polynimial &Polynimial::operator+=(double rhs)
{
    coef_[0] += rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator++()
{
    *this += 1;
    return *this;
}

Polynimial &Polynimial::operator-=(const Polynimial &rhs)
{
    for (auto it : rhs.coef_)
        coef_[it.first] -= it.second;
    fix();
    return *this;
}

Polynimial &Polynimial::operator-=(double rhs)
{
    coef_[0] -= rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator--()
{
    *this -= 1;
    return *this;
}

Polynimial &Polynimial::operator*=(const Polynimial &rhs)
{
    Polynimial new_polynimial(*this);
    coef_.clear();
    for (auto it : new_polynimial.coef_)
        for (auto it1 : rhs.coef_)
            coef_[it.first + it1.first] += it.second * it1.second;
    fix();
    return *this;
}

Polynimial &Polynimial::operator*=(double rhs)
{
    for (auto &it : coef_)
        it.second *= rhs;
    fix();
    return *this;
}

Polynimial &Polynimial::operator/=(const Polynimial &rhs)
{
    if (degree_ < rhs.degree_)
    {
        *this = Polynimial();
        return *this;
    }
    Polynimial temp(*this);
    coef_.clear();
    double new_coef;
    while (temp.degree_ >= rhs.degree_)
    {
        new_coef = temp.coef_[temp.degree_] / rhs.coef_.at(rhs.degree_);
        coef_[temp.degree_ - rhs.degree_] = new_coef;
        temp -= (rhs << (temp.degree_ - rhs.degree_)) * new_coef;
    }
    return *this;
}

Polynimial &Polynimial::operator/=(double rhs)
{
    for (auto &it : coef_)
        it.second /= rhs;
    return *this;
}

bool Polynimial::operator==(const Polynimial &rhs) const
{
    if (coef_.size() != rhs.coef_.size())
        return false;
    for (auto it : rhs.coef_)
        if (!coef_.count(it.first))
            return false;
    return true;
}

bool Polynimial::operator!=(const Polynimial &rhs) const
{
    return !(*this == rhs);
}

Polynimial Polynimial::operator+(const Polynimial &rhs) const
{
    Polynimial new_polynimial(*this);
    for (auto it : rhs.coef_)
        new_polynimial.coef_[it.first] += it.second;
    new_polynimial.fix();
    return new_polynimial;
}

Polynimial Polynimial::operator+(double rhs) const
{
    Polynimial new_polynimial(*this);
    new_polynimial.coef_[0] += rhs;
    new_polynimial.fix();
    return new_polynimial;
}

Polynimial Polynimial::operator++(int)
{
    Polynimial new_polynimial(++*this);
    return new_polynimial;
}

Polynimial Polynimial::operator-(const Polynimial &rhs) const
{
    return *this + (-rhs);
}

Polynimial Polynimial::operator-(double rhs) const
{
    return *this + (-rhs);
}

Polynimial Polynimial::operator--(int)
{
    Polynimial new_polynimial(*this);
    --*this;
    return new_polynimial;
}

Polynimial Polynimial::operator*(const Polynimial &rhs) const
{
    Polynimial new_polynimial;
    for (auto it : coef_)
        for (auto it1 : rhs.coef_)
            new_polynimial.coef_[it.first + it1.first] += it.second * it1.second;
    new_polynimial.fix();
    return new_polynimial;
}

Polynimial Polynimial::operator*(double rhs) const
{
    Polynimial new_polynimial(*this);
    for (auto &it : new_polynimial.coef_)
        it.second *= rhs;
    new_polynimial.fix();
    return new_polynimial;
}

Polynimial Polynimial::operator/(const Polynimial &rhs) const
{
    if (degree_ < rhs.degree_)
        return Polynimial();
    Polynimial new_polynimial;
    Polynimial temp(*this);
    double new_coef;
    while (temp.degree_ >= rhs.degree_)
    {
        new_coef = temp.coef_[temp.degree_] / rhs.coef_.at(rhs.degree_);
        new_polynimial.coef_[temp.degree_ - rhs.degree_] = new_coef;
        temp -= (rhs << (temp.degree_ - rhs.degree_)) * new_coef;
    }
    return new_polynimial;
}

Polynimial Polynimial::operator/(double rhs) const
{
    Polynimial new_polynimial(*this);
    for (auto &it : new_polynimial.coef_)
        it.second /= rhs;
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
    if (rhs.coef_.at(rhs.coef_.size() - 1) < 0)
        out << "-";
    for (int i = rhs.coef_.size() - 1; i >= 1; i--)
    {
        if (rhs.coef_.at(i) == 0)
            continue;
        else if (i != (rhs.coef_.size() - 1))
        {
            if (rhs.coef_.at(i) > 0)
                out << " + ";
            else
                out << " - ";
        }
        t = abs(rhs.coef_.at(i));
        if (t != 1)
            out << t << "x";
        else
            out << "x";
        if (i != 1)
            out << "^" << i;
    }
    if (rhs.coef_.at(0) > 0)
        out << " + " << abs(rhs.coef_.at(0));
    else if (rhs.coef_.at(0) != 0)
        out << " - " << abs(rhs.coef_.at(0));
    return out;
}

std::istream &operator>>(std::istream &in, Polynimial &rhs)
{
    int size;
    in >> size;
    for (int i = 0; i < size; i++)
        in >> rhs.coef_[i];
    return in;
}

Polynimial Polynimial::operator<<(int rhs) const
{
    if (rhs <= 0)
        return *this;
    Polynimial new_polynimial;
    for (auto &it : coef_)
        new_polynimial[it.first + rhs] = it.second;
    new_polynimial.degree_ = degree_ + rhs;
    return new_polynimial;
}

Polynimial Polynimial::operator>>(int rhs) const
{
    if (rhs <= 0)
        return *this;
    if (degree_ <= rhs)
        return Polynimial();
    Polynimial new_polynimial(*this);
    for (auto &it : coef_)
        if (it.first >= rhs)
            new_polynimial[it.first - rhs] = it.second;
    return new_polynimial;
}

Polynimial Polynimial::derivative() const
{
    Polynimial new_polynimial(*this >> 1);
    for (auto &it : new_polynimial.coef_)
        it.second *= (it.first + 1);
    return new_polynimial;
}

Polynimial Polynimial::primitive(double con = 0) const
{
    Polynimial new_polynimial(*this << 1);
    for (auto &it : new_polynimial.coef_)
        it.second /= it.first;
    return (new_polynimial + con);
}

double Polynimial::root(double start, double end, double accuracy) const
{
    Polynimial temp(*this);
    if (temp(start) == 0)
        return start;
    if (temp(end) == 0)
        return end;
    double fixer = 0.000000000000001;
    end += fixer;
    while (abs(end - start) > accuracy)
    {
        start = end - (end - start) * temp(end) / (temp(end) - temp(start));
        end = start - (start - end) * temp(start) / (temp(start) - temp(end));
        end += fixer;
    }
    return end;
}