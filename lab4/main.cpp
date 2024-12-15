#include "hexagon.h"
#include "pentagon.h"
#include "romb.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    using T = double;

    auto hexagon = std::make_shared<Hexagon<T>>(Hexagon<T>{{Point<T>(0, 0), Point<T>(1, 0), Point<T>(1.5, 1), Point<T>(1, 2), Point<T>(0, 2), Point<T>(-0.5, 1)}});
    auto pentagon = std::make_shared<Pentagon<T>>(Pentagon<T>{{Point<T>(0, 0), Point<T>(2, 0), Point<T>(2.5, 1), Point<T>(1, 2), Point<T>(-0.5, 1)}});
    auto rhombus = std::make_shared<Rhombus<T>>(Rhombus<T>{{Point<T>(0, 0), Point<T>(1, 2), Point<T>(2, 0), Point<T>(1, -2)}});

    std::vector<std::shared_ptr<Figure<T>>> figures = {hexagon, pentagon, rhombus};

    for (const auto& figure : figures) {
        std::cout << *figure << "\n";
        std::cout << "Area: " << figure->area() << "\n";
        std::cout << "Centroid: " << figure->centroid() << "\n\n";
    }

    return 0;
}
