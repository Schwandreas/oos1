// DVD.hpp
#pragma once

#include "Medium.hpp"

// Klasse f�r die DVDs als Spezialisierung von Medium
class DVD : public Medium{
	// Abspieldauer der DVD
	const int dauer;
public:
	const int getDauer() const { return dauer; }

public:
	// Standardkonstruktor
	DVD(string t = "", string v = "", int j = 0, int d = 0) : Medium(t, v, j), dauer(d) {}
	// die DVD auf der Konsole ausgeben
	void print() const;
	Medium* clone() override
	{
		return new DVD(*this);
	}
};

void DVD::print() const {
	Medium::print();
	std::cout << "Dauer:      " << this->dauer << std::endl;
}
