#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const Fixed&, const Fixed&);
        Point(const float, const float);
        Point(const int, const int);
        
        
        Point(const Point&);

        Fixed   &operator=(const Fixed&);

        ~Point();
};









#endif