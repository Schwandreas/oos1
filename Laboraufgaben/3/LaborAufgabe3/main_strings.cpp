#include <iostream>


#include "../../../OOS1Lib/Circle.cpp"
#include "../../../OOS1Lib/Point.cpp"
#include "../../../OOS1Lib/Polygonline.cpp"


using namespace std;

// Hauptprogramm
int main(void)
{
	string      str1("(1.1,2.1)");
	string      str2("<(5.5, 6.6), 10.1>");
	string      str3("|(1.1,1.2) - (2.1, 2.2) -(3.1,3.2) |");
	Point       p(str1);
	Circle      c(str2);
	Polygonline l(str3);

	cout << p.toString() << endl;
	cout << c.toString() << endl;
	c.move(1.0, 2.0);
	cout << c.toString() << endl;
	cout << l.toString() << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	std::cout << "Geben sie ein Objekt ein: ";
	string userInput;
	getline(cin, userInput);

	if (userInput.find('|') != std::string::npos)
	{
		Polygonline polygonline(userInput);
		polygonline.print(true);
	}
	else if (userInput.find('<') != std::string::npos)
	{
		Circle circle(userInput);
		circle.print(true);
	}
	else if (userInput.find('(') != std::string::npos)
	{
		Point point(userInput);
		point.print(true);
	}
	else
	{
		std::cout << "Invalidinput format!";
	}

	return 0;
}
