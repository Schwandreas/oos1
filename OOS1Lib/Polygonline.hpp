#pragma once
#include <string>

#include "PlgElement.hpp"
#include "Point.hpp"

class Polygonline : public OneDimObject {
    PlgElement* start = nullptr, * end = nullptr;

public:
    Polygonline() {
        if (debugConstructor)
            std::cout << "Konstruktor der Klasse <Polygonline>, Object: <" << getId() << ">" << std::endl;
    };
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
    ~Polygonline();

    friend std::ostream& operator<<(std::ostream& stream, const Polygonline& line);
};
