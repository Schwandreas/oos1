#pragma once
#include "../Hausaufgaben/3/Aufgabe1/ObjectCounter.hpp"
bool debugConstructor = true;

class DrawingObject : public ObjectCounter {
public:
    virtual void print(bool = false) const = 0;
};