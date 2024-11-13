#include "hexagon.hpp"

Hexagon::Hexagon() {
    ups.resize(6); 
}

void Hexagon::Input(std::istream& in) {
    Method::Input(in);
    validate_vertices(6); 
}