// Medium.hpp
#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include "Datum.hpp"
#include "Person.hpp"
using namespace std;

// Klasse f�r die Medien, die in der Bibliothek ausgeliehen werden 
// k�nnen
class Medium {
	// Titel des Mediums
	const string titel;
	// Verlag, der das Medium herausgibt
	const string verlag;
public:
    const string &getVerlag() const;

private:
    // Jahr, in dem das Medium ver�ffentlicht wurde
	const int jahr;
	// ausgeliehen von
	Person * ausleiher = nullptr;
	// ausgeliehen am 
	Datum von;
	// ausgeliehen bis
	Datum bis;
public:
	// Konstruktor
	Medium(string t = "", string v = "", int j = 0) : titel(t), verlag(v), jahr(j) {}
	// Titel zur�ckliefern
	string getTitel() const { return titel; }
	// Ausleiher zur�ckliefern
	Person * getAusleiher() const {return ausleiher;}

    // das Mediuem "ausleihen", d.h. Person p, von und bis eintragen
	void ausleihen(Person & p, Datum von, Datum bis);
	// Medium in der Konsole ausgeben
	virtual void print() const;

    const int getJahr() const { return jahr; }

	// The "Virtual Copy Constructor"
	virtual Medium* clone() = 0;
};


void Medium::ausleihen(Person &p, Datum von, Datum bis) {
    this->ausleiher = &p;
    this->von = von;
    this->bis = bis;
}


void Medium::print() const {
	cout << "------------------------" << endl;
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