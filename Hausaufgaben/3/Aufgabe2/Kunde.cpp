#include <cstring>
#include <iostream>
#include <iomanip>
#include "Kunde.hpp"

int Kunde::anzahl = 0;

Kunde::Kunde(const Kunde &obj) {
    int nameLen = strlen(obj.name);
    int ortLen = strlen(obj.ort);

    name = new char[nameLen + 1];
    ort = new char[ortLen + 1];
    alter = new int;

    strcpy(this->name, obj.name);
    strcpy(this->ort, obj.ort);
    *this->alter = *obj.alter;
}

Kunde::~Kunde() {
    Kunde::anzahl--;

    delete[] name, ort;
    delete alter;
}

void Kunde::kaufe(double u) {
    this->umsatz += u;
    this->transaktion++;
}

void Kunde::print() {
    std::cout << "Kunde " << this->name << " aus " << this->ort
              << " (ID = " << this->id << ", " << *this->alter << " Jahre)"
              << " hatte " << this->transaktion << " Transaktion(en) und "
              << std::setprecision(2) << std::fixed
              << this->umsatz << " Euro Umsatz" << std::endl;
}
