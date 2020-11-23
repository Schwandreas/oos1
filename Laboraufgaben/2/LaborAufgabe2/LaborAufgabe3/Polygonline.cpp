#include "Polygonline.hpp"

#include <iomanip>
#include <iostream>

Polygonline::Polygonline(Point p1) : Polygonline() {
    addPoint(p1);
}

Polygonline & Polygonline::addPoint(Point point) {

    PlgElement * newElement = new PlgElement(point);
    if(start == nullptr)
    {
        start = newElement;
        end = newElement;
        return * this;
    }

    PlgElement * curEnd = end;
    curEnd->setNext(newElement);
    end = newElement;
    return *this;
}

void Polygonline::print(bool addNl) {
    std::setprecision(1);
    std::cout << "|";

    PlgElement * next = start;
    while(next != nullptr)
    {
        next->print(false);
        next = next->getNext();
        if(next != nullptr)
            std::cout << " - ";
    }

    std::cout << "|";
    if(addNl)
        std::cout << std::endl;
}

void Polygonline::appendPolygonline(Polygonline polygonline) {
    PlgElement * next = polygonline.getStart();
    while(next != nullptr)
    {
        addPoint(next->getPoint());
        next = next->getNext();
    }
}

void Polygonline::move(double dx, double dy) {
    PlgElement * next = start;
    while(next != nullptr)
    {
        next->move(dx, dy);
        next = next->getNext();
    }
}

PlgElement *Polygonline::getStart() {
    return start;
}

PlgElement *Polygonline::getEnd() {
    return end;
}
