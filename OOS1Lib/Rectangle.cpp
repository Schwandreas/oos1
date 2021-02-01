#include "Rectangle.hpp"

#include <iostream>
#include <sstream>

Rectangle::Rectangle(std::string& instr) {
    std::istringstream stream(instr);
    char c;
    Point tmpP1;
    Point tmpP2;

    stream >> c;
    stream >> tmpP1;
    stream >> c;
    stream >> tmpP2;

    this->p1 = tmpP1;
    this->p2 = tmpP2;
}

void Rectangle::print(bool b) const {
    std::cout << "[";
    p1.print(false);
    std::cout << ", ";
    p2.print(false);
    std::cout << "]";
    if (b)
        std::cout << std::endl;
}
