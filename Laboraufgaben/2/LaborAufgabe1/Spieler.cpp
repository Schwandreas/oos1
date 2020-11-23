#include "Spieler.hpp"

#include <cstdlib>

#include "../../../OOS1Lib/Labyrinth.hpp"


Spieler& Spieler::schritt(const Labyrinth& lab) {
    this->pos.schritt(lab);
    return *this;
}

void Spieler::orientieren(const Labyrinth& lab) {
    Position postmp = pos;
    // Eine von 4 Richtungen auswählen
    int rint = rand() % 4;
    postmp.r = Richtung(rint);
    while ((lab.getZeichenAnPos(postmp)) == MAUER) {
        rint = rand() % 4;
        postmp.r = Richtung(rint);
    }
    pos.r = Richtung(rint);
}
