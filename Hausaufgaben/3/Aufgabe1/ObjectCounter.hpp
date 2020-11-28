#ifndef LABOR_3_OBJECTCOUNTER
#define LABOR_3_OBJECTCOUNTER


class ObjectCounter {
    int id;
    static int maxId;
    static int number;
public:
    ObjectCounter() {
        this->id = ObjectCounter::maxId++;
        ObjectCounter::number++;
    }

    ~ObjectCounter() {
        ObjectCounter::maxId--;
        ObjectCounter::number--;
    }

    int getId() { return id; }

    static int getMaxId() { return maxId; }

    static int getNumber() { return number; }
};


#endif
