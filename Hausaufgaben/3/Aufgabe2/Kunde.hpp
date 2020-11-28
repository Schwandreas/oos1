//
// Created by simon on 13.05.2017.
//

#ifndef LABOR_3_KUNDE_HPP
#define LABOR_3_KUNDE_HPP


class Kunde {
    char *name;
    char *ort;
    int *alter;
    double umsatz = 0;
    int transaktion = 0;
    int id;

    static int anzahl;
public:
    Kunde(char *name = (char *) "None", char *ort = (char *) "None", int alter = 0)
            : name(name), ort(ort), alter(&alter)
    { this->id = Kunde::anzahl++; }

    Kunde(const Kunde &obj);

    ~Kunde();

public:
    void kaufe(double u);

    void print();

    static int getAnzahl() { return Kunde::anzahl; }
};


#endif //LABOR_3_KUNDE_HPP
