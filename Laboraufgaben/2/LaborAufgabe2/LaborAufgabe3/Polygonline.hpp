#ifndef LABOR2_POLYGONLINE
#define LABOR2_POLYGONLINE

#include "PlgElement.hpp"

class Polygonline
{
	PlgElement *start, *end;

public:
	Polygonline(Point p1);

	Polygonline()
	{
		start = nullptr;
		end   = nullptr;
	};

	PlgElement* getStart();
	PlgElement* getEnd();

	Polygonline& addPoint(Point point);
	void         appendPolygonline(Polygonline polygonline);

	void print(bool addNl = true);
	void move(double dx, double dy);
};


#endif //LABOR2_POLYGONLINE_HPP
