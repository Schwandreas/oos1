#pragma once

#include <ostream>

class Point {
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point(std::string& str);

    double getX() const { return x; }
    void setX(double x) { this->x = x; }

    double getY() const { return y; }
    void setY(double y) { this->y = y; }

    void move(double dx, double dy);
    void print(bool addNl = true) const;
    std::string toString() const;

    Point operator-();
    Point operator++();
    Point operator++(int);

    friend Point operator-(const Point& a, const Point& b);
    friend Point operator+(const Point& a, const Point& b);
    friend Point operator+(const Point& a, double b);
    friend Point operator+(double a, const Point& b);

    friend std::istringstream& operator>>(std::istringstream& str, Point& p);
    friend std::ostream& operator<<(std::ostream& stream, const Point& p);
};
