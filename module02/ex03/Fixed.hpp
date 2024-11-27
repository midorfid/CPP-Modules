#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

    int                 value;
    static const int    fract_bits = 8;

public:

    Fixed();
    ~Fixed();

    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed& other);

    Fixed   &operator=(const Fixed &);

    Fixed   &operator++();
    Fixed   operator++(int);
    Fixed   &operator--();
    Fixed   operator--(int);

    bool    operator<(const Fixed &) const;
    bool    operator>(const Fixed &) const;
    bool    operator<=(const Fixed &) const;
    bool    operator>=(const Fixed &) const;
    bool    operator==(const Fixed &) const;
    bool    operator!=(const Fixed &) const;

    Fixed    operator+(const Fixed &) const;
    Fixed    operator-(const Fixed &) const;
    Fixed    operator*(const Fixed &) const;
    Fixed    operator/(const Fixed &) const;

    static Fixed            &max(Fixed &, Fixed &);
    static const Fixed      &max(const Fixed &, const Fixed &);
    static Fixed            &min(Fixed &, Fixed &);
    static const Fixed      &min(const Fixed &, const Fixed &);

    int     getRawBits(void) const;

    void    setRawBits(const int raw);

    int     convertToRaw(float const input);

    int     convertToRaw(int const input);

    float   toFloat(void) const;

    int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &cl);

#endif
