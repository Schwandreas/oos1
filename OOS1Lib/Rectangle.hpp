#pragma once
#include "OneDimObject.hpp"
#include "Point.hpp"

class Rectangle : public OneDimObject {
    Point p1, p2;

public:
    Rectangle() : p1(Point(0, 0)), p2(Point(1, 1)) {}
    Rectangle(Point p1, Point p2) : p1(p1), p2(p2) {}
    Rectangle(std::string& instr);

private:
    void print(bool b) const override;
};
