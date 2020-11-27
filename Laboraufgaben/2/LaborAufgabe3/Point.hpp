#ifndef LABOR2_POINT
#define LABOR2_POINT

class Point
{
	double x, y;

public:
	Point(double x = 0, double y = 0) : x(x), y(y)
	{
	}

	double getX() const { return x; }
	void   setX(double x) { this->x = x; }

	double getY() const { return y; }
	void   setY(double y) { this->y = y; }

	void move(double dx, double dy);
	void print(bool addNl = true);
};


#endif
