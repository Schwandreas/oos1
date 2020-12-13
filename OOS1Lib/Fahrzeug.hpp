#pragma once

#include <iomanip>

#include "MyString.cpp"

class Fahrzeug {
    MyString kz;
    int vin;
    double km = 0;

    static double summeKm;
    static int maxVehicleId;

public:
    Fahrzeug(const char * str) : kz(str){ vin = maxVehicleId++; };
    ~Fahrzeug(){summeKm-=km;}
    void fahren(double km);

    static double getSummeKm() {return summeKm;}

    friend std::ostream & operator<<(std::ostream & stream, const Fahrzeug & obj);
};
