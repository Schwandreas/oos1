#include <iostream>

#include "Kunde.hpp"

int main()
{
	std::cout << "Number: " << Kunde::getAnzahl() << std::endl;

	Kunde kundeDefault;
	kundeDefault.print();

	std::cout << "Number: " << Kunde::getAnzahl() << std::endl;

	Kunde kunde1("Mathis", "Ostfildern", 22);
	kunde1.print();

	std::cout << "Number: " << Kunde::getAnzahl() << std::endl;

	kunde1.kaufe(200);
	kunde1.print();
	kunde1.kaufe(150.23);
	kunde1.print();
}
