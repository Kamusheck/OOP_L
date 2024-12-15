#pragma once

#include "shape.h"


template <typename T>
class Figure : public Shape<T> {
protected:
    std::vector<Point<T>> points;

public:
    virtual ~Figure() = default;

    void add_point(const Point<T>& point) {
        points.push_back(point);
    }

    virtual T area() const override = 0;

    virtual Point<T> centroid() const override = 0;

    bool operator==(const Shape<T>& other) const override {
        const auto* other_figure = dynamic_cast<const Figure<T>*>(&other);
        if (!other_figure) return false;
        return points == other_figure->points;
    }

    bool operator!=(const Shape<T>& other) const override {
        return !(*this == other);
    }

    void print(std::ostream& os) const override {
        os << "Figure with points: ";
        for (const auto& point : points) {
            os << point << " ";
        }
    }
};
