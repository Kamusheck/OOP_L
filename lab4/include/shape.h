#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "point.h"

template <typename T>
class Shape {
public:
    virtual ~Shape() = default;

    virtual T area() const = 0;
    virtual Point<T> centroid() const = 0;

    virtual bool operator==(const Shape<T>& other) const = 0;
    virtual bool operator!=(const Shape<T>& other) const = 0;

    virtual void print(std::ostream& os) const = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Shape<T>& shape) {
    shape.print(os);
    return os;
}
