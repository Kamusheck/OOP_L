#pragma once
#include "vector.hpp"
#include "method.hpp"

class Pentagon : public Method {
public:
    Pentagon();
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;
};