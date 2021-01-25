// Student.hpp
#pragma once

#include "Person.hpp"

// Klasse Student als Spezialisierung von Person
class Student : public Person{
	// Matrikelnummer des Studenten/der Studentin
	int matNr;
public:
	// Standardkonstruktor
	Student(string name, int matNr) : Person(name, 30), matNr(matNr){}
	// Student auf der Konsole ausgeben
	void print() const;
};

void Student::print() const {
	Person::print();
	std::cout << " matNr: " << matNr << std::endl;
}
