#ifndef LABOR_3_KUNDE
#define LABOR_3_KUNDE


class Kunde
{
	const char* name;
	const char* ort;
	int*        alter;
	double      umsatz      = 0;
	int         transaktion = 0;
	int         id;

	static int anzahl;
public:
	Kunde(const char* name = "None", const char* ort = "None", int alter = 0)
		: name(name), ort(ort), alter(&alter)
	{
		this->id = Kunde::anzahl++;
	}

	Kunde(const Kunde& obj);

	~Kunde();

public:
	void kaufe(double u);

	void print();

	static int getAnzahl() { return Kunde::anzahl; }
};


#endif
