#ifndef Pentagon_H
#define Pentagon_H

#include "shape.h"
#include "point.h"

class Pentagon : public Shape {
  public:
    Pentagon();
    Pentagon(const std::vector<Point>& vect);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;

};

#endif // Pentagon_H