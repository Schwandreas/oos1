#pragma once
#include <string>

#include "PlgElement.hpp"
#include "Point.hpp"

class Polygonline {
    PlgElement* start = nullptr, * end = nullptr;

public:
    Polygonline() {};
    Polygonline(Point p1);
    Polygonline(std::string& str);

    PlgElement* getStart() const;
    PlgElement* getEnd() const;

    Polygonline& addPoint(Point point);
    void appendPolygonline(Polygonline polygonline);

    void print(bool addNl = true) const;
    void move(double dx, double dy);

    std::string toString() const;

    Polygonline& operator+(const Point& p);
    Polygonline& operator+(const Polygonline& p);

    friend std::ostream& operator<<(std::ostream& stream, const Polygonline& line);
};
