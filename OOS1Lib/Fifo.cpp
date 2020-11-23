#include "Fifo.hpp"

Fifo::Fifo(int size): maxSize(size)
{
	ptr = new char[maxSize];
}

Fifo::~Fifo()
{
	delete[] ptr;
}

int Fifo::getWPos() const
{
	return wPos;
}

int Fifo::getRPos() const
{
	return rPos;
}

bool Fifo::isEmpty() const
{
	return number == 0;
}

bool Fifo::isFull() const
{
	return number == maxSize;
}

int Fifo::push(char c)
{
	if (isFull())
		return -1;

	int pos  = wPos++;
	ptr[pos] = c;
	number++;

	if (wPos >= maxSize)
		wPos = 0;

	return pos;
}

char Fifo::pop()
{
	if (number-- <= 0)
		return (char)((number = 0) - 1); //Set number=0 and return -1

	int pos = rPos++;
	if (rPos >= maxSize)
		rPos = 0;

	return ptr[pos];
}
