// Dozent.hpp
#pragma once

#include "Person.hpp"

// Klasse Dozent als Spezialisierung von Person
class Dozent : public Person {
	// Prüfernummer des Dozenten
	int prfrNr;
public:
	// Standardkosntruktor
	Dozent(string name, int prfrNr) : Person(name, 30), prfrNr(prfrNr){}
	// Dozenten auf der Konsole ausgeben
	void print() const;
};

void Dozent::print() const {
	Person::print();
	std::cout << " prfrNr: " << prfrNr << std::endl;
}
