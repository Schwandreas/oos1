
#include "Polygonline.hpp"


#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>


#include "PlgElement.cpp"
#include "Point.hpp"

Polygonline::Polygonline(Point p1) {
    addPoint(p1);
}

Polygonline& Polygonline::addPoint(Point point) {

    PlgElement* newElement = new PlgElement(point);
    if (start == nullptr)
    {
        start = newElement;
        end = newElement;
        return *this;
    }

    PlgElement* curEnd = end;
    curEnd->setNext(newElement);
    end = newElement;
    return *this;
}

void Polygonline::print(bool addNl) const {
    std::cout << toString();

    if (addNl)
        std::cout << std::endl;
}

void Polygonline::appendPolygonline(Polygonline polygonline) {
    PlgElement* next = polygonline.getStart();
    while (next != nullptr)
    {
        addPoint(next->getPoint());
        next = next->getNext();
    }
}

void Polygonline::move(double dx, double dy) {
    PlgElement* next = start;
    while (next != nullptr)
    {
        next->move(dx, dy);
        next = next->getNext();
    }
}

PlgElement* Polygonline::getStart() const {
    return start;
}

PlgElement* Polygonline::getEnd() const {
    return end;
}

std::string Polygonline::toString() const {
    std::ostringstream stream;
    stream << std::setprecision(1) << std::fixed;
    stream << "|";

    PlgElement* next = start;
    while (next != nullptr)
    {
        stream << next->toString();
        next = next->getNext();
        if (next != nullptr)
            stream << " - ";
    }
    stream << "|";

    return stream.str();
}

Polygonline::Polygonline(std::string& str) {
    std::istringstream stream(str);
    char c;
    bool end = false;

    stream >> c;
    while (!end)
    {
        Point* p = new Point();
        stream >> *p;
        addPoint(*p);
        delete p;

        stream >> c;
        if (!stream || c == '|' || stream.peek() == '|')
            end = true;
    }
}

std::ostream& operator<<(std::ostream& stream, const Polygonline& p) {
    return stream << p.toString();
}

Polygonline& Polygonline::operator+(const Point& p) {
    addPoint(p);
    return *this;
}

Polygonline& Polygonline::operator+(const Polygonline& p) {
    appendPolygonline(p);
    return *this;
}