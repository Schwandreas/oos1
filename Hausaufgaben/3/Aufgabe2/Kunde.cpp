#include <iostream>
#include <iomanip>
#include "Kunde.hpp"

int Kunde::anzahl = 0;

Kunde::Kunde(const Kunde& obj): name(obj.name), ort(obj.ort), alter(obj.alter)
{
}

Kunde::~Kunde()
{
	Kunde::anzahl--;

	delete[] name, ort;
	delete alter;
}

void Kunde::kaufe(double u)
{
	this->umsatz += u;
	this->transaktion++;
}

void Kunde::print()
{
	std::cout << "Kunde " << this->name << " aus " << this->ort
		<< " (ID = " << this->id << ", " << *this->alter << " Jahre)"
		<< " hatte " << this->transaktion << " Transaktion(en) und "
		<< std::setprecision(2) << std::fixed
		<< this->umsatz << " Euro Umsatz" << std::endl;
}
