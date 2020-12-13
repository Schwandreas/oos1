#pragma once
#include "Point.hpp"

class Circle {
    Point centre;
    double radius;

public:
    Circle(double x = 0, double y = 0, double radius = 0) : Circle(Point(x, y), radius) {}

    Circle(Point centre, double radius = 0) : centre(centre), radius(radius) {}

    Circle(std::string& str);

    Point& getCentre() { return centre; }
    void setCentre(const Point& centre) { Circle::centre = centre; }

    double getRadius() const { return radius; }
    void setRadius(double radius) { Circle::radius = radius; }

    void move(double dx, double dy);
    void print(bool addNl = true) const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& stream, Circle& c);
};
