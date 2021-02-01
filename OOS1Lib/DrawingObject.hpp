#pragma once
#include "../Hausaufgaben/3/Aufgabe1/ObjectCounter.hpp"
bool debugConstructor = true;

class DrawingObject : public ObjectCounter {
public:
    virtual void print(bool = false) const = 0;

    void check() const;

    int getId() const override;

    class GraphException {
    protected:
        const int id;
    public:
        GraphException(int id) : id(id) {};
    };

    class IdToohigh : public GraphException {
    public:
        IdToohigh(int id);
        int getId() const { return id; }
    };
};