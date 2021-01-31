#pragma once
#include "Point.hpp"

class Circle: public OneDimObject, public MyData {
    Point centre;
    double radius;

public:
    MyData* clone() const override;

    Circle(Point centre, double radius = 0);
    Circle(double x = 0, double y = 0, double radius = 0) : Circle(Point(x, y), radius) {}
    Circle(std::string& str);
    Circle(const Circle& circle);
    ~Circle();

    Point& getCentre() { return centre; }
    void setCentre(const Point& centre) { Circle::centre = centre; }

    double getRadius() const { return radius; }
    void setRadius(double radius) { Circle::radius = radius; }

    void move(double dx, double dy);
    void print(bool addNl = true) const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& stream, Circle& c);
};
