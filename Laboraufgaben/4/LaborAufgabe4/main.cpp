#include <iostream>

#include "../../../Hausaufgaben/3/Aufgabe1/ObjectCounter.cpp"


#include "../../../OOS1Lib/Circle.cpp"
#include "../../../OOS1Lib/Point.cpp"
#include "../../../OOS1Lib/Polygonline.cpp"
using namespace std;


// Hauptprogramm
int main(void)
{
	debugConstructor = true;
	cout << "Anzahl der Objekte: " << DrawingObject::getNumber();
	cout << endl;
	Point p1;
	cout << "p1 ObjectId: " << p1.getId() << " " << p1 << endl;
	Point p2(1, 1);
	cout << "p2 ObjectId: " << p2.getId() << " " << p2 << endl;
	Circle c1(p1, 3);
	cout << "c1 ObjectId: " << c1.getId() << " " << c1 << endl;
	Polygonline l1(p1);
	cout << "l1 ObjectId: " << l1.getId() << " " << l1 << endl;
	cout << "Anzahl der Objekte: " << c1.getNumber() << endl;
}
