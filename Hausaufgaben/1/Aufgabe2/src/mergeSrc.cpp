#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;
int basis, exponent;
int basis2, exponent2;

int main(void) {
	//programm 2
	// Need of new line
	// need of ^
	cout << endl << "Basis = ";
	cin >> basis;
	cout << endl << "Exponent = ";
	cin >> exponent;
	cout << endl << "Ergebnis: " << endl;
	cout << endl << basis << "^"  << exponent << " = " << pow(basis, exponent);

	// programm 1
	printf("\nBasis = ");
	scanf_s("%d", &basis2);
	printf("\nExponent = ");
	scanf_s("%d", &exponent2);
	printf("\nErgebnis: \n");
	printf("\n%d^%d = %d\n", basis2, exponent2,
		int(pow(double(basis2), double(exponent2))));

	return 0;
}