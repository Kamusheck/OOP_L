#pragma once

#include "figure.h"

template <typename T>
class Hexagon : public Figure<T> {
public:
    Hexagon(const std::initializer_list<Point<T>>& points) {
        if (points.size() != 6) {
            throw std::invalid_argument("Hexagon must have exactly 6 points");
        }
        this->points = points;
    }

    T area() const override {
        T area = 0;
        for (size_t i = 0; i < 6; ++i) {
            size_t j = (i + 1) % 6;
            area += this->points[i].x * this->points[j].y - this->points[i].y * this->points[j].x;
        }
        return std::abs(area) / 2.0;
    }

    Point<T> centroid() const override {
        T cx = 0, cy = 0;
        for (const auto& point : this->points) {
            cx += point.x;
            cy += point.y;
        }
        return Point<T>(cx / 6, cy / 6);
    }

    void print(std::ostream& os) const override {
        os << "Hexagon: ";
        Figure<T>::print(os);
    }
};
