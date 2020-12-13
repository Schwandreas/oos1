#include <cassert>
#include <iostream>

#include "../../../OOS1Lib/Fahrzeug.cpp"
using namespace std;
int main() {

	// setup sut
	Fahrzeug f1("ES - H 123");
	cout << f1 << endl;
	f1.fahren(100);
	cout << f1 << endl;
	Fahrzeug f2("ES - M 4711");
	f2.fahren(50);
	cout << f2 << endl;
	// assert
	cout << "assert getSummeKm is 150 with epsilon = 1" << endl;
	assert(abs(Fahrzeug::getSummeKm() - 150) < 1);
	cout << "Summe KM was in expected epsilon" << endl;

	cout << "assert getSummeKm is 100 with epsilon = 1, after destructing f2" << endl;
	// setup sut
	// This may trigger some break point idk how to workaround the _CrtIsValidHeapPointer but should be fine.
	f2.~Fahrzeug();
	// assert
	assert(abs(Fahrzeug::getSummeKm() - 100) < 1);
	cout << "Summe KM was in expected epsilon, after destructing f2" << endl;
	return 0;
}
