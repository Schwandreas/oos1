// Bibliothek.hpp
#pragma once

#include "Buch.hpp"
#include "DVD.hpp"
#include "Person.hpp"
#include "Datum.hpp"

// Die Klasse Bibliothek verweist auf alle Medien (Bücher und DVDs),
// die von Personen (Studierende und Dozenten) ausgeliehen werden 
// können.
class Bibliothek {
	// Anzahl der in der im Bibliothekskatalog verzeichneten Medien
	int anz = 0;
	// maximale Anzahl der Medien im Katalog
	const int maxAnz;
	// Zeiger auf das Array der Zeiger auf die Medien im Katalog
	// Deshalb wird hier ein Doppelzeiger genutzt.
	Medium ** medien;
public:
	// Standardkonstruktor
	Bibliothek(int maxAnz = 1000);
	// Destruktor
	~Bibliothek();
	// Kopie eines Buches in den Katalog der Bibliothek eintragen
	void mediumBeschaffen(Buch &);
	// Kopie einer DVD in den Katalog der Bibliothek eintragen
	void mediumBeschaffen(DVD &);
	// alle Medien auf der Konsole ausgeben, 
	// die im Titel das Suchwort enthalten
	void mediumSuchen(string suchwort);
	// im Medium mit der Nummer nr, die Person p als Ausleiher
	// eintragen mit von-Datum d und bis-Datum d+p.ausleihdauer
	void mediumAusleihen(int nr, Person & p, Datum d);
	// alle Medien in der Konsole ausgeben
	void print() const;
};

Bibliothek::Bibliothek(int maxAnz) : maxAnz(maxAnz) {
	medien = new Medium*[maxAnz];
}

Bibliothek::~Bibliothek() {
    for (int i = 0; i < anz; ++i) {
        delete medien[i];
    }

    delete[] medien;
}

void Bibliothek::mediumBeschaffen(Buch & inputBuch) {
    Buch * b = new Buch(inputBuch.getTitel(), inputBuch.getAutor(), inputBuch.getVerlag(), inputBuch.getJahr());
    medien[anz++] = b;
}

void Bibliothek::mediumBeschaffen(DVD & inputDvd) {
    DVD * d =  new DVD(inputDvd.getTitel(), inputDvd.getVerlag(), inputDvd.getJahr(), inputDvd.getDauer());
    medien[anz++] = d;
}

inline void Bibliothek::mediumSuchen(string suchwort) {
	cout << endl << "Suche nach \"" << suchwort << "\. Ergebnis:" << endl << endl;

    for (int i = 0; i < anz; ++i) {
        if(medien[i]->getTitel().find(suchwort) != std::string::npos)
        {
			cout << "Medium " << i << ":" << endl;
	        medien[i]->print();
        }
    }
}

void Bibliothek::mediumAusleihen(int nr, Person &p, Datum d) {
    medien[nr]->ausleihen(p, d, d + p.getAusleihdauer() );
}

void Bibliothek::print() const {
	cout << endl << "##### Bibliothek #####" << endl << endl;

    for (int i = 0; i < anz; ++i) {
        medien[i]->print();
    }
}
