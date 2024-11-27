#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(convertToRaw(value)) {
    // std::cout << "INT constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(convertToRaw(value)) {
    // std::cout << "FLOAT constructor called" << std::endl;
}
Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
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

    Fixed &Fixed::operator=(const Fixed &other) {
        // std::cout << "Copy assignment operator called" << std::endl;
        this->value = other.getRawBits();
        return(*this);
    }

    bool Fixed::operator<(const Fixed &other) const{
        return (this->value < other.value);
    }

    bool Fixed::operator>(const Fixed &other) const{
        return other < *this;
    }

    bool Fixed::operator==(const Fixed &other) const{
        return (!(*this > other) && !(*this < other));
    }

    bool Fixed::operator<=(const Fixed &other) const{
        return (!(*this > other));
    }

    bool Fixed::operator>=(const Fixed &other) const{
        return (!(*this < other));
    }

    bool Fixed::operator!=(const Fixed &other) const{
        return (!(*this == other));
    }

    Fixed Fixed::operator+(const Fixed &other) const{
        Fixed result;

        result.setRawBits(this->getRawBits() + other.getRawBits());
        return (result);
    }

    Fixed Fixed::operator-(const Fixed &other) const{
        Fixed result;

        result.setRawBits(this->getRawBits() - other.getRawBits());
        return (result);
    }

    Fixed Fixed::operator*(const Fixed &other) const{
        Fixed result;

        result.setRawBits((long)this->getRawBits() * (long)other.getRawBits() / (1 << fract_bits));
        return (result);
    }

    Fixed Fixed::operator/(const Fixed &other) const{
        Fixed result;

        result.setRawBits((long)this->getRawBits() * (1 << fract_bits) / (long)other.getRawBits());
        return (result);
    }

    Fixed Fixed::operator++(int) {
        Fixed old = *this;
        ++value;
        return (old);
    }

    Fixed &Fixed::operator++() {
        ++value;
        return(*this);
    }

    Fixed Fixed::operator--(int) {
        Fixed old = *this;
        --value;
        return (old);
    }

    Fixed &Fixed::operator--() {
        --value;
        return(*this);
    }

    Fixed &Fixed::max(Fixed &a, Fixed &b) {
        return (a < b ? b : a);
    }

    const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
        return (a < b ? b : a);
    }
    
    Fixed &Fixed::min(Fixed &a, Fixed &b) {
        return (a < b ? a : b);
    }

    const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
        return (a < b ? a : b);
    }