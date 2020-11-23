#include "Circle.hpp"

#include <iomanip>
#include <iostream>
#include <ostream>

void Circle::move(double dx, double dy)
{
	centre.move(dx, dy);
}

void Circle::print(bool addNl)
{
	std::setprecision(1);

	std::cout << "<";
	centre.print(false);
	std::cout << ", " << radius << ">";
	if (addNl)
		std::cout << std::endl;
}
