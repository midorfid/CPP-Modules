#include "Span.hpp"
#include <iostream>
#include <exception>

int main(void) {
    unsigned int u = 10;
    
    Span<int> s(u);

    try {
        for (int i = 0; i < 5; ++i) {
            int rng_int = rand() % 100 + 1;
            s.addNumber(rng_int);
            std::cout << s[i] << ' ';
        }

        s.addNumber(100);
        s.addNumber(17);

        std::cout << s.shortestSpan(); 
    } catch(std::exception &e) {
        std::cout << "caught!" << std::endl;
    }
}
