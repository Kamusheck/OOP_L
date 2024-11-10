#pragma once
#include "figure.hpp"
#include "vector.hpp"

class Romb: public Figure{
private:
    Vector<std::pair<double, double>> ups; // ups-вершины
    double distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2);
    void check_equal_sides() const;

public:
    Romb() = default;
    std::pair<double, double> Center() const override; // описывает метод дочернего класса, позволянт компилятору следить за тем, чтобы метод точно переопределял его из класса родителя, даже если будет фул реализация можно будет все равно переопределить
    double Space() const override;
    void Print(std::ostream& out) const override;
    void Input(std::istream& in) override;
    Romb& operator=(const Romb& other) ;
    Romb& operator=(Romb&& other);
    bool operator==(const Figure& other) const override;
};