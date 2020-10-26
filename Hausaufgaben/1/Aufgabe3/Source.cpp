#include <iostream>
#include <string>

int main(void)
{
	std::cout << "Aufgabe 3:";

	const auto arrSize = 5;
	int arr[arrSize] = {};
	auto* const end = arr + arrSize;
	std::string arrStr = "[";
	std::string arrPlus1Str = "[";
	std::string diffStr;
	auto sum = 0;

	for (auto* ptr = arr; ptr != end; ++ptr)
	{
		std::cout << "\nPlease enter an integer value: ";
		std::cin >> *ptr;

		auto spacerOrEnd = ']';
		if (ptr + 1 != end)
		{
			spacerOrEnd = static_cast<char>(spacerOrEnd - '1');
		}

		arrStr += std::to_string(*ptr) + spacerOrEnd + " ";
		arrPlus1Str += std::to_string(++(*ptr)) + spacerOrEnd + " ";
		sum += *ptr;

		if(ptr != arr)
		{
			diffStr += "\n" + std::to_string(*(ptr - 1)) + " - " + std::to_string(*ptr) + " = " + std::to_string(*(ptr - 1) - *ptr);
		}
	}
	
	std::cout << "\nSie haben folgendes Array eingegeben: " << arrStr;
	std::cout << "\nJedes Item plus 1: " << arrPlus1Str;
	std::cout << "\nDurchschnitt: " << sum / 5.;
	std::cout << "\nDifferenzen der Nachbarn:" << diffStr;
}
