// Datei PacMan.hpp
#pragma once

#include "Spieler.hpp"

class Labyrinth;
const int kAnzGeister = 3;

class PacMan {
	Labyrinth* lab;          // Labyrinth f�r das Spiel
	Spieler* s;              // Spieler, der das Spiel spielt
	Spieler* g[kAnzGeister]; // Geister, die den Spieler jagen
	int schritte;             // Anzahl der Spielschritte
	int muenzen;              // Anzahl der M�nzen im Labyrinth
public:
	// Konstruktor
	PacMan(Labyrinth& l, Spieler& sp, Spieler gArr[], int anzGeister);
	// Einen Schritt im Spiel ausf�hren
	void schritt();
	// Spiel spielen
	void spielen();
};
