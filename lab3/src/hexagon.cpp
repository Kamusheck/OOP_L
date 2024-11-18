#include "shape.h"
#include "point.h"
#include "hexagon.h"

#include "hexagon.h"

Hexagon::Hexagon() : Shape() {}

Hexagon::Hexagon(const std::vector<Point>& vect) : Shape(vect) {
    validate_v(6);  
}

Hexagon::Hexagon(const Hexagon& other) : Shape(other) {}

Hexagon::Hexagon(Hexagon&& other) noexcept : Shape(std::move(other)) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        Shape::operator=(other);
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        Shape::operator=(std::move(other)); 
    }
    return *this;
}
