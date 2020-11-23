#include <cassert>
#include <iostream>

#include "../../../OOS1Lib/Fifo.cpp"

int main() {
	Fifo f(5);

	// assert initial state is correct
	assert(f.getRPos() == 0);
	assert(f.getWPos() == 0);
	assert(f.isEmpty());
	assert(!f.isFull());

	// assert push will happen at correct write position
	for (char i = 0; i < 5; ++i) {
		assert(f.getWPos() == i % 5);
		f.push(i);
	}

	// assert full push is -1
	assert(f.push(0) == -1);

	// assert full conditions
	assert(!f.isEmpty());
	assert(f.isFull());

	// assert correct read pos while pop
	for (int j = 0; j < 5; ++j) {
		assert(f.getRPos() == j % 5);
		assert(f.pop() == j);
	}

	// assert empty conditions
	assert(!f.isFull());
	assert(f.isEmpty());

	// push chars
	f.push('a'); f.push('b'); f.push('c'); f.push('d'); f.push('e');
	// assert first out
	assert(f.pop() == 'a');
	// assert first place new push
	assert(f.push('f') == 0);
	assert(f.isFull());

	std::cout << "Test ran to completion!" << std::endl;
}