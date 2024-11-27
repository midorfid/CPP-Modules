#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(convertToRaw(value)) {
    std::cout << "INT constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(convertToRaw(value)) {
    std::cout << "FLOAT constructor called" << std::endl;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

int Fixed::getRawBits() const{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

int Fixed::convertToRaw(const float input) {
    return (roundf(input * (float)(1 << fract_bits)));
}

int Fixed::convertToRaw(const int input) {
    return (input << fract_bits);
}

float Fixed::toFloat(void) const{
    return ((float)this->value / (float)(1 << fract_bits));
}

int Fixed::toInt(void) const{
    return (value / (1 << fract_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &cl) {
    return (os << cl.toFloat());
}