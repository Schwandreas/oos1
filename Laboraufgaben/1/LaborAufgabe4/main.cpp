#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

// Aufzählungstyp für Stein etc.
enum WAHL { STEIN = 1, SCHERE = 2, PAPIER = 3 };

// Struktur für einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player {
	const char* name;
	WAHL choice;
};

// Variable für den Namen des Spielers 
char name[15];

// Name des Spielers eingeben
char* enterName(char str[])
{
	cout << "Bitte gebe deinen Namen ein: \n" << endl;
	cin >> name;
	return name;
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
WAHL randomChoice()
{
	srand(time(NULL));
	int i;
	i = rand() % 3;

	switch (i)
	{
	case 1:return STEIN; break;
	case 2:return SCHERE; break;
	case 3:return PAPIER; break;
	default: "Fehler";
		break;
	}

}

// Die Wahl von STEIN etc. als String zurückgeben lassen
const char* object2str(WAHL o)
{
	
	switch (o) {
	case STEIN: return ("Stein");
	case SCHERE: return ("Schere");
	case PAPIER: return ("Papier");
	default: cout << "Fehler";
	}

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{
	cout << "\n" << p.name << " hat das Objekt " << object2str(p.choice) << " gewaehlt." << endl;


}

// Die Wahl des Spielers abfragen
WAHL enterChoice()
{
	int eingabe;
	cout << "\nBitte Objektwahl eingeben: [1=Stein, 2=Schere, 3=Papier]" << endl;
	cin >> eingabe;

	switch (eingabe) {
	case 1: return STEIN;  break;
	case 2: return SCHERE; break;
	case 3: return PAPIER; break;
	default: cout << "Fehler" << endl; break;
	}


}

// Die Wahl bestimmen, die gewonnen hat
WAHL winningObject(WAHL obj1, WAHL obj2)
{

	if (obj1 == STEIN && obj2 == SCHERE || obj1 == SCHERE && obj2 == PAPIER || obj1 == PAPIER && obj2 == STEIN) {
		cout << "\nDer Computer hat gewonnen!" << endl;
		return obj1;

	}
	else if (obj2 == STEIN && obj1 == SCHERE || obj2 == SCHERE && obj1 == PAPIER || obj2 == PAPIER && obj1 == STEIN) {
		cout << "\nDu hast gewonnen!" << endl;
		return obj2;
	}

	else {

		cout << "\nKeiner hat gewonnen" << endl;

	}




}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{

	winningObject(p1.choice, p2.choice);

}

int main()
{
	player player1, player2;
	player1.name = "Computer";
	player1.choice = randomChoice();
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	player2.name = enterName(name);
	player2.choice = enterChoice();
	showPlayer(player1);
	showPlayer(player2);
	showWinner(player1, player2);

	return 0;
}