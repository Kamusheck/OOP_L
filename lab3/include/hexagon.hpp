#pragma once
#include "vector.hpp"
#include "figure.hpp"

class Hexagon: public Figure{
private:
    Vector<std::pair<double, double>> ups;

public:
    Hexagon() = default;
    std::pair<double, double> Center() const override;
    double Space() const override;
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other);
    bool operator==(const Figure& other) const override;
};
