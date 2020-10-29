/*

Spiel Tsching, Tschang, Tschong

Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt wählen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist 
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist 
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE 
ist maechtiger als PAPIER

*/

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Aufzählungstyp für Stein etc.
enum objectType { STEIN, SCHERE, PAPIER };

// Struktur für einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player
{
	unique_ptr<string>     name;
	unique_ptr<objectType> choice;
};


// Name des Spielers eingeben
unique_ptr<string> enterName()
{
	string name;
	cout << "Geben deinen Namen ein:";
	cin >> name;
	return make_unique<string>(name);
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
unique_ptr<objectType> randomChoice()
{
	srand(time(nullptr));
	int num = rand() % 3;
	return make_unique<objectType>(static_cast<objectType>(num));
}

// Die Wahl von STEIN etc. als String zurückgeben lassen
unique_ptr<string> object2str(objectType o)
{
	switch (o)
	{
	case STEIN:
		return make_unique<string>("Stein");
	case SCHERE:
		return make_unique<string>("Schere");
	default:
		return make_unique<string>("Papier");
	}
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(unique_ptr<player>& p)
{
}

// Die Wahl des Spielers abfragen
unique_ptr<objectType> enterChoice()
{
	cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier):";
	uint8_t choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		return make_unique<objectType>(STEIN);
	case 2:
		return make_unique<objectType>(SCHERE);
	default:
		return make_unique<objectType>(PAPIER);
	}
}

// Die Wahl bestimmen, die gewonnen hat
unique_ptr<objectType> winningObject(unique_ptr<objectType>& obj1, unique_ptr<objectType>& obj2)
{
	if (*obj1 == STEIN)
		return make_unique<objectType>(*obj2 == SCHERE ? STEIN : PAPIER);
	if (*obj1 == PAPIER)
		return make_unique<objectType>(*obj2 == STEIN ? PAPIER : SCHERE);
	if (*obj1 == SCHERE)
		return make_unique<objectType>(*obj2 == PAPIER ? SCHERE : STEIN);

	return make_unique<objectType>(*obj1);
}

// Ausgeben, wer gewonnen hat
void showWinner(unique_ptr<player>& p1, unique_ptr<player>& p2)
{

	cout << *p1->name << " hat das Objekt " << *object2str(*p1->choice) << " gewaehlt." << endl;
	cout << *p2->name << " hat das Objekt " << *object2str(*p2->choice) << " gewaehlt." << endl;
	if (*p1->choice == *p2->choice)
	{
		cout << "Unentschieden!";
		return;
	}
	unique_ptr<objectType> winObj = winningObject(p1->choice, p2->choice);
	player*                winner = (*(p1->choice) == *winObj) ? p1.get() : p2.get();
	cout << *winner->name << " hat gewonnen!";
}

int main()
{
	unique_ptr<player> player1 = make_unique<player>();
	unique_ptr<player> player2 = make_unique<player>();
	player1->name              = make_unique<string>("Computer");
	player1->choice            = move(randomChoice());
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	player2->name   = move(enterName());
	player2->choice = move(enterChoice());
	showPlayer(player1);
	showPlayer(player2);
	showWinner(player1, player2);
}
