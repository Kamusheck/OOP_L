#pragma once
#include "vector.hpp"
#include "figure.hpp"

class Pentagon: public Figure{
private:
    Vector<std::pair<double, double>> ups;

public:
    Pentagon() = default;
    std::pair<double, double> Center() const override;
    double Space() const override;
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other);
    bool operator==(const Figure& other) const override;
};