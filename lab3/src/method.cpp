#include "figure.hpp"

class Method : public Figure {

    void Print(std::ostream& out) const {
         out << "Romb ups: ";
         for (int i = 0; i < ups.getsize(); ++i){
             out << "(" << ups[i].first << ", " << ups[i].second << ") ";
         }
    };

    void Input(std::istream& in) {
        for (int i = 0; i < ups.getsize(); ++i){
            in >> ups[i].first >> ups[i].second;
        }
        validate_vertices(ups.getsize());
    }


protected:
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

    std::pair<double, double> calculate_center() const {
        double x_summa = 0, y_summa = 0;
        for (int i = 0; i < ups.getsize(); ++i)  {
            x_summa += ups[i].first;
            y_summa += ups[i].second;
        }
        return {x_summa / ups.getsize(), y_summa / ups.getsize()};
    }


    // Проверка, что вершины уникальны и все тройки вершин неколлинеарны
    void validate_vertices(int expected_count) const {
        if (ups.getsize() != expected_count) {
            throw std::invalid_argument("Invalid number of vertices.");
        }

        std::set<std::pair<double, double>> unique_ups;
        size_t n = ups.getsize();
        
        for (size_t i = 0; i < n; ++i) {
            // Проверка уникальности
            if (!unique_ups.insert(ups[i]).second) {
                throw std::invalid_argument("Vertices must be unique.");
            }
            // Проверка коллинеарности с другими вершинами
            for (size_t j = i + 1; j < n; ++j) {
                for (size_t k = j + 1; k < n; ++k) {
                    if (are_three_points_collinear(ups[i], ups[j], ups[k])) {
                        throw std::invalid_argument("No three vertices should be collinear.");
                    }
                }
            }
        }
    }

    // Проверка, коллинеарны ли три точки
    bool are_three_points_collinear(const std::pair<double, double>& p1,
                                     const std::pair<double, double>& p2,
                                     const std::pair<double, double>& p3) const {
        return std::abs((p2.second - p1.second) * (p3.first - p1.first) -
                        (p3.second - p1.second) * (p2.first - p1.first)) < 1e-6;
    } 
};