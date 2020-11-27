#ifndef LABOR2_CIRCLE
#define LABOR2_CIRCLE

#include "Point.hpp"

class Circle
{
	Point  centre;
	double radius;

public:
	Circle(double x = 0, double y = 0, double radius = 0) : Circle(Point(x, y), radius)
	{
	}

	Circle(Point centre, double radius = 0) : centre(centre), radius(radius)
	{
	}

	const Point& getCentre() const { return centre; }
	void         setCentre(const Point& centre) { Circle::centre = centre; }

	double getRadius() const { return radius; }
	void   setRadius(double radius) { Circle::radius = radius; }

	void move(double dx, double dy);
	void print(bool addNl = true);
};


#endif
