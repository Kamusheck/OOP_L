#include "pentagon.h"

Pentagon::Pentagon() : Shape() {}

Pentagon::Pentagon(const std::vector<Point>& vect) : Shape(vect) {
    validate_v(5);  
}

Pentagon::Pentagon(const Pentagon& other) : Shape(other) {}

Pentagon::Pentagon(Pentagon&& other) noexcept : Shape(std::move(other)) {}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        Shape::operator=(other);
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        Shape::operator=(std::move(other)); 
    }
    return *this;
}
