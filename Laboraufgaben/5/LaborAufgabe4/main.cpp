#include <iostream>

class DrawingObject;

int main()
{
	DrawingObject* objects[20];
	int anzahl = 0;
	std::cout << "Wieviele Objekte wollen Sie einlesen?" << std::endl;
	std::cout << "Anzahl: ";
	std::cin >> anzahl;
	// Objekte einlesen
	....
		for (int i = 0; i < anzahl; i++)
		{
			// einzelnes Objekt einlesen
			....
				objects[i] = ....
		}
	// Objekte ausgeben
	for (int i = 0; i < anzahl; i++)
	{
		// einzelnes Objekt ausgeben
		....
	}
	return 0;
}
