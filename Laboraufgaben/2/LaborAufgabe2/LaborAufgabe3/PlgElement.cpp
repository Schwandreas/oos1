#include "PlgElement.hpp"

const Point &PlgElement::getPoint() const {
    return point;
}

void PlgElement::setPoint(const Point &point) {
    PlgElement::point = point;
}

PlgElement::~PlgElement() {
    if(next != nullptr)
        delete next;
}

PlgElement::PlgElement(const Point &point) : point(point) {}

PlgElement *PlgElement::getNext() const {
    return this->next;
}

void PlgElement::setNext(PlgElement * next) {
    this->next = next;
}

void PlgElement::print(bool addNl) {
    point.print(addNl);
}

void PlgElement::move(double dx, double dy) {
    point.move(dx, dy);
}
