// Buch.hpp
#pragma once

#include "Medium.hpp"

// Klasse für die Bücher als Spezialisierung von Medium
class Buch : public Medium{
	// Autor(en) des Buches
	string autor;
public:
	// Standardkonstruktor
	Buch(string t = "", string a = "", string v = "", int jahr = 0) : Medium(t, v, jahr, "Buch"), autor(a) {}
    const string getAutor() const {return autor;}

    // das Buch auf der Konsole ausgeben
	void print() const;
};

void Buch::print() const {
	Medium::print();
	std::cout << "Autor:      " << this->autor << std::endl;
}
