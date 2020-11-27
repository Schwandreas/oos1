#include "Point.hpp"

#include <iomanip>
#include <iostream>

void Point::print(bool addNl) {
    std::setprecision(1);

    std::cout << "(" << x << ", " << y << ")";

    if(addNl)
        std::cout << std::endl;
}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}
