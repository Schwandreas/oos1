#include <iostream>
#include "DrawingObject.hpp"
DrawingObject::IdToohigh::IdToohigh(int id) : GraphException(id) {}

void DrawingObject::check() const {
    if (ObjectCounter::getId() > this->getMaxId())
        throw IdToohigh(ObjectCounter::getId());
}

int DrawingObject::getId() const
{
    this->check();
    return ObjectCounter::getId();
}
