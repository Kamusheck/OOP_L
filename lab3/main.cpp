#include "point.h"
#include "shape.h"
#include "vector"
#include <iostream>

int main() {
    Shape p1(std::vector<Point>{{0, 0}, {0, 1}, {1, 0}});
    std::cout << p1.area() << " " << p1.centroid() << std::endl;
    return 0;
}