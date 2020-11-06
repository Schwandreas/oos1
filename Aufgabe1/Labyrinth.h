#pragma once
#include <vector>

using namespace std;

enum Symbole {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};

class Labyrinth
{
public:
	const int rowCount;
	const int colCount;
	const int ghostCount;
	const int coinCount;

	std::vector<char*> labyrinth;
	Labyrinth(const int rows, const int cols, const int ghosts): rowCount(rows), colCount(cols), ghostCount(ghosts), coinCount(0)
	{
	}
	int getZeilen() const;
	int getSpalten() const;
	int getAnzGeister() const;


	void initialisieren();
	void drucken();
	void erzeugen();

private:
	static int max(int x, int y);
	static int min(int x, int y);
};
