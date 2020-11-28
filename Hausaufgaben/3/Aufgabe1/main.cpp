#include <iostream>

#include "ObjectCounter.hpp"

int main()
{
	std::cout << "getMaxId: " << ObjectCounter::getMaxId() << ", Number: " << ObjectCounter::getNumber() << std::endl;

	ObjectCounter counter1;
	std::cout << "Counter1 ID: " << counter1.getId() << std::endl;
	std::cout << "getMaxId: " << ObjectCounter::getMaxId() << ", Number: " << ObjectCounter::getNumber() << std::endl;

	ObjectCounter counter2;
	std::cout << "Counter2 ID: " << counter2.getId() << std::endl;
	std::cout << "getMaxId: " << ObjectCounter::getMaxId() << ", Number: " << ObjectCounter::getNumber() << std::endl;

	delete&counter1;
	std::cout << "Counter1 deleted" << std::endl;
	std::cout << "getMaxId: " << ObjectCounter::getMaxId() << ", Number: " << ObjectCounter::getNumber() << std::endl;

	delete&counter2;
	std::cout << "Counter2 deleted" << std::endl;
	std::cout << "getMaxId: " << ObjectCounter::getMaxId() << ", Number: " << ObjectCounter::getNumber() << std::endl;
}
