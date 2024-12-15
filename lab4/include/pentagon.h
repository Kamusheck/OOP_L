#pragma once
#include "figure.h"
#include <stdexcept>

template <typename T>
class Pentagon : public Figure<T> {
public:
    explicit Pentagon(const std::initializer_list<Point<T>>& points) {
        if (points.size() != 5) {
            throw std::invalid_argument("Pentagon must have exactly 5 points");
        }
        this->points = points;
    }

    T area() const override {
    T area = 0;
    size_t n = this->points.size();
    for (size_t i = 0; i < n; ++i) {
        const auto& p1 = this->points[i];
        const auto& p2 = this->points[(i + 1) % n];
        area += p1.x * p2.y - p1.y * p2.x;
    }
    return std::abs(area) / 2.0;
}

    Point<T> centroid() const override {
        T cx = 0, cy = 0;
        for (const auto& point : this->points) {
            cx += point.x;
            cy += point.y;
        }
        return Point<T>(cx / this->points.size(), cy / this->points.size());
    }

    void print(std::ostream& os) const override {
        os << "Pentagon: ";
        Figure<T>::print(os);
    }
};
