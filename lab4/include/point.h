#pragma once 

#include <cmath>
#include <iostream>
#include <concepts>
#include <stdexcept>
#include <vector>
#include <initializer_list>

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

#ifndef DOUBLE_EPS_DEFAULT
#define DOUBLE_EPS_DEFAULT 1e-9
#endif

template <Number T>
struct Point {
    T x;
    T y;

    Point() noexcept : x{}, y{} {}
    Point(T x, T y) noexcept : x(x), y(y) {}

    Point operator+(const Point &other) const noexcept {
        return Point(x + other.x, y + other.y);
    }

    Point &operator+=(const Point &other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point operator-(const Point &other) const noexcept {
        return Point(x - other.x, y - other.y);
    }

    Point &operator-=(const Point &other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Point operator-() const noexcept {
        return Point(-x, -y);
    }

    Point operator*(const T &lambda) const noexcept {
        return Point(x * lambda, y * lambda);
    }

    Point &operator*=(const T &lambda) noexcept {
        x *= lambda;
        y *= lambda;
        return *this;
    }

    T dot(const Point &other) const noexcept {
        return x * other.x + y * other.y;
    }

    T len() const noexcept {
        return std::sqrt(dot(*this));
    }

    friend Point &operator~(Point &v) noexcept {
        v.x = -v.x;
        v.y = -v.y;
        return v;
    }

    friend Point operator*(const T &lambda, const Point &v) noexcept {
        return v * lambda;
    }

    bool operator==(const Point &other) const noexcept {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const noexcept {
        return !(*this == other);
    }

    bool operator<(const Point &other) const noexcept {
        return len() < other.len();
    }

    bool operator>(const Point &other) const noexcept {
        return len() > other.len();
    }

    friend std::istream &operator>>(std::istream &in, Point &v) {
        in >> v.x >> v.y;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Point &v) {
        out << "{" << v.x << ", " << v.y << "}";
        return out;
    }
};


template <Number T>
T triangle_area(const Point<T> &a, const Point<T> &b) noexcept {
    return std::abs(a.x * b.y - a.y * b.x) / 2.0;
}

template <Number T>
bool cmp_by_len(const Point<T> &a, const Point<T> &b) noexcept {
    return a.len() < b.len();
}

template <Number T>
bool double_eq_zero(T value, T eps = DOUBLE_EPS_DEFAULT) noexcept {
    return std::abs(value) < eps;
}

template <Number T>
Point<T> intersection(const Point<T> &a, const Point<T> &b,
                      const Point<T> &c, const Point<T> &d) {
    T denominator = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
    if (double_eq_zero(denominator)) {
        throw std::logic_error("Lines do not intersect");
    }

    T x_numerator = (a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
    T y_numerator = (a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x);

    return Point<T>(x_numerator / denominator, y_numerator / denominator);
}
