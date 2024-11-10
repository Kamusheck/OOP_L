#include "romb.hpp"
#include "vector.hpp"
#include <cmath>

double Romb:: distance(const std::pair<double, double>&p1, const std::pair<double,double>&p2) const{
    return std::sqrt(std::pow(p2.first-p1.first,2) + std::pow(p2.second - p1.second,2));
}

void Romb:: check_equal_sides() const {
    if (ups.getsize() != 4){
        throw std::invalid_argument("Обсчитался, дорогой (или дорогая), это ромб, нужно 4 вершины");
    }
    double length = distance(ups[0], ups[1]);
    for (size_t i = 1; i < ups.getsize(); i++ ){
        if(distance(ups[i],ups[(i + 1) % ups.getsize()])!= length){
            throw std:: invalid_argument("Сторны не равны, а должны - это же ромб");
        }
    }
}