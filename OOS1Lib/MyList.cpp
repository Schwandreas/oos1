#pragma once

#include "MyList.hpp"

void MyList::push_back(const MyData& data) {
    num++;
    MyListElement* lastElementNew = new MyListElement();
    lastElementNew->setData(data.clone());

    if (this->last == nullptr) {
        first = last = lastElementNew;
    }
    else {
        last->setNext(lastElementNew);
        last = lastElementNew;
    }
}

void MyList::pop_back() {
    num--;
    MyListElement* current = first;
    while (current->getNext() != last) {
        current = current->getNext();
    }
    delete last;
    current->setNext(nullptr);
    last = current;
}

void MyList::clear() {
    this->num = 0;
    MyListElement* current = first;
    while (current != nullptr) {
        MyListElement* next = current->getNext();
        delete current;
        current = next;
    }
    this->first = nullptr;
    this->last = nullptr;
}

void MyList::print() const {
    std::cout << "List Size: " << size() << std::endl;

    MyListElement* current = first;
    while (current != nullptr) {
        current->getData()->print(false);
        current = current->getNext();
    }

    std::cout << std::endl;
}

MyList& MyList::operator=(const MyList& list) {
    MyList* newList = new MyList(list);
    return *newList;

}

MyList& MyList::operator+(const MyList& data) {
    if (data.empty())
        return *this;

    last->setNext(new MyListElement(*data.first));
    MyListElement* next = last->getNext();

    while (next != nullptr) {
        last->setNext(new MyListElement(*next));
        last = last->getNext();
        next = last->getNext();
    }

    return *this;
}

MyList::MyList(const MyList& list) {
    MyListElement* element = list.first;
    if (element == nullptr)
        return;

    MyListElement* elementCopy = new MyListElement(*element);
    this->first = elementCopy;

    MyListElement* nextObject = element->getNext(), * nextObjectCopy;

    while (nextObject != nullptr) {
        nextObjectCopy = new MyListElement(*nextObject);
        elementCopy->setNext(nextObjectCopy);
        elementCopy = nextObjectCopy;
        nextObject = elementCopy->getNext();
    }

    this->last = elementCopy;
    this->num = list.num;
}

MyList::MyListElement::MyListElement(const MyList::MyListElement& element) {
    this->data = element.getData()->clone();
    this->next = element.getNext();
}