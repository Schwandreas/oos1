
#include <iostream>
#include "../../../OOS1Lib/ArrayReader.h"

int main(int argc, char* argv[])
{
	int arrSize;

	std::cout << "Please enter the array size: ";
	std::cin >> arrSize;
	std::unique_ptr<OOS1Library::ArrayReader<int>> arrayReader(new OOS1Library::ArrayReader<int>(arrSize, "integer"));
	arrayReader->readAll();
	const std::unique_ptr<int[]> arr = std::move(arrayReader->arrayPtr);

	std::string arrStr = "[";
	auto        sum = 0;
	std::string diffStr;
	for (auto i = 0; i < arrSize; ++i)
	{
		auto const spacerOrEnd = i + 1 != arrSize
			? ','
			: ']';
		arrStr += std::to_string(arr[i]) + spacerOrEnd + " ";
		sum += arr[i];
	}
	std::cout << "\nYour input was the following array: " << arrStr;
	std::cout << "\nAverage: " << sum / static_cast<double>(arrSize);

}
