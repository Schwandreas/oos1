#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;
	for (auto k = 1; k < 11; k++)
	{
		cout << showbase << setfill(' ') << setw(3) << dec << k;
		cout << setfill(' ') << setw(4) << oct << k;
		cout << setw(5) << hex << k << " ";
		cout << std::left << setfill('+') << setw(7) << string(k % 5 + 1, '*') << " ";
		cout << std::right << ((d < 0) ? "- " : "+ ") << setfill(' ') << setw(7) << std::noshowpos << setprecision(3) << fixed << std::abs(d);
		cout << std::noshowpos << setfill(' ') << setw(11) << scientific << d;
		d = d * -2;
		cout << endl;
	}
	return 0;
}
