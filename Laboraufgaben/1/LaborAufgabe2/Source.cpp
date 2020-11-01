
#include <iostream>
#include "../../../OOS1Lib/ArrayReader.h"

int main(int argc, char* argv[])
{
	int arrSize;

	std::cout << "Please enter the array size: ";
	std::cin >> arrSize;

	const auto arr = std::make_unique<int[]>(arrSize);

	std::string arrStr = "[";
	auto        sum = 0;
	for (auto i = 0; i < arrSize; ++i)
	{
		std::cout << "\nPlease enter an integer value: ";
		std::cin >> arr[i];

		auto const spacerOrEnd = i + 1 != arrSize
			? ','
			: ']';
		arrStr += std::to_string(arr[i]) + spacerOrEnd + " ";
		sum += arr[i];
	}

	std::cout << "\nYour input was the following array: " << arrStr;
	std::cout << "\nAverage: " << sum / static_cast<double>(arrSize);
}
