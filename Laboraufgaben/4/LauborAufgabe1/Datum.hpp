// Datum.hpp
#pragma once

#include <string>
#include <ostream>
#include <sstream>

using namespace std;

// Klasse Datum, ähnlich zu der in der Übung der Vorlesung
class Datum {
	// Elemente eines Datums
	int tag, monat, jahr;
public:
	// Standardkonstruktor
	Datum(int j = 0, int m = 0, int t = 0) : jahr(j), monat(m), tag(t) {}
	// Konvertierkonstruktor für String
	Datum(const string &);
	// Konvertierkonstruktor für C-String
	Datum(const char * input) : Datum(string(input)) {}
	// Operator + addiert eine Anzahl von Tagen zum Datum hinzu
	Datum operator+(int tage);
	// Ausgabeoperator <<, Ausgabe in dem Format tt.mm.jjjj
	friend ostream &operator<<(ostream &os, const Datum &datum);
};

Datum::Datum(const string & s) {
	char c;
	istringstream stream(s);
	stream >> tag >> c >> monat >> c >> jahr;
}


Datum Datum::operator+(int tage) {
	Datum newDate(this->jahr, this->monat, this->tag);
	newDate.tag += tage;
	while(newDate.tag > 30)
	{
		newDate.tag %= 30;
		newDate.monat++;
	}
	while(newDate.monat > 12)
	{
		newDate.monat %= 12;
		newDate.jahr++;
	}
	return newDate;
}

ostream &operator<<(ostream &os, const Datum &datum) {
	os << datum.tag << "." << datum.monat << "." << datum.jahr;
	return os;
}
