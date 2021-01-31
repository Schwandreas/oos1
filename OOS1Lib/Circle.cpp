
#include "Circle.hpp"


#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>

void Circle::move(double dx, double dy) {
    centre.move(dx, dy);
}

void Circle::print(bool addNl) const {
    std::cout << toString();
    if (addNl)
        std::cout << std::endl;
}

std::string Circle::toString() const {
    std::ostringstream stream;
    stream << std::setprecision(1) << std::fixed << "<" << centre.toString()
        << ", " << radius << ">";
    return stream.str();
}


Circle::Circle(std::string& str) {
    std::istringstream stream(str);
    char c;

    stream >> c;
    stream >> centre;
    stream >> c;
    stream >> radius;
}

std::ostream& operator<<(std::ostream& stream, Circle& c) {
    return stream << c.toString();
}

Circle::~Circle() {
    if (debugConstructor)
        std::cout << "Destruktor der Klasse <Circle>, Object: <" << getId() << ">" << std::endl;
}

Circle::Circle(Point centre, double radius) : centre(centre), radius(radius) {
    if (debugConstructor)
        std::cout << "Konstruktor der Klasse <Circle>, Object: <" << getId() << ">" << std::endl;
}

MyData* Circle::clone() const {
    Circle* c = new Circle(*this);
    return c;
}

Circle::Circle(const Circle& circle) : radius(circle.radius)
{
    centre = Point(circle.centre.getX(), circle.centre.getY());
    if (debugConstructor)
        std::cout << "Copy Konstruktor der Klasse <Circle>, Object: <" << getId() << ">" << std::endl;
}
