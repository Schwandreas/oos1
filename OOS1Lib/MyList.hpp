#pragma once
#include "MyData.hpp"
#include <iostream>


class MyList {
    class MyListElement {
        MyListElement* next = nullptr;
        const MyData* data = nullptr;
    public:
        MyListElement() {};
        MyListElement(const MyListElement& element);
        MyListElement* getNext() const { return next; }
        const MyData* getData() const { return data; }

        void setNext(MyListElement* next) { this->next = next; }
        void setData(const MyData* data) { this->data = data; }
    };
private:
    int num = 0;
public:
    MyList() {};
    MyList(const MyList& list);

    MyListElement* first = nullptr, * last = nullptr;
    MyData& front() const { return (MyData&)*first->getData(); }
    MyData& back() const { return (MyData&)*last->getData(); }

    const bool empty() const { return num == 0; }
    const int size() const { return num; }

    void push_back(const MyData&);
    void pop_back();
    void clear();

    void print() const;

    MyList& operator=(const MyList&);
    MyList& operator+(const MyList&);
};
