#pragma once
#include "Point.hpp"

class PlgElement {
    Point point;
    PlgElement* next = nullptr;

public:
    ~PlgElement();

    PlgElement(const Point point);

    PlgElement* getNext() const;

    void setNext(PlgElement* next);

    const Point& getPoint() const;

    void setPoint(const Point& point);

    void print(bool addNl = true) const;

    void move(double dx, double dy);

    std::string toString() const;
};
