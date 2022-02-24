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
     * @param _coef Вектор с коэффициентами
     */
    Polynimial(const std::vector<double> &_coef);
    Polynimial(const Polynimial &polynimial);
    ~Polynimial() {}
    /**
     * @brief Возвращает степень полинома
     *
     * @return int Степень полинома
     */
    int size();
    Polynimial &operator=(const Polynimial &rhs);
    double operator[](int rhs) const;
    double &operator[](int rhs);
    /**
     * @brief Возращает текущий полином
     *
     * @return Polynimial Текущий полином
     */
    Polynimial operator+() const;
    /**
     * @brief Возращает текущий полином с отрицательным коэффициентами
     *
     * @return Polynimial Изменённый полином
     */
    Polynimial operator-() const;
    /**
     * @brief Прибавляет к текущему полиному заданный полином
     *
     * @param rhs Полином
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator+=(const Polynimial &rhs);
    /**
     * @brief Прибавляет к текущему полиному заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator+=(double rhs);
    /**
     * @brief Прибавляет к текущему полиному 1
     *
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator++();
    /**
     * @brief Отнимает от текущего полинома заданный полином
     *
     * @param rhs Полином
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator-=(const Polynimial &rhs);
    /**
     * @brief Отнимает от текущего полинома заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator-=(double rhs);
    /**
     * @brief Отнимает от текущего полинома 1
     *
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator--();
    /**
     * @brief Умножает текущий полином на заданный полином
     *
     * @param rhs Полином
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator*=(const Polynimial &rhs);
    /**
     * @brief Умножает текущий полином на заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator*=(double rhs);
    /**
     * @brief Делит текущий полином на заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator/=(double rhs);
    /**
     * @brief Проверяет равны ли текущий и заданный полином
     *
     * @param rhs Полином
     * @return true Если равны
     * @return false Если не равны
     */
    bool operator==(const Polynimial &rhs) const;
    /**
     * @brief Проверяет не равны ли текущий и заданный полином
     *
     * @param rhs Полином
     * @return true Если не равны
     * @return false Если равны
     */
    bool operator!=(const Polynimial &rhs) const;
    /**
     * @brief Возвращает сумму текущего и заданного полинома
     *
     * @param rhs Полином
     * @return Polynimial Новый полином
     */
    Polynimial operator+(const Polynimial &rhs) const;
    /**
     * @brief Возвращает сумму текущего полинома и заданного числа
     *
     * @param rhs Число
     * @return Polynimial Новый полином
     */
    Polynimial operator+(double rhs) const;
    /**
     * @brief Прибавляет к текущему полиному 1
     *
     * @return Polynimial Неизменённый полином
     */
    Polynimial operator++(int);
    /**
     * @brief Возвращает разность текущего и заданного полинома
     *
     * @param rhs Полином
     * @return Polynimial Новый полином
     */
    Polynimial operator-(const Polynimial &rhs) const;
    /**
     * @brief Возвращает разность текущего полинома и заданного числа
     *
     * @param rhs Число
     * @return Polynimial Новый полином
     */
    Polynimial operator-(double num) const;
    /**
     * @brief Отнимает от текущего полинома 1
     *
     * @return Polynimial Неизменённый полином
     */
    Polynimial operator--(int);
    /**
     * @brief Возвращает произведение текущего и заданного полинома
     *
     * @param rhs Полином
     * @return Polynimial Новый полином
     */
    Polynimial operator*(const Polynimial &rhs) const;
    /**
     * @brief Возвращает произведение текущего полинома и заданного числа
     *
     * @param rhs Число
     * @return Polynimial Новый полином
     */
    Polynimial operator*(double rhs) const;
    /**
     * @brief Возвращает отеошение текущего полинома и заданного числа
     *
     * @param rhs Число
     * @return Polynimial Новый полином
     */
    Polynimial operator/(double rhs) const;
    /**
     * @brief Выводит полином в заданный поток
     *
     * @param out Поток вывода
     * @param rhs Полином
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &out, const Polynimial &rhs);
    /**
     * @brief Ввод полинома через заданный поток
     *
     * @param in Поток ввода
     * @param rhs Полином
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &in, Polynimial &rhs);
    /**
     * @brief Увеличивает степень полинома на заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator<<(int rhs);
    /**
     * @brief Уменьшает степень полинома на заданное число
     *
     * @param rhs Число
     * @return Polynimial& Ссылка на изменённый полином
     */
    Polynimial &operator>>(int rhs);
};