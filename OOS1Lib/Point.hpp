#pragma once

#include <ostream>


#include "MyData.hpp"
#include "OneDimObject.hpp"

class Point : public OneDimObject, public MyData {
    double x, y;

public:
    Point(double x = 0, double y = 0);
    Point(std::string& str);
    Point(const Point& p);
    ~Point();


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
    friend std::ostream&       operator<<(std::ostream& stream, const Point& p);
    MyData*                    clone() const override;
    MyData&                    operator=(const MyData&) override;
};
