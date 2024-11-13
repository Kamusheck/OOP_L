#pragma once
#include "figure.hpp"

class Method : public Figure {
public:
    std::pair<double, double> Center() const override { 
        return calculate_center(); 
    }

    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;

    double Space() const {
        double area = 0;
        size_t n = ups.getsize();
        for (size_t i = 0; i < n; ++i) {
            auto [x1, y1] = ups[i];
            auto [x2, y2] = ups[(i + 1) % n];
            area += (x1 * y2 - y1 * x2);
        }
        return std::abs(area) / 2.0;
    }
   

protected:

    std::pair<double, double> calculate_center() const ;

    // Проверка, что вершины уникальны и все тройки вершин неколлинеарны
    void validate_vertices(int expected_count) const ;

    // Проверка, коллинеарны ли три точки
    bool are_three_points_collinear(const std::pair<double, double>& p1,
                                     const std::pair<double, double>& p2,
                                     const std::pair<double, double>& p3) const; 
};