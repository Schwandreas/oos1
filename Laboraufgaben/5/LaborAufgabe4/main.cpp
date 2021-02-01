#include <iostream>
#include <string>


#include "../../../Hausaufgaben/3/Aufgabe1/ObjectCounter.cpp"

#include "../../../OOS1Lib/Point.cpp"
#include "../../../OOS1Lib/Circle.cpp"
#include "../../../OOS1Lib/Polygonline.cpp"
#include "../../../OOS1Lib/Rectangle.cpp"
class DrawingObject;
using namespace std;


int main() {
    debugConstructor = false;
    DrawingObject* objects[20];
    string inString;
    int anzahl = 0;
    cout << "Wieviele Objekte wollen Sie einlesen?" << endl;
    cout << "Anzahl: ";
    cin >> anzahl;
    getline(cin, inString);
    if (anzahl > 20 || anzahl < 0)
    {
        cout << "Bitte Zahl zwischen 1-20 eingeben!";
        return 0;
    }

    for (int i = 0; i < anzahl; ++i) {
        cout << "Object[" << i + 1 << "]: ";
        getline(cin, inString);
        DrawingObject* object;

        if (inString.find('[') != std::string::npos)
            object = new Rectangle(inString);
        else if (inString.find('|') != std::string::npos)
            object = new Polygonline(inString);
        else if (inString.find('<') != std::string::npos)
            object = new Circle(inString);
        else if (inString.find('(') != std::string::npos)
            object = new Point(inString);
        else
        {
            std::cout << "Invalid input format!";
            return 0;
        }
        objects[i] = object;
    }

    for (int j = 0; j < anzahl; ++j) {
        objects[j]->print(true);
    }
}
