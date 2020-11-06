#pragma once
#include <vector>

struct Position;
using namespace std;

enum Symbole
{
	MAUER = '#',
	WEG = ' ',
	MUENZE = ':',
	NL = '\n',
	EOS = '\0',
	ICH = 'X',
	GEIST = 'G'
};

class Labyrinth
{
public:
	int rowCount;
	int colCount;
	int ghostCount;
	int coinCount;

	std::vector<char*> labyrinth;
	Labyrinth() = default;

	Labyrinth(const int rows, const int cols, const int ghosts): rowCount(rows), colCount(cols), ghostCount(ghosts),
	                                                             coinCount(0)
	{
		initialisieren();
	}

	int     getZeilen() const;
	int     getSpalten() const;
	int     getAnzGeister() const;
	void    initialisieren();
	void    drucken();
	void    erzeugen();
	void    exportDatei(const char* fileName);
	void    importDatei(const char* fileName);
	void    legeMuenzen();
	void    zeichneChar(char c, Position pos);
	void    zeichneChar(char c, Position posalt, Position posneu);
	Symbole getZeichenAnPos(const Position& tmp);
	bool    istMuenzeAnPos(Position pos);
private:
	int replaceAllSymbole(Symbole toReplace, Symbole value);
};
