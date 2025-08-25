#include "base.hpp"
#include <iostream>

int main(void) {
    for (int i = 0; i < 10; ++i) {
        std::cout << i << " ";
        Base *b = generate();
        identify(*b);
        identify(b);
    }
}