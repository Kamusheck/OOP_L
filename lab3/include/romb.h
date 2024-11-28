#ifndef Romb_H
#define Romb_H

#include "shape.h"
#include "point.h"

class Romb : public Shape {
  public:
    Romb();
    Romb(const std::vector<Point>& vect);
    Romb(const Romb &other);
    Romb(Romb &&other) noexcept;
    Romb &operator=(const Romb &other);
    Romb &operator=(Romb &&other) noexcept;
    
    void check_equal_sides() const;
    //
};

#endif // Romb_H