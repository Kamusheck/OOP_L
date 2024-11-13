#pragma once
#include "vector.hpp"
#include "method.hpp"

class Hexagon : public Method {
public:
    Hexagon();
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;
};
