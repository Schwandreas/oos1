#include <iostream>
#include <string>

#include "../../../OOS1Library/ArrayReader.h"
using namespace OOS1Library;

int main(void)
{
	std::cout << "Aufgabe 3:";
	const auto arrSize = 5;

	std::unique_ptr<ArrayReader<int>> arrayReader(new ArrayReader<int>(arrSize, "integer"));
	arrayReader->readAll();
	const std::unique_ptr<int[]> arr = std::move(arrayReader->arrayPtr);

	std::string arrStr      = "[";
	std::string arrPlus1Str = "[";
	auto        sum         = 0;
	std::string diffStr;
	for (auto i = 0; i < arrSize; ++i)
	{
		auto const spacerOrEnd = i + 1 != arrSize
		                         ? ','
		                         : ']';
		arrStr += std::to_string(arr[i]) + spacerOrEnd + " ";
		arrPlus1Str += std::to_string(++(arr[i])) + spacerOrEnd + " ";
		sum += arr[i];

		if (i > 0)
		{
			diffStr += "\n|" + std::to_string(arr[i - 1]) + " - " + std::to_string(arr[i]) + "| = " + std::to_string(
				abs(arr[i - 1] - arr[i]));
		}
	}

	std::cout << "\nSie haben folgendes Array eingegeben: " << arrStr;
	std::cout << "\nJedes Item plus 1: " << arrPlus1Str;
	std::cout << "\nDurchschnitt: " << sum / 5.;
	std::cout << "\nDifferenzen der Nachbarn:" << diffStr;
}
