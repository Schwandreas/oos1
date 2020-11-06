// Main für Hausaufgabe 2
#include <memory>

#include "Labyrinth.h"

int main() {
	unique_ptr<Labyrinth> lab = make_unique<Labyrinth>(11, 11, 5);
	lab->drucken();
	lab->erzeugen();
	lab->drucken();
	lab->exportDatei("lab.txt");
	unique_ptr<Labyrinth> lab2 = make_unique<Labyrinth>();
	lab2->importDatei("lab.txt");
	lab2->drucken();
	lab2->legeMuenzen();
	lab2->drucken();
}
