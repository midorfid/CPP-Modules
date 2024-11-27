#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:

    int                 value;
    static const int    fract_bits = 8;

public:

    Fixed();
    ~Fixed();

    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->value = other.getRawBits();
        return(*this);
    }

    int getRawBits(void) const;

    void setRawBits(int const raw);
};

#endif