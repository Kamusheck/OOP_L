#include "pentagon.hpp"

Pentagon::Pentagon() {
    ups.resize(5); 
}

void Pentagon::Input(std::istream& in) {
    Method::Input(in);
    validate_vertices(5); 
}