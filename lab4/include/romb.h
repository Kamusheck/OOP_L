#pragma once
#include "figure.h"
#include <stdexcept>

template <typename T>
class Rhombus : public Figure<T> {
public:
    explicit Rhombus(const std::initializer_list<Point<T>>& points) {
        if (points.size() != 4) {
            throw std::invalid_argument("Rhombus must have exactly 4 points");
        }
        this->points = points;

        auto side1 = (this->points[0] - this->points[1]).len();
        auto side2 = (this->points[1] - this->points[2]).len();
        auto side3 = (this->points[2] - this->points[3]).len();
        auto side4 = (this->points[3] - this->points[0]).len();
        if (!(std::abs(side1 - side2) < 1e-9 && std::abs(side2 - side3) < 1e-9 && std::abs(side3 - side4) < 1e-9)) {
            throw std::logic_error("All sides of a rhombus must be equal");
        }
    }

    T area() const override {
        T d1 = (this->points[0] - this->points[2]).len();
        T d2 = (this->points[1] - this->points[3]).len();
        return (d1 * d2) / 2.0;
    }

    Point<T> centroid() const override {
        T cx = 0, cy = 0;
        for (const auto& point : this->points) {
            cx += point.x;
            cy += point.y;
        }
        return Point<T>(cx / 4, cy / 4);
    }

    void print(std::ostream& os) const override {
        os << "Rhombus: ";
        Figure<T>::print(os);
    }
};
