#include "Labyrinth.h"

#include <conio.h>
#include <iostream>
#include <ostream>

int Labyrinth::getSpalten() const
{
	return colCount;
}

int Labyrinth::getZeilen() const
{
	return rowCount;
}

int Labyrinth::getAnzGeister() const
{
	return ghostCount;
}


void Labyrinth::initialisieren()
{
	for (auto i = 0; i < rowCount; ++i)
	{
		char* row = new char[colCount + 2];
		for (auto j = 0; j < colCount; ++j)
		{
			row[j] = MAUER;
		}
		row[colCount] = NL;
		row[colCount] = EOS;
		labyrinth.push_back(row);
	}
}

void Labyrinth::drucken()
{
	for (char* row : labyrinth)
	{
		cout << row;
	}
}

void Labyrinth::erzeugen()
{
	char c                = 'x';
	int  posx             = colCount / 2;
	int  posy             = rowCount / 2;
	labyrinth[posy][posx] = ICH;
	drucken();
	while (c != 'q')
	{
		drucken();
		cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
		labyrinth[posy][posx] = WEG;
		c                     = _getch();
		switch (int(c))
		{
			// oben
		case 72: posy = max(1, posy - 1);
			break;
			// links
		case 75: posx = max(1, posx - 1);
			break;
			// rechts
		case 77: posx = min(colCount - 2, posx + 1);
			break;
			// unten
		case 80: posy = min(rowCount - 2, posy + 1);
			break;
			// q = quit
		case 113: return;
		}
		labyrinth[posy][posx] = ICH;
	}
}


int Labyrinth::max(int x, int y)
{
	return (x <= y) ? y : x;
}

int Labyrinth::min(int x, int y)
{
	return (x <= y) ? x : y;
}
