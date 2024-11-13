#include "romb.hpp"

Romb::Romb() {
    ups.resize(4); 
}
double Romb::Distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2) const {
    return std::sqrt(std::pow(p2.first - p1.first, 2) + std::pow(p2.second - p1.second, 2));
}

// Проверка равенства всех сторон ромба
void Romb::CheckEqualSides() const {
    if (ups.getsize() != 4) {
        throw std::logic_error("Ромб должен иметь 4 вершины.");
    }
    double side = Distance(ups[0], ups[1]);
    for (size_t i = 1; i < ups.getsize(); ++i) {
        if (std::abs(Distance(ups[i], ups[(i + 1) % 4]) - side) > 1e-6) {
            throw std::logic_error("Все стороны ромба должны быть равны.");
        }
    }
}

void Romb::Input(std::istream& in) {
    Method::Input(in);
    validate_vertices(4); 
    CheckEqualSides();
}





