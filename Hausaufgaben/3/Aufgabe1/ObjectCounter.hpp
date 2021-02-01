#ifndef LABOR_3_OBJECTCOUNTER
#define LABOR_3_OBJECTCOUNTER


class ObjectCounter
{
	static int maxId;
	static int number;
	int        id;
public:
	ObjectCounter()
	{
		this->id = ObjectCounter::maxId++;
		ObjectCounter::number++;
	}

	~ObjectCounter()
	{
		ObjectCounter::maxId--;
		ObjectCounter::number--;
	}

	virtual int getId() const
	{
		return id;
	}

	static int getMaxId() { return maxId; }

	static int getNumber() { return number; }
};


#endif
