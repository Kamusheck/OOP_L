#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>
#include "point.h"

class Figure {
  public:
    virtual Point centroid() const = 0;

    virtual double area() const noexcept = 0;

    virtual operator double() const noexcept = 0;

    virtual ~Figure() = 0;

    friend std::istream &operator>>(std::istream &is, Figure &figure) {
        figure.read_from_stream(is);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure) {
        figure.print_in_stream(os);
        return os;
    }

  protected:
    virtual std::istream &read_from_stream(std::istream &) = 0;

    virtual std::ostream &print_in_stream(std::ostream &) const = 0;
};

#endif // FIGURE_H