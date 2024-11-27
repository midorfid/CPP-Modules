#include "Fixed.hpp"

int main (void)
{
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << b-a << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << (a < b ? "true" : "false") << std::endl;
    std::cout << (a == b ? "true" : "false") << std::endl;
    std::cout << (Fixed::max(Fixed(5), Fixed(4)++)) << std::endl;

    return 0;
}
