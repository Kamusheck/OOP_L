#pragma once
#include "vector.hpp"
#include "method.hpp"

class Romb : public Method {
private:
   double Distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2) const;
    void CheckEqualSides() const;

public:
    Romb();
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;

private:
    void validate_vertices(int vertex_count) const;
};
