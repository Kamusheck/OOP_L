#include "shape.h"
#include "point.h"

Shape::Shape() {}

Shape::Shape(const std::vector<Point>& vect) : points(vect) {}

Shape::Shape(const Shape& other) : points(other.points) {}

Shape::Shape(Shape&& other) noexcept : points(std::move(other.points)) {}


Shape& Shape::operator=(const Shape& other) {
    if (this != &other) {
        points = other.points;
    }
    return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept {
    if (this != &other) {
        points = std::move(other.points);
    }
    return *this;
}

bool Shape::operator==(const Shape& other) const noexcept {
    if (points.size() != other.points.size()) return false;
    return std::equal(points.begin(), points.end(), other.points.begin());
}

Point Shape::centroid() const {
    Point result(0.0, 0.0);
    for (const auto& p : points) {
        result += p;
    }
    return result * (1.0 / points.size());
}

double Shape::area() const noexcept {
    double total_area = 0.0;
    size_t n = points.size();
    for (size_t i = 1; i < n - 1; ++i) {
        total_area += triangle_area(points[i] - points[0], points[i + 1] - points[0]);
    }
    return total_area;
}

Shape::operator double() const noexcept {
    return area();
}

std::istream& Shape::read_from_stream(std::istream& in) {
    Point point;
    while (in >> point) {
        points.push_back(point);
    }
    validate_v(3);
    return in;
}

// Вывод в поток
std::ostream& Shape::print_in_stream(std::ostream& out) const {
    out << '(';
    for (const auto& point : points) {
        out << point << " ";
    }
    out << ')';
    return out;
}


bool Shape::collinearnost(const Point& p1, const Point& p2, const Point& p3) const {
    return std::abs((p2.y - p1.y) * (p3.x - p1.x) - (p3.y - p1.y) * (p2.x - p1.x)) < 1e-6;
}


void Shape::validate_v(int expected_count) {
    if (points.size() != expected_count) {
        throw std::invalid_argument("Error: Shape must have exactly " + std::to_string(expected_count) + " points.");
    }

    std::set<Point> unique_points(points.begin(), points.end());
    if (unique_points.size() < expected_count) {
        throw std::invalid_argument("Shape must have unique vertices.");
    }

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            for (size_t k = j + 1; k < points.size(); ++k) {
                if (collinearnost(points[i], points[j], points[k])) {
                    throw std::invalid_argument("No three vertices should be collinear.");
                }
            }
        }
    }
}

std::istream& operator>>(std::istream& in, Shape& shape) {
    return shape.read_from_stream(in);
}

std::ostream& operator<<(std::ostream& out, const Shape& shape) {
    return shape.print_in_stream(out);
}
