#ifndef OOS1LIB_FIFO
#define OOS1LIB_FIFO

#include <algorithm>

class Fifo {
    int maxSize = 0, number = 0;
    int wPos = 0, rPos = 0;
    char* ptr;

public:
    Fifo(int size = 20);

    ~Fifo();

    int getWPos() const;
    int getRPos() const;


    bool isEmpty() const;
    bool isFull() const;

    int push(char c);
    char pop();
};

#endif 
