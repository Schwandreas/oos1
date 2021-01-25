// Person.hpp
#pragma once

#include <string>
#include <ostream>

using namespace std;

// Klasse für alle Personen, die Medien ausleihen können
class Person {
	// Name der Person
	string name;
	// Dauer in Tagen, die die Person ein Medium ausleihen darf
	// wird von den abgelieteten Klassen festgelegt
	int ausleihdauer;
public:
	// Standardkonstruktor
	Person(string name, int dauer = 0) : name(name), ausleihdauer(dauer) {}
	// den Namen zurückliefern
	string getName() const {return name;}
	// die Ausliehdauer zurückliefern
	int getAusleihdauer() const {return ausleihdauer;}
	// die Person auf der Konsole ausgeben
	virtual void print() const;
};

void Person::print() const {
	std::cout << "name: " << this->name << " ausleihdauer: " << this->ausleihdauer;
}

