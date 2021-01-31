
#include "Point.hpp"


#include <iomanip>
#include <iostream>
#include <sstream>

void Point::print(bool addNl) const {
    std::cout << toString();

    if (addNl)
        std::cout << std::endl;
}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

std::string Point::toString() const {
    std::ostringstream stream;
    stream << std::setprecision(1) << std::fixed << "(" << x << ", " << y << ")";
    return stream.str();
}

double stringToDouble(const std::string st) {
    std::istringstream is;
    is.str(st);
    double n;
    is >> n;
    return n;
}

std::istringstream& operator>>(std::istringstream& stream, Point& p) {
    unsigned int pos = (unsigned int)stream.tellg();
    std::string str = stream.str();
    str = str.substr(pos);

    unsigned int indexParOpen = str.find("(");
    unsigned int indexParClose = str.find(")");
    unsigned int indexComma = str.find(",");

    unsigned int length = indexParClose + 1;

    if (indexParOpen == std::string::npos || indexParClose == std::string::npos || indexComma == std::string::npos)
        throw std::invalid_argument("invalid input string");

    unsigned int firstNumStartIndex = indexParOpen + 1;
    unsigned int secondNumStartIndex = indexComma + 1;

    unsigned int firstNumLength = indexComma - firstNumStartIndex;
    unsigned int secondNumLength = indexParClose - secondNumStartIndex;

    std::string xString = str.substr(firstNumStartIndex, firstNumLength);
    std::string yString = str.substr(secondNumStartIndex, secondNumLength);

    p.setX(stringToDouble(xString));
    p.setY(stringToDouble(yString));

    stream.seekg(length, std::ios_base::cur);
    return stream;
}

Point::Point(std::string& str) {
    char c;
    std::stringstream stream(str);
    stream >> c >> x >> c >> y;
}

std::ostream& operator<<(std::ostream& stream, const Point& p) {
    return stream << p.toString();
}

Point Point::operator-() {
    Point returnPoint(-this->x, -this->y);
    return returnPoint;
}

Point Point::operator++() {
    x++;
    y++;
    return *this;
}

Point Point::operator++(int) {
    Point p = *this;
    x++;
    y++;
    return p;
}

Point operator+(const Point& a, const Point& b) {
    Point returnPoint(a.getX(), a.getY());
    returnPoint.move(b.getX(), b.getY());
    return returnPoint;
}

Point operator+(double a, const Point& b) {
    Point returnPoint(b.getX(), b.getY());
    returnPoint.move(a, a);
    return returnPoint;
}

Point operator+(const Point& a, double b) {
    Point returnPoint(a.getX(), a.getY());
    returnPoint.move(b, b);
    return returnPoint;
}

Point operator-(const Point& a, const Point& b) {
    Point returnPoint(a.getX(), a.getY());
    returnPoint.move(-b.getX(), -b.getY());
    return returnPoint;
}
Point::~Point() {
    if (debugConstructor)
        std::cout << "Destruktor der Klasse <Point>, Object: <" << getId() << ">" << std::endl;
}

MyData* Point::clone() const {
    Point* p = new Point(*this);
    return p;
}

Point::Point(const Point& p) : x(p.x), y(p.y) {
    if (debugConstructor)
        std::cout << "Copy Konstruktor der Klasse <Point>, Object: <" << getId() << ">" << std::endl;
}

Point::Point(double x, double y) : x(x), y(y) {
    if (debugConstructor)
        std::cout << "Konstruktor der Klasse <Point>, Object: <" << getId() << ">" << std::endl;
}

MyData& Point::operator=(const MyData& data) {
    return MyData::operator=(data);
}