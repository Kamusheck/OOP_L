#include "point.h"

bool equal_between(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) < epsilon;
}

Point::Point() noexcept : x{0}, y{0} {}

Point::Point(double x, double y) noexcept : x(x), y(y) {}

Point Point::operator+(const Point &other) const noexcept {
    Point tmp = *this;
    return tmp += other;
}

Point &Point::operator+=(const Point &other) noexcept {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Point Point::operator-(const Point &other) const noexcept {
    Point tmp = *this;
    return tmp -= other;
}

Point &Point::operator-=(const Point &other) noexcept {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Point Point::operator-() const noexcept {
    Point tmp = *this;
    return ~tmp;
}

Point Point::operator*(const double &lambda) const noexcept {
    Point tmp = *this;
    return tmp *= lambda;
}

Point operator*(double lambda, const Point &v) noexcept {
    return v * lambda;
}

Point &Point::operator*=(const double &lambda) noexcept {
    this->x *= lambda;
    this->y *= lambda;
    return *this;
}

double Point::dot(const Point &other) const noexcept {
    return (this->x * other.x) + (this->y * other.y);
}

double Point::len() const noexcept { return sqrt(this->dot(*this)); }

Point &operator~(Point &v) noexcept {
    v.x = -v.x;
    v.y = -v.y;
    return v;
}

bool Point::operator==(const Point &other) const noexcept {
    return equal_between(this->x, other.x) && equal_between(this->y, other.y);
}

bool Point::operator!=(const Point &other) const noexcept {
    return !(*this == other);
}

bool Point::operator<(const Point &other) const noexcept {
    if (!equal_between(this->x, other.x)) {
        return this->x < other.x;
    }
    return this->y < other.y;
}

bool Point::operator>(const Point &other) const noexcept {
    if (!equal_between(this->x, other.x)) {
        return this->x > other.x;
    }
    return this->y > other.y;
}

double triangle_area(const Point &a, const Point &b) noexcept {
    return abs(((a.x * b.y) - (a.y * b.x))) / 2.0;
}


bool cmp_by_len(const Point &a, const Point &b) noexcept {
    return a.len() < b.len();
}

std::istream &operator>>(std::istream &in, Point &f) {
    in >> f.x >> f.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &f) {
    out << '{' << f.x << ", " << f.y << '}';
    return out;
}
