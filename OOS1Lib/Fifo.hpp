#ifndef OOS1LIB_FIFO
#define OOS1LIB_FIFO

#include <algorithm>

class Fifo {
    int maxSize = 0, number = 0;
    int wPos = 0, rPos = 0;
    char* ptr;

public:
    Fifo(int size = 20) : maxSize(size) { ptr = new char[maxSize]; }

    ~Fifo() { delete[] ptr; }

    int getWPos() { return wPos; }
    int getRPos() { return rPos; }


    bool isEmpty() { return number == 0; }
    bool isFull() { return number == maxSize; }

    int push(char c);
    char pop();
};

#endif 
