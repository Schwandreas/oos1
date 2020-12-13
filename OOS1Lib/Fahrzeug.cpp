#include "Fahrzeug.hpp"

int Fahrzeug::maxVehicleId = 0;
double Fahrzeug::summeKm = 0;

void Fahrzeug::fahren(double km) {
    this->km += km;
    summeKm+=km;
}

std::ostream &operator<<(std::ostream &stream, const Fahrzeug &obj) {
    return stream << std::setprecision(1) << std::fixed << "Kz = " << obj.kz << "  VIN = " << obj.vin << "  km = " << obj.km;
}