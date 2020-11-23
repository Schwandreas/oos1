#ifndef LABOR2_SPIELER
#define LABOR2_SPIELER

#include "../../../OOS1Lib/MyString.hpp"
#include "../../../OOS1Lib/Position.hpp"


class Spieler {
    MyString name;
    Position pos;
    int muenzen = 0;

public:
    //Constructor
    Spieler(const MyString& name) : name(name) {};
    Spieler(const char* name) : name(name) {};

    //Setter
    void setPos(const Position& pos) { this->pos = pos; }
    void setRichtung(const Richtung& richtung) { this->pos.r = richtung; }

    //Getter
    int getMuenzen() { return muenzen; }
    Position& getPos() { return this->pos; }

    void plusMuenze() { muenzen++; }
    Spieler& schritt(const Labyrinth& lab);
    void orientieren(const Labyrinth& lab);
};

#endif
