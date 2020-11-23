#include "Labyrinth.h"

#include <conio.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#include "../Hausaufgaben/2/Aufgabe1/Position.hpp"

Labyrinth::~Labyrinth()
{
	for (char* row : labyrinth)
	{
		delete[] row;
	}
}

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
		row[colCount + 1] = EOS;
		labyrinth.push_back(row);
	}
}

void Labyrinth::drucken()
{
	system("cls");
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


void Labyrinth::exportDatei(const char* fileName)
{
	ofstream datei(fileName);
	if (!datei)
	{
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < rowCount; i++)
	{
		datei << labyrinth[i];
	}
	datei.close();
}

void Labyrinth::importDatei(const char* fileName) {
	ifstream datei(fileName);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	std::string line;
	vector<string> lines;
	unsigned int shortestIndex = 0;

	while (std::getline(datei, line))
	{
		lines.push_back(line);
		if(line.length() <= lines[shortestIndex].length())
		{
			shortestIndex = lines.size() - 1;
		}
	}
	datei.close();

	rowCount = lines.size();
	colCount = lines[shortestIndex].length();
	for (string curLine : lines)
	{
		if (curLine[curLine.length() - 1] != EOS)
		{
			curLine += NL;
			curLine += EOS;
		}
		char* cstr = new char[curLine.length() + 1];
		strcpy_s(cstr, curLine.length() + 1, curLine.c_str());
		labyrinth.push_back(cstr);
	}
}

void Labyrinth::legeMuenzen()
{
	coinCount = replaceAllSymbole(WEG, MUENZE);
}

Symbole Labyrinth::getZeichenAnPos(const Position& tmp)
{
	return static_cast<Symbole>(labyrinth[tmp.posy][tmp.posx]);
}


void Labyrinth::zeichneChar(char c, Position pos)
{
	labyrinth[pos.posy][pos.posx] = c;
}

void Labyrinth::zeichneChar(char c, Position posalt, Position posneu)
{
	zeichneChar(WEG, posalt);
	zeichneChar(c, posneu);
}

bool Labyrinth::istMuenzeAnPos(Position pos)
{
	return getZeichenAnPos(pos) == MUENZE;
}

int Labyrinth::replaceAllSymbole(Symbole toReplace, Symbole value)
{
	int replaceCount = 0;
	for (auto row : labyrinth)
	{
		for (int i = 0; i < colCount; ++i)
		{
			if(row[i] == toReplace)
			{
				row[i] = value;
				replaceCount++;
			}
		}
	}
	return replaceCount;
}

