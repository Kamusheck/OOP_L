#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

struct Point {
 
    double x;
    double y;

    Point() noexcept;
    Point(double x, double y) noexcept;

    Point operator+(const Point &other) const noexcept;
    Point &operator+=(const Point &other) noexcept;
    Point operator-(const Point &other) const noexcept;
    Point &operator-=(const Point &other) noexcept;
    Point operator-() const noexcept;

    Point operator*(const double &labmda) const noexcept;
    Point &operator*=(const double &labmda) noexcept;

    double dot(const Point &other) const noexcept;

    double len() const noexcept;

    friend Point &operator~(Point &v) noexcept;


    bool operator==(const Point &other) const noexcept;

    bool operator!=(const Point &other) const noexcept;

    bool operator<(const Point &other) const  noexcept;

    bool operator>(const Point &other) const  noexcept;
};

Point operator*(double lambda, const Point &v) noexcept;

double triangle_area(const Point &a, const Point &b) noexcept;



bool cmp_by_len(const Point &a, const Point &b) noexcept;

std::istream &operator>>(std::istream &in, Point &f);

std::ostream &operator<<(std::ostream &out, const Point &f);


#endif // POINT_H