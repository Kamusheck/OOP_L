#pragma once
#include <vector>
#include <set>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "point.h"

class Shape {
protected:
    std::vector<Point> points;

    bool collinearnost(const Point& p1, const Point& p2, const Point& p3) const;

    void validate_ups(int expected_count);

public:
    Shape();
    explicit Shape(const std::vector<Point>& vect);

    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;

    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other) noexcept;

    bool operator==(const Shape& other) const noexcept;

    Point geom_centr() const;
    double area() const noexcept;
    operator double() const noexcept;

    std::istream& read_from_stream(std::istream& in);
    std::ostream& print_in_stream(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Shape& shape);
std::ostream& operator<<(std::ostream& out, const Shape& shape);
