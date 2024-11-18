#include "romb.h"

Romb::Romb() : Shape() {}

Romb::Romb(const std::vector<Point>& vect) : Shape(vect) {
    validate_ups(4);
    check_equal_sides();  
}

Romb::Romb(const Romb& other) : Shape(other) {}

Romb::Romb(Romb&& other) noexcept : Shape(std::move(other)) {}

Romb& Romb::operator=(const Romb& other) {
    if (this != &other) {
        Shape::operator=(other);
    }
    return *this;
}

Romb& Romb::operator=(Romb&& other) noexcept {
    if (this != &other) {
        Shape::operator=(std::move(other)); 
    }
    return *this;
}


void Romb::check_equal_sides() const {
    if (points.size() != 4) {
        throw std::logic_error("Error: A Romb must have exactly 4 points.");
    }

    auto distance_squared = [](const Point& p1, const Point& p2) {
        return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
    };

    double side1 = distance_squared(points[0], points[1]);
    double side2 = distance_squared(points[1], points[2]);
    double side3 = distance_squared(points[2], points[3]);
    double side4 = distance_squared(points[3], points[0]);

    if (side1 != side2 || side2 != side3 || side3 != side4) {
        throw std::logic_error("Error: All sides of a Romb must be equal.");
    }
}