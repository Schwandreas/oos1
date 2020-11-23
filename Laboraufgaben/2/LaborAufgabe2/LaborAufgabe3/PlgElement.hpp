#ifndef LABOR2_PLGELEMENT
#define LABOR2_PLGELEMENT

#include "Point.hpp"

class PlgElement
{
	Point       point;
	PlgElement* next = nullptr;

public:
	~PlgElement();

	PlgElement(const Point& point);

	PlgElement* getNext() const;

	void setNext(PlgElement* next);

	const Point& getPoint() const;

	void setPoint(const Point& point);

	void print(bool addNl = true);

	void move(double dx, double dy);
};


#endif
