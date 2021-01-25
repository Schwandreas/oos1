// Medium.hpp
#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include "Datum.hpp"
#include "Person.hpp"
using namespace std;

// Klasse für die Medien, die in der Bibliothek ausgeliehen werden 
// können
class Medium {
	// Titel des Mediums
	const string titel;
	// Verlag, der das Medium herausgibt
	const string verlag;
public:
    const string &getVerlag() const;

private:
    // Jahr, in dem das Medium veröffentlicht wurde
	const int jahr;
	// Typ des Mediums (z.B. Buch, DVD, ...)
	// wird von den abgeleiteten Klassen festgelegt
	const string typ;
	// ausgeliehen von
	Person * ausleiher = nullptr;
	// ausgeliehen am 
	Datum von;
	// ausgeliehen bis
	Datum bis;

public:
	// Konstruktor
	Medium(string t = "", string v = "", int j = 0, 
		   string typ = "undef") : titel(t), verlag(v), jahr(j), typ(typ){}
	// Titel zurückliefern
	string getTitel() const {return titel;}
	// Typ zurückliefern
	string getTyp() const {return typ;}
	// Ausleiher zurückliefern
	Person * getAusleiher() const {return ausleiher;}

    // das Mediuem "ausleihen", d.h. Person p, von und bis eintragen
	void ausleihen(Person & p, Datum von, Datum bis);
	// Medium in der Konsole ausgeben
	virtual void print() const;

    const int getJahr() const { return jahr; }
};


void Medium::ausleihen(Person &p, Datum von, Datum bis) {
    this->ausleiher = &p;
    this->von = von;
    this->bis = bis;
}


void Medium::print() const {
	cout << "------------------------" << endl;
	std::cout << this->typ << endl;
	std::cout << "Titel:      " << this->titel << endl;
	std::cout << "Verlag:     " << this->verlag << endl;
	std::cout << "Jahr:       " << this->jahr << endl;
	if(this->ausleiher == nullptr)
	{
		std::cout << "Ausleiher:  kein" << endl;
	} else
	{
		std::cout << "Ausleiher:  " << this->ausleiher->getName() << " von: " << this->von << " bis: " << this->bis << endl;
	}
}

const string &Medium::getVerlag() const {
    return verlag;
}
