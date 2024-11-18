#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"
#include "point.h"

class Hexagon : public Shape {
  public:
    Hexagon();
    Hexagon(const std::vector<Point>& vect);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;

};

#endif // HEXAGON_H