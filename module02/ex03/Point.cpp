#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const int x, const int y) : x(x), y(y) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point &copy) {
    *this = copy;
}

Point &Point::operator=(const Point &other) {
    const_cast<Fixed&>(x) = other.x;
    const_cast<Fixed&>(y) = other.y;
    return *this;
}

Point Point::operator-(const Point &other) const{
    Point result(this->getX() - other.getX(), this->getY() - other.getY());

    return (result);
}

Point::~Point() {}

Fixed Point::getX() const{
    return (x);
}

Fixed Point::getY() const{
    return (y);
}